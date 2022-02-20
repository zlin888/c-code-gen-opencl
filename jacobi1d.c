#include <stdio.h>
#include <stdlib.h>
#include "include/helper.h"

#ifdef __APPLE__
#include <OpenCL/cl.h>
#else
#include <CL/cl.h>
#endif
#define VECTOR_SIZE 4096

//OpenCL kernel which is run for every work item created.

void launch_kernel(char *filename) {
  int i;
  // Allocate space for vectors A, B and C
  srand(42);
  float *A = (float*)malloc(sizeof(float)*VECTOR_SIZE);
  float *C = (float*)malloc(sizeof(float)*VECTOR_SIZE);
  for(i = 0; i < VECTOR_SIZE; i++)
  {
    A[i] = rand() / (float)RAND_MAX;
    C[i] = 0;
  }

  cl_int clStatus;
  cl_info clInfo = init_cl_info(filename);

  // Create memory buffers on the device for each vector
  cl_mem A_clmem = clCreateBuffer(clInfo.context, CL_MEM_READ_ONLY,VECTOR_SIZE * sizeof(float), NULL, &clStatus);
  cl_mem C_clmem = clCreateBuffer(clInfo.context, CL_MEM_WRITE_ONLY,VECTOR_SIZE * sizeof(float), NULL, &clStatus);

  // Copy the Buffer A and B to the device
  clStatus = clEnqueueWriteBuffer(clInfo.command_queue, A_clmem, CL_TRUE, 0, VECTOR_SIZE * sizeof(float), A, 0, NULL, NULL);

fill_program_and_kernel(&clInfo);
  // Set the arguments of the kernel
  clStatus = clSetKernelArg(clInfo.kernel, 0, sizeof(cl_mem), (void *)&A_clmem);
  clStatus = clSetKernelArg(clInfo.kernel, 1, sizeof(cl_mem), (void *)&C_clmem);

  // Execute the OpenCL kernel on the list
  size_t global_size = VECTOR_SIZE; // Process the entire lists
  size_t local_size = 16;           // Process one item at a time
  clStatus = clEnqueueNDRangeKernel(clInfo.command_queue, clInfo.kernel, 1, NULL, &global_size, &local_size, 0, NULL, &clInfo.event);

  // Read the cl memory C_clmem on device to the host variable C
  clStatus = clEnqueueReadBuffer(clInfo.command_queue, C_clmem, CL_TRUE, 0, VECTOR_SIZE * sizeof(float), C, 0, NULL, NULL);

  // Clean up and wait for all the comands to complete.
  clStatus = clFlush(clInfo.command_queue);
  clStatus = clFinish(clInfo.command_queue);

  print_runtime(clInfo.event);

  for (int i = 0; i < 10; i++) {
      printf("%f, ", A[i]);
  }
  printf("\n");

  for (int i = 0; i < 10; i++) {
      printf("%f, ", C[i]);
  }
  printf("\n");

  clStatus = clReleaseMemObject(A_clmem);
  clStatus = clReleaseMemObject(C_clmem);
  clean_cl_info(clInfo);
  free(A);
  free(C);
}

int main(void) {
  launch_kernel("jacobi1d_gen.cl");
  launch_kernel("jacobi1d.cl");
  return 0;
}
