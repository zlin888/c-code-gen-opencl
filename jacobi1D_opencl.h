__kernel void cl_kernel(__global float *var0, __global float *var16) {
  float *var18;
  float var29;
  float var13;
  float var10;
  int var17;
  float *var23;
  var17 = get_global_id(0);
  var18 = &(var29);
  *(var18) = 0.00000;
  var13 = *(var18);
  for (int var14 = 0; var14 < 3; var14++) {
    int *var19;
    int var30;
    int var15;
    float var26;
    var19 = &(var30);
    *(var19) = (var14 + var17);
    var15 = *(var19);
    if (var15 >= 4096) printf("%d\n", var15);
    var26 = *((float *)((char *)(var0) + (var15 * (1 * 4))));
    *(var18) = (var26 + var13);
    var13 = *(var18);
  }
  *(var18) = var13;
  var10 = *(var18);
  var23 = ((char *)(var16) + (var17 * (1 * 4)));
  *(var23) = (var10 * 0.33333);
}
