#include <stdio.h>
#include <stdlib.h>
#include <CL/cl.h>

struct CL_info {
  char *source;
  cl_device_id *device_list;
  cl_int clStatus;
  cl_context context;
  cl_command_queue command_queue;
  cl_program program;
  cl_kernel kernel;
  cl_event event;
};

typedef struct CL_info cl_info;

char* from_source(char* filename) {
    /* declare a file pointer */
    FILE    *infile;
    long    numbytes;
    char* buffer;
     
    /* open an existing file for reading */
    infile = fopen(filename, "r");
     
    /* quit if the file does not exist */
    if(infile == NULL)
        printf("ERROR");
     
    /* Get the number of bytes */
    fseek(infile, 0L, SEEK_END);
    numbytes = ftell(infile);
     
    /* reset the file position indicator to 
    the beginning of the file */
    fseek(infile, 0L, SEEK_SET);	
     
    /* grab sufficient memory for the 
    buffer to hold the text */
    buffer = (char*)calloc(numbytes, sizeof(char));	
     
    /* memory error */
    if(buffer == NULL)
        printf("ERROR");
     
    /* copy all the text into the buffer */
    fread(buffer, sizeof(char), numbytes, infile);

    fclose(infile);
    return buffer;
}

cl_device_id* get_device_list() {
  // Get platform and device information
  cl_platform_id * platforms = NULL;
  cl_uint     num_platforms;
  //Set up the Platform
  cl_int clStatus = clGetPlatformIDs(0, NULL, &num_platforms);
  platforms = (cl_platform_id *)malloc(sizeof(cl_platform_id)*num_platforms);
  clStatus = clGetPlatformIDs(num_platforms, platforms, NULL);

  //Get the devices list and choose the device you want to run on
  cl_device_id     *device_list = NULL;
  cl_uint           num_devices;

  clStatus = clGetDeviceIDs( platforms[0], CL_DEVICE_TYPE_GPU, 0,NULL, &num_devices);
  device_list = (cl_device_id *)malloc(sizeof(cl_device_id)*num_devices);
  clStatus = clGetDeviceIDs( platforms[0],CL_DEVICE_TYPE_GPU, num_devices, device_list, NULL);
  free(platforms);
  return device_list;
}

cl_uint get_device_num() {
  // Get platform and device information
  cl_platform_id * platforms = NULL;
  cl_uint     num_platforms;
  //Set up the Platform
  cl_int clStatus = clGetPlatformIDs(0, NULL, &num_platforms);
  platforms = (cl_platform_id *)malloc(sizeof(cl_platform_id)*num_platforms);
  clStatus = clGetPlatformIDs(num_platforms, platforms, NULL);

  //Get the devices list and choose the device you want to run on
  cl_device_id     *device_list = NULL;
  cl_uint           num_devices;

  clStatus = clGetDeviceIDs( platforms[0], CL_DEVICE_TYPE_GPU, 0,NULL, &num_devices);
  free(platforms);
  return num_devices;
}

void get_context_and_command_queue(cl_context *context, cl_command_queue *command_queue) {
  cl_int clStatus;
  cl_device_id *device_list = get_device_list();
  cl_uint device_num = get_device_num();

  *context = clCreateContext( NULL, device_num, device_list, NULL, CL_QUEUE_PROFILING_ENABLE, &clStatus);

  *command_queue = clCreateCommandQueue(*context, device_list[0], CL_QUEUE_PROFILING_ENABLE, &clStatus);
  free(device_list);
}

cl_info init_cl_info(char *filename) {
  cl_info clInfo;
  clInfo.device_list = get_device_list();
  get_context_and_command_queue(&clInfo.context, &clInfo.command_queue);
  clInfo.source = from_source(filename);
  return clInfo;
}

void clean_cl_info(cl_info clInfo) {
  cl_int clStatus;
  clStatus = clReleaseKernel(clInfo.kernel);
  clStatus = clReleaseProgram(clInfo.program);
  clStatus = clReleaseCommandQueue(clInfo.command_queue);
  clStatus = clReleaseContext(clInfo.context);
  free(clInfo.device_list);
  free(clInfo.source);
}

void print_runtime(cl_event event) {
    clWaitForEvents(1, &event);
    cl_ulong time_start;
    cl_ulong time_end;

    clGetEventProfilingInfo(event, CL_PROFILING_COMMAND_START, sizeof(time_start), &time_start, NULL);
    clGetEventProfilingInfo(event, CL_PROFILING_COMMAND_END, sizeof(time_end), &time_end, NULL);

    double nanoSeconds = time_end-time_start;
    printf("%lu,%lu\n", time_end, time_start);
    printf("OpenCl Execution time is: %0.3f milliseconds \n", nanoSeconds / 1000000.0);
}

void fill_program_and_kernel(cl_info *clInfo) {
  cl_int clStatus;                  
  // Create a program from the kernel source
  clInfo->program = clCreateProgramWithSource(clInfo->context, 1,(const char **)&clInfo->source, NULL, &clStatus);

  // Build the program
  clStatus = clBuildProgram(clInfo->program, 1, clInfo->device_list, NULL, NULL, NULL);

  // Create the OpenCL kernel
  clInfo->kernel = clCreateKernel(clInfo->program, "cl_kernel", &clStatus);

}















