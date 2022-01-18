#include <stdio.h>
#include <stdlib.h>
#include <CL/cl.h>

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

cl_device_id* get_device_list(cl_playform_id *platforms) {
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
  return device_list;
}

















