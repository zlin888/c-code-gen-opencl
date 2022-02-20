#define VECTOR_SIZE 4096

__kernel void cl_kernel(__global double* var0, __global double* var4)
{
int var5;
double* var31;
double* var6;
double var52;
int* var11;
int var53;
double var7;
double var32;
var5 = get_global_id(0);
var31 = &(var4[var5]);
var6 = &(var52);
*(var6) = 0.0;
var11 = &(var53);
var7 = *(var6);
for (int var8 = 0; var8 < 3; var8++)
{
int var44;
double var41;
*(var11) = (var8 + var5);
var44 = *(var11);
var41 = var0[var44];
*(var6) = (var41 + var7);
var7 = *(var6);
}
*(var6) = var7;
var32 = *(var6);
*(var31) = (var32 * 0.33333);
}
