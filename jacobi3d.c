#include <stdio.h>
#include <stdlib.h>
#include "include/helper.h"

#ifdef __APPLE__
#include <OpenCL/cl.h>
#else
#include <CL/cl.h>
#endif
#define GS 128
#define LS 8
#define DIM 3

//OpenCL kernel which is run for every work item created.
//
void launch_kernel(char *filename) {
  float *A = (float*)malloc(sizeof(float)*GS * GS*GS);
  float *C = (float*)malloc(sizeof(float)*GS * GS*GS);
  for(int i = 0; i < GS * GS * GS; i++)
  {
    A[i] = rand() / (float)RAND_MAX;
    C[i] = 0;
  }


  // Execute the OpenCL kernel on the list
  size_t global_size[] = {GS, GS, GS}; // Process the entire lists
  size_t local_size[] = {LS, LS, LS};           // Process one item at a time

  cl_int clStatus;
  cl_info clInfo = init_cl_info(filename);

  // Create memory buffers on the device for each vector
  cl_mem A_clmem = clCreateBuffer(clInfo.context, CL_MEM_READ_WRITE,GS * GS * GS * sizeof(float), NULL, &clStatus);
  cl_mem C_clmem = clCreateBuffer(clInfo.context, CL_MEM_READ_WRITE,GS * GS * GS * sizeof(float), NULL, &clStatus);

  // Copy the Buffer A and B to the device
  clStatus = clEnqueueWriteBuffer(clInfo.command_queue, A_clmem, CL_TRUE, 0, GS * GS * GS * sizeof(float), A, 0, NULL, NULL);

fill_program_and_kernel(&clInfo);
  // Set the arguments of the kernel
  clStatus = clSetKernelArg(clInfo.kernel, 0, sizeof(cl_mem), (void *)&A_clmem);
  clStatus = clSetKernelArg(clInfo.kernel, 1, sizeof(cl_mem), (void *)&C_clmem);

  clStatus = clEnqueueNDRangeKernel(clInfo.command_queue, clInfo.kernel, DIM, NULL, global_size, local_size, 0, NULL, &clInfo.event);
  printf("kernel in\n");

  // Read the cl memory C_clmem on device to the host variable C
  clStatus = clEnqueueReadBuffer(clInfo.command_queue, C_clmem, CL_TRUE, 0, GS * GS * GS * sizeof(float), C, 0, NULL, NULL);
  printf("read buffer\n");

  // Clean up and wait for all the comands to complete.
  clStatus = clFlush(clInfo.command_queue);
  clStatus = clFinish(clInfo.command_queue);

  for(int i = 0; i < 5; i++) {
      printf("%.2f, ", A[5 * GS * GS + 5 * GS + i]); 
  }
  printf("\n");
  for(int i = 0; i < 5; i++) {
      printf("%.2f, ", C[5 * GS * GS + 5 * GS + i]); 
  }
  printf("\n");

  print_runtime(clInfo.event);

  clStatus = clReleaseMemObject(A_clmem);
  clStatus = clReleaseMemObject(C_clmem);
  clean_cl_info(clInfo);
  free(A);
  free(C);
}


int main(void) {
  // Allocate space for vectors A, B and C
  srand(42);
  launch_kernel("jacobi3d.cl");
  return 0;
}

