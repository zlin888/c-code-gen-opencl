__kernel void cl_kernel(__global float *var0, __global float *var40) {
  int var41;
  int var42;
  float *var165[27];
  float *var56;
  var41 = get_global_id(0);
  var42 = get_global_id(1);
  var56 = &(var165);
  for (int var60 = 0; var60 < 3; var60++) {
    for (int var59 = 0; var59 < 3; var59++) {
      int *var63;
      int var166;
      int var39;
      int *var61;
      int var167;
      int var38;
      float *var158;
      float *var159;
      float var162;
      float *var156;
      float *var157;
      float *var164;
      var63 = &(var166);
      *(var63) = (var60 + var41);
      var39 = *(var63);
      var61 = &(var167);
      *(var61) = (var59 + var42);
      var38 = *(var61);
      var158 = (var0 + (var39 * 16384));
      var159 = (var158 + (var38 * 128));
      var162 = *((var159 + 0));
      var156 = (var56 + (1 * 9));
      var157 = (var156 + (var60 * 3));
      var164 = (var157 + var59);
      *(var164) = var162;
    }
  }
  for (int var69 = 0; var69 < 3; var69++) {
    for (int var68 = 0; var68 < 3; var68++) {
      int *var72;
      int var168;
      int var39;
      int *var70;
      int var169;
      int var38;
      float *var149;
      float *var150;
      float var153;
      float *var147;
      float *var148;
      float *var155;
      var72 = &(var168);
      *(var72) = (var69 + var41);
      var39 = *(var72);
      var70 = &(var169);
      *(var70) = (var68 + var42);
      var38 = *(var70);
      var149 = (var0 + (var39 * 16384));
      var150 = (var149 + (var38 * 128));
      var153 = *((var150 + 1));
      var147 = (var56 + (2 * 9));
      var148 = (var147 + (var69 * 3));
      var155 = (var148 + var68);
      *(var155) = var153;
    }
  }
  for (int var37 = 0; var37 < 126; var37++) {
    float *var9;
    float *var118;
    float *var119;
    float var11;
    float *var116;
    float *var117;
    float var12;
    float *var114;
    float *var115;
    float var13;
    float *var112;
    float *var113;
    float var14;
    float *var110;
    float *var111;
    float var15;
    float *var108;
    float *var109;
    float var16;
    float *var106;
    float *var107;
    float var17;
    float *var53;
    float var173;
    float var24;
    float *var51;
    float var174;
    float var25;
    float *var49;
    float var175;
    float var26;
    float *var47;
    float var176;
    float var27;
    float *var45;
    float var177;
    float var28;
    float *var43;
    float var178;
    float var29;
    float *var96;
    float *var97;
    float *var99;
    for (int var78 = 0; var78 < 3; var78++) {
      for (int var77 = 0; var77 < 3; var77++) {
        float *var141;
        float *var142;
        float *var143;
        float var144;
        float *var139;
        float *var140;
        float *var146;
        var141 = var56;
        var142 = (var141 + (1 * 9));
        var143 = (var142 + (var78 * 3));
        var144 = *((var143 + var77));
        var139 = (var56 + (0 * 9));
        var140 = (var139 + (var78 * 3));
        var146 = (var140 + var77);
        *(var146) = var144;
      }
    }
    for (int var83 = 0; var83 < 3; var83++) {
      for (int var82 = 0; var82 < 3; var82++) {
        float *var133;
        float *var134;
        float *var135;
        float var136;
        float *var131;
        float *var132;
        float *var138;
        var133 = var56;
        var134 = (var133 + (2 * 9));
        var135 = (var134 + (var83 * 3));
        var136 = *((var135 + var82));
        var131 = (var56 + (1 * 9));
        var132 = (var131 + (var83 * 3));
        var138 = (var132 + var82);
        *(var138) = var136;
      }
    }
    for (int var88 = 0; var88 < 3; var88++) {
      for (int var87 = 0; var87 < 3; var87++) {
        int *var91;
        int var170;
        int var39;
        int *var89;
        int var171;
        int var38;
        float *var123;
        float *var124;
        int *var93;
        int var172;
        int var125;
        float var128;
        float *var120;
        float *var121;
        float *var130;
        var91 = &(var170);
        *(var91) = (var88 + var41);
        var39 = *(var91);
        var89 = &(var171);
        *(var89) = (var87 + var42);
        var38 = *(var89);
        var123 = (var0 + (var39 * 16384));
        var124 = (var123 + (var38 * 128));
        var93 = &(var172);
        *(var93) = (var37 + 2);
        var125 = *(var93);
        var128 = *((var124 + var125));
        var120 = (var56 + (2 * 9));
        var121 = (var120 + (var88 * 3));
        var130 = (var121 + var87);
        *(var130) = var128;
      }
    }
    var9 = var56;
    var118 = (var9 + (1 * 9));
    var119 = (var118 + (1 * 3));
    var11 = *((var119 + 0));
    var116 = (var9 + (0 * 9));
    var117 = (var116 + (1 * 3));
    var12 = *((var117 + 1));
    var114 = (var9 + (1 * 9));
    var115 = (var114 + (0 * 3));
    var13 = *((var115 + 1));
    var112 = (var9 + (1 * 9));
    var113 = (var112 + (1 * 3));
    var14 = *((var113 + 1));
    var110 = (var9 + (1 * 9));
    var111 = (var110 + (2 * 3));
    var15 = *((var111 + 1));
    var108 = (var9 + (2 * 9));
    var109 = (var108 + (1 * 3));
    var16 = *((var109 + 1));
    var106 = (var9 + (1 * 9));
    var107 = (var106 + (1 * 3));
    var17 = *((var107 + 2));
    var53 = &(var173);
    *(var53) = (var11 + var12);
    var24 = *(var53);
    var51 = &(var174);
    *(var51) = (var24 + var13);
    var25 = *(var51);
    var49 = &(var175);
    *(var49) = (var25 + var14);
    var26 = *(var49);
    var47 = &(var176);
    *(var47) = (var26 + var15);
    var27 = *(var47);
    var45 = &(var177);
    *(var45) = (var27 + var16);
    var28 = *(var45);
    var43 = &(var178);
    *(var43) = (var28 + var17);
    var29 = *(var43);
    var96 = (var40 + (var41 * 15876));
    var97 = (var96 + (var42 * 126));
    var99 = (var97 + var37);
    *(var99) = (var29 / 7.00000);
  }
}
