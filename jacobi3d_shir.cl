#define NX 128 
#define NY 128 
#define NZ 128 

__kernel void cl_kernel(__global float* var0, __global float* var22)
{
int* var255;
int var444;
int* var251;
int var445;
int var24;
int var426;
int* var253;
int var446;
int var23;
int var428;
float** var425;
float* var423;
int* var240;
int var447;
int* var236;
int var448;
int var405;
int* var238;
int var449;
int var407;
float** var404;
float* var402;
int* var225;
int var450;
int* var221;
int var451;
int var384;
int* var223;
int var452;
int var386;
float** var383;
float* var381;
int* var210;
int var453;
int* var206;
int var454;
int var363;
int* var208;
int var455;
int var365;
float** var362;
float* var360;
int* var195;
int var456;
int* var191;
int var457;
int var342;
int* var193;
int var458;
int var344;
float** var341;
float* var339;
int* var180;
int var459;
int* var176;
int var460;
int var321;
int* var178;
int var461;
int var323;
float** var320;
float* var318;
int* var165;
int var462;
int* var161;
int var463;
int var300;
int* var163;
int var464;
int var302;
float** var299;
float* var297;
float** var293;
float* var291;
float* var26;
float var465;
float* var27;
float var466;
float* var28;
float var467;
float* var29;
float var468;
float* var30;
float var469;
float* var31;
float var470;
var23 = get_global_id(0);
var24 = get_global_id(1);
if(var23 < 126 && var24 < 126) {
var255 = &(var444);
var251 = &(var445);
*(var251) = (0 + var24);
var426 = *(var251);
var253 = &(var446);
*(var253) = (1 + var23);
var428 = *(var253);
var425 = ((char*) (var0) + (var428 * (16384 * 4)));
var423 = ((char*) (var425) + (var426 * (128 * 4)));
var240 = &(var447);
var236 = &(var448);
*(var236) = (1 + var24);
var405 = *(var236);
var238 = &(var449);
*(var238) = (1 + var23);
var407 = *(var238);
var404 = ((char*) (var0) + (var407 * (16384 * 4)));
var402 = ((char*) (var404) + (var405 * (128 * 4)));
var225 = &(var450);
var221 = &(var451);
*(var221) = (1 + var24);
var384 = *(var221);
var223 = &(var452);
*(var223) = (0 + var23);
var386 = *(var223);
var383 = ((char*) (var0) + (var386 * (16384 * 4)));
var381 = ((char*) (var383) + (var384 * (128 * 4)));
var210 = &(var453);
var206 = &(var454);
*(var206) = (1 + var24);
var363 = *(var206);
var208 = &(var455);
*(var208) = (1 + var23);
var365 = *(var208);
var362 = ((char*) (var0) + (var365 * (16384 * 4)));
var360 = ((char*) (var362) + (var363 * (128 * 4)));
var195 = &(var456);
var191 = &(var457);
*(var191) = (1 + var24);
var342 = *(var191);
var193 = &(var458);
*(var193) = (2 + var23);
var344 = *(var193);
var341 = ((char*) (var0) + (var344 * (16384 * 4)));
var339 = ((char*) (var341) + (var342 * (128 * 4)));
var180 = &(var459);
var176 = &(var460);
*(var176) = (1 + var24);
var321 = *(var176);
var178 = &(var461);
*(var178) = (1 + var23);
var323 = *(var178);
var320 = ((char*) (var0) + (var323 * (16384 * 4)));
var318 = ((char*) (var320) + (var321 * (128 * 4)));
var165 = &(var462);
var161 = &(var463);
*(var161) = (2 + var24);
var300 = *(var161);
var163 = &(var464);
*(var163) = (1 + var23);
var302 = *(var163);
var299 = ((char*) (var0) + (var302 * (16384 * 4)));
var297 = ((char*) (var299) + (var300 * (128 * 4)));
var293 = ((char*) (var22) + (var23 * (15876 * 4)));
var291 = ((char*) (var293) + (var24 * (126 * 4)));
var26 = &(var465);
var27 = &(var466);
var28 = &(var467);
var29 = &(var468);
var30 = &(var469);
var31 = &(var470);
for (int var25 = 0; var25 < 126; var25++)
{
int var424;
float var9;
int var403;
float var10;
int var382;
float var11;
int var361;
float var12;
int var340;
float var13;
int var319;
float var14;
int var298;
float var15;
float* var258;
float var284;
float var279;
float var274;
float var269;
float var264;
float var259;
*(var255) = (1 + var25);
var424 = *(var255);
var9 = *(((char*) (var423) + (var424 * (1 * 4))));
*(var240) = (0 + var25);
var403 = *(var240);
var10 = *(((char*) (var402) + (var403 * (1 * 4))));
*(var225) = (1 + var25);
var382 = *(var225);
var11 = *(((char*) (var381) + (var382 * (1 * 4))));
*(var210) = (1 + var25);
var361 = *(var210);
var12 = *(((char*) (var360) + (var361 * (1 * 4))));
*(var195) = (1 + var25);
var340 = *(var195);
var13 = *(((char*) (var339) + (var340 * (1 * 4))));
*(var180) = (2 + var25);
var319 = *(var180);
var14 = *(((char*) (var318) + (var319 * (1 * 4))));
*(var165) = (1 + var25);
var298 = *(var165);
var15 = *(((char*) (var297) + (var298 * (1 * 4))));
var258 = ((char*) (var291) + (var25 * (1 * 4)));
*(var31) = (var9 + var10);
var284 = *(var31);
*(var30) = (var284 + var11);
var279 = *(var30);
*(var29) = (var279 + var12);
var274 = *(var29);
*(var28) = (var274 + var13);
var269 = *(var28);
*(var27) = (var269 + var14);
var264 = *(var27);
*(var26) = (var264 + var15);
var259 = *(var26);
*(var258) = (var259 / 7.0);
}
}
}
