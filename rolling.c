void main() {
}

void cl_kernel(float *var0, float *var39) {
  int var40;
  int var41;
  //printf("%d %d\n", var40, var41);
  float var55[27];
  //var55 = malloc(sizeof(float *) * 3);
  //for (int var164 = 0; var164 < 3; var164++) {
  //  var55[var164] = malloc(sizeof(float *) * 3);
  //  for (int var165 = 0; var165 < 3; var165++) {
  //    var55[var164][var165] = malloc(sizeof(float) * 3);
  //  }
  //}
  for (int var59 = 0; var59 < 3; var59++) {
    for (int var58 = 0; var58 < 3; var58++) {
      int *var62;
      int var166;
      int var38;
      int *var60;
      int var167;
      int var37;
      float *var157;
      float *var158;
      float var161;
      float *var155;
      float *var156;
      float *var163;
      var62 = &(var166);
      *(var62) = (var59 + var40);
      var38 = *(var62);
      var60 = &(var167);
      *(var60) = (var58 + var41);
      var37 = *(var60);
      var157 = (var0 + (var38 * 16384));
      var158 = (var157 + (var37 * 128));
      var161 = *((var158 + 0));
      var155 = (var55 + (1 * 9));
      var156 = (var155 + (var59 * 3));
      var163 = (var156 + var58);
      *(var163) = var161;
    }
  }
  for (int var68 = 0; var68 < 3; var68++) {
    for (int var67 = 0; var67 < 3; var67++) {
      int *var71;
      int var168;
      int var38;
      int *var69;
      int var169;
      int var37;
      float *var148;
      float *var149;
      float var152;
      float *var146;
      float *var147;
      float *var154;
      var71 = &(var168);
      *(var71) = (var68 + var40);
      var38 = *(var71);
      var69 = &(var169);
      *(var69) = (var67 + var41);
      var37 = *(var69);
      var148 = (var0 + (var38 * 16384));
      var149 = (var148 + (var37 * 128));
      var152 = *((var149 + 1));
      var146 = (var55 + (2 * 9));
      var147 = (var146 + (var68 * 3));
      var154 = (var147 + var67);
      *(var154) = var152;
    }
  }
  for (int var36 = 0; var36 < 126; var36++) {
    float *var9;
    float *var117;
    float *var118;
    float var10;
    float *var115;
    float *var116;
    float var11;
    float *var113;
    float *var114;
    float var12;
    float *var111;
    float *var112;
    float var13;
    float *var109;
    float *var110;
    float var14;
    float *var107;
    float *var108;
    float var15;
    float *var105;
    float *var106;
    float var16;
    float *var52;
    float var173;
    float var23;
    float *var50;
    float var174;
    float var24;
    float *var48;
    float var175;
    float var25;
    float *var46;
    float var176;
    float var26;
    float *var44;
    float var177;
    float var27;
    float *var42;
    float var178;
    float var28;
    float *var95;
    float *var96;
    float *var98;
    for (int var77 = 0; var77 < 3; var77++) {
      for (int var76 = 0; var76 < 3; var76++) {
        float *var140;
        float *var141;
        float *var142;
        float var143;
        float *var138;
        float *var139;
        float *var145;
        var140 = var55;
        var141 = (var140 + (1 * 9));
        var142 = (var141 + (var77 * 3));
        var143 = *((var142 + var76));
        var138 = (var55 + (0 * 9));
        var139 = (var138 + (var77 * 3));
        var145 = (var139 + var76);
        *(var145) = var143;
      }
    }
    for (int var82 = 0; var82 < 3; var82++) {
      for (int var81 = 0; var81 < 3; var81++) {
        float *var132;
        float *var133;
        float *var134;
        float var135;
        float *var130;
        float *var131;
        float *var137;
        var132 = var55;
        var133 = (var132 + (2 * 9));
        var134 = (var133 + (var82 * 3));
        var135 = *((var134 + var81));
        var130 = (var55 + (1 * 9));
        var131 = (var130 + (var82 * 3));
        var137 = (var131 + var81);
        *(var137) = var135;
      }
    }
    for (int var87 = 0; var87 < 3; var87++) {
      for (int var86 = 0; var86 < 3; var86++) {
        int *var90;
        int var170;
        int var38;
        int *var88;
        int var171;
        int var37;
        float *var122;
        float *var123;
        int *var92;
        int var172;
        int var124;
        float var127;
        float *var119;
        float *var120;
        float *var129;
        var90 = &(var170);
        *(var90) = (var87 + var40);
        var38 = *(var90);
        var88 = &(var171);
        *(var88) = (var86 + var41);
        var37 = *(var88);
        var122 = (var0 + (var38 * 16384));
        var123 = (var122 + (var37 * 128));
        var92 = &(var172);
        *(var92) = (var36 + 2);
        var124 = *(var92);
        var127 = *((var123 + var124));
        var119 = (var55 + (2 * 9));
        var120 = (var119 + (var87 * 3));
        var129 = (var120 + var86);
        *(var129) = var127;
      }
    }
    var9 = var55;
    var117 = (var9 + (1 * 9));
    var118 = (var117 + (1 * 3));
    var10 = *((var118 + 0));
    var115 = (var9 + (0 * 9));
    var116 = (var115 + (1 * 3));
    var11 = *((var116 + 1));
    var113 = (var9 + (1 * 9));
    var114 = (var113 + (0 * 3));
    var12 = *((var114 + 1));
    var111 = (var9 + (1 * 9));
    var112 = (var111 + (1 * 3));
    var13 = *((var112 + 1));
    var109 = (var9 + (1 * 9));
    var110 = (var109 + (2 * 3));
    var14 = *((var110 + 1));
    var107 = (var9 + (2 * 9));
    var108 = (var107 + (1 * 3));
    var15 = *((var108 + 1));
    var105 = (var9 + (1 * 9));
    var106 = (var105 + (1 * 3));
    var16 = *((var106 + 2));
    var52 = &(var173);
    *(var52) = (var10 + var11);
    var23 = *(var52);
    var50 = &(var174);
    *(var50) = (var23 + var12);
    var24 = *(var50);
    var48 = &(var175);
    *(var48) = (var24 + var13);
    var25 = *(var48);
    var46 = &(var176);
    *(var46) = (var25 + var14);
    var26 = *(var46);
    var44 = &(var177);
    *(var44) = (var26 + var15);
    var27 = *(var44);
    var42 = &(var178);
    *(var42) = (var27 + var16);
    var28 = *(var42);
    var95 = (var39 + (var40 * 15876));
    var96 = (var95 + (var41 * 126));
    var98 = (var96 + var36);
    *(var98) = (var28 / 7.00000);
  }
}
