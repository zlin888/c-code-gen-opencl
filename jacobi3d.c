#include <stdio.h>
#include <stdlib.h>
#include "include/helper.h"

#ifdef __APPLE__
#include <OpenCL/cl.h>
#else
#include <CL/cl.h>
#endif
#define DIM 3

//OpenCL kernel which is run for every work item created.
//
void launch_kernel(char *filename, size_t gs, size_t ls, int dim) {
  float *A = (float*)malloc(sizeof(float)*gs * gs*gs);
  float *C = (float*)malloc(sizeof(float)*gs * gs*gs);
  for(int i = 0; i < gs * gs * gs; i++)
  {
    A[i] = rand() / (float)RAND_MAX;
    C[i] = 0;
  }

  size_t *global_size = malloc(dim * sizeof(size_t));
  size_t *local_size = malloc(dim * sizeof(size_t));
  for(int i = 0; i < dim; i++){
      global_size[i] = gs;
      local_size[i] = ls;
  }

  cl_int clStatus;
  cl_info clInfo = init_cl_info(filename);

  // Create memory buffers on the device for each vector
  cl_mem A_clmem = clCreateBuffer(clInfo.context, CL_MEM_READ_WRITE,gs * gs * gs * sizeof(float), NULL, &clStatus);
  cl_mem C_clmem = clCreateBuffer(clInfo.context, CL_MEM_READ_WRITE,gs * gs * gs * sizeof(float), NULL, &clStatus);

  // Copy the Buffer A and B to the device
  clStatus = clEnqueueWriteBuffer(clInfo.command_queue, A_clmem, CL_TRUE, 0, gs * gs * gs * sizeof(float), A, 0, NULL, NULL);

fill_program_and_kernel(&clInfo);
  // Set the arguments of the kernel
  clStatus = clSetKernelArg(clInfo.kernel, 0, sizeof(cl_mem), (void *)&A_clmem);
  clStatus = clSetKernelArg(clInfo.kernel, 1, sizeof(cl_mem), (void *)&C_clmem);

  clStatus = clEnqueueNDRangeKernel(clInfo.command_queue, clInfo.kernel, dim, NULL, global_size, local_size, 0, NULL, &clInfo.event);
  if (clStatus != CL_SUCCESS) {
      printf("NDRangeKernel Error: %d\n", clStatus);
  }

  // Read the cl memory C_clmem on device to the host variable C
  clStatus = clEnqueueReadBuffer(clInfo.command_queue, C_clmem, CL_TRUE, 0, gs * gs * gs * sizeof(float), C, 0, NULL, NULL);
  printf("read buffer\n");

  // Clean up and wait for all the comands to complete.
  clStatus = clFlush(clInfo.command_queue);
  clStatus = clFinish(clInfo.command_queue);

  for(int i = 0; i < 5; i++) {
      printf("%.2f, ", A[5 * gs * gs + 5 * gs + i]); 
  }
  printf("\n");
  for(int i = 0; i < 8 * 8 * 8; i++) {
      printf("%.2f, ", C[i]); 
  }
  printf("\n");
  for(int i = 0; i < 5; i++) {
      printf("%.2f, ", C[5 * gs * gs + 5 * gs + i]); 
  }
  printf("\n");

  print_runtime(clInfo.event);

  clStatus = clReleaseMemObject(A_clmem);
  clStatus = clReleaseMemObject(C_clmem);
  clean_cl_info(clInfo);
  free(A);
  free(C);
  free(global_size);
  free(local_size);
}


int main(void) {
  // Allocate space for vectors A, B and C
  srand(42);
  launch_kernel("jacobi3d.cl", 128, 4, 3);
  launch_kernel("jacobi3d_opt1_nu.cl", 128, 4, 3);
  //launch_kernel("jacobi3d_opt0.cl", 128, 4, 3);
  //launch_kernel("jacobi3d_opt1.cl", 128, 4, 3);
  //launch_kernel("jacobi3d_opt2.cl", 128, 4, 3);
  //launch_kernel("jacobi3d_opt3.cl", 128, 4, 3);
 // launch_kernel("jacobi3d_shir.cl", 128, 4, 2);
  return 0;
}

