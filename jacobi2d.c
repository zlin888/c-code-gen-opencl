#include <stdio.h>
#include <stdlib.h>
#include "include/helper.h"

#ifdef __APPLE__
#include <OpenCL/cl.h>
#else
#include <CL/cl.h>
#endif
#define VECTOR_SIZE 4096
#define LS 16

//OpenCL kernel which is run for every work item created.
//
void launch_kernel(char *filename) {
  float *A = (float*)malloc(sizeof(float)*VECTOR_SIZE * VECTOR_SIZE);
  float *C = (float*)malloc(sizeof(float)*VECTOR_SIZE * VECTOR_SIZE);
  for(int i = 0; i < VECTOR_SIZE; i++)
  {
      for(int j = 0; j < VECTOR_SIZE; j++) {
        A[i * VECTOR_SIZE + j] = rand() / (float)RAND_MAX;
        C[i * VECTOR_SIZE + j] = 0;
      }
  }

  cl_int clStatus;
  cl_info clInfo = init_cl_info(filename);

  // Create memory buffers on the device for each vector
  cl_mem A_clmem = clCreateBuffer(clInfo.context, CL_MEM_READ_WRITE,VECTOR_SIZE * VECTOR_SIZE * sizeof(float), NULL, &clStatus);
  cl_mem C_clmem = clCreateBuffer(clInfo.context, CL_MEM_READ_WRITE,VECTOR_SIZE * VECTOR_SIZE * sizeof(float), NULL, &clStatus);

  // Copy the Buffer A and B to the device
  clStatus = clEnqueueWriteBuffer(clInfo.command_queue, A_clmem, CL_TRUE, 0, VECTOR_SIZE * VECTOR_SIZE * sizeof(float), A, 0, NULL, NULL);

fill_program_and_kernel(&clInfo);
  // Set the arguments of the kernel
  clStatus = clSetKernelArg(clInfo.kernel, 0, sizeof(cl_mem), (void *)&A_clmem);
  clStatus = clSetKernelArg(clInfo.kernel, 1, sizeof(cl_mem), (void *)&C_clmem);

  // Execute the OpenCL kernel on the list
  size_t global_size[] = {VECTOR_SIZE, VECTOR_SIZE}; // Process the entire lists
  size_t local_size[] = {LS, LS};           // Process one item at a time

  clStatus = clEnqueueNDRangeKernel(clInfo.command_queue, clInfo.kernel, 2, NULL, global_size, local_size, 0, NULL, &clInfo.event);
  printf("kernel in\n");

  // Read the cl memory C_clmem on device to the host variable C
  clStatus = clEnqueueReadBuffer(clInfo.command_queue, C_clmem, CL_TRUE, 0, VECTOR_SIZE * VECTOR_SIZE * sizeof(float), C, 0, NULL, NULL);
  printf("read buffer\n");

  // Clean up and wait for all the comands to complete.
  clStatus = clFlush(clInfo.command_queue);
  clStatus = clFinish(clInfo.command_queue);

  for(int i = 0; i < 5; i++) {
      printf("%.2f, ", A[5 * VECTOR_SIZE + i]); 
  }
  printf("\n");
  for(int i = 0; i < 5; i++) {
      printf("%.2f, ", C[5 * VECTOR_SIZE + i]); 
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
  launch_kernel("jacobi2d.cl");
  launch_kernel("jacobi2d_opt0.cl");
  launch_kernel("jacobi2d_opt1.cl");
  return 0;
}

