__kernel void cl_kernel(__global float *var16, __global float *var55) {
  int var56;
  int var57;
  float *var220[27];
  float *var87;
  var56 = get_global_id(0);
  var57 = get_global_id(1);
  var87 = &(var220);
  for (int var91 = 0; var91 < 3; var91++) {
    for (int var90 = 0; var90 < 3; var90++) {
      int *var94;
      int var221;
      int var54;
      int *var92;
      int var222;
      int var53;
      float *var213;
      float *var214;
      float var217;
      float *var211;
      float *var212;
      float *var219;
      var94 = &(var221);
      *(var94) = (var91 + var56);
      var54 = *(var94);
      var92 = &(var222);
      *(var92) = (var90 + var57);
      var53 = *(var92);
      var213 = (var16 + (var54 * 16384));
      var214 = (var213 + (var53 * 128));
      var217 = *((var214 + 0));
      var211 = (var87 + (1 * 9));
      var212 = (var211 + (var91 * 3));
      var219 = (var212 + var90);
      *(var219) = var217;
    }
  }
  for (int var100 = 0; var100 < 3; var100++) {
    for (int var99 = 0; var99 < 3; var99++) {
      int *var103;
      int var223;
      int var54;
      int *var101;
      int var224;
      int var53;
      float *var204;
      float *var205;
      float var208;
      float *var202;
      float *var203;
      float *var210;
      var103 = &(var223);
      *(var103) = (var100 + var56);
      var54 = *(var103);
      var101 = &(var224);
      *(var101) = (var99 + var57);
      var53 = *(var101);
      var204 = (var16 + (var54 * 16384));
      var205 = (var204 + (var53 * 128));
      var208 = *((var205 + 1));
      var202 = (var87 + (2 * 9));
      var203 = (var202 + (var100 * 3));
      var210 = (var203 + var99);
      *(var210) = var208;
    }
  }
  for (int var52 = 0; var52 < 126; var52++) {
    float *var24;
    float *var173;
    float *var174;
    float var1;
    float *var171;
    float *var172;
    float var2;
    float *var169;
    float *var170;
    float var3;
    float *var167;
    float *var168;
    float var4;
    float *var165;
    float *var166;
    float var5;
    float *var163;
    float *var164;
    float var6;
    float *var161;
    float *var162;
    float var7;
    float *var159;
    float *var160;
    float var8;
    float *var157;
    float *var158;
    float var9;
    float *var155;
    float *var156;
    float var10;
    float *var153;
    float *var154;
    float var11;
    float *var151;
    float *var152;
    float var12;
    float *var149;
    float *var150;
    float var13;
    float *var147;
    float *var148;
    float var14;
    float *var145;
    float *var146;
    float var15;
    float *var84;
    float var228;
    float var31;
    float *var82;
    float var229;
    float var32;
    float *var80;
    float var230;
    float var33;
    float *var78;
    float var231;
    float var34;
    float *var76;
    float var232;
    float var35;
    float *var74;
    float var233;
    float var36;
    float *var72;
    float var234;
    float var37;
    float *var70;
    float var235;
    float var38;
    float *var68;
    float var236;
    float var39;
    float *var66;
    float var237;
    float var40;
    float *var64;
    float var238;
    float var41;
    float *var62;
    float var239;
    float var42;
    float *var60;
    float var240;
    float var43;
    float *var58;
    float var241;
    float var44;
    float *var127;
    float *var128;
    float *var130;
    for (int var109 = 0; var109 < 3; var109++) {
      for (int var108 = 0; var108 < 3; var108++) {
        float *var196;
        float *var197;
        float *var198;
        float var199;
        float *var194;
        float *var195;
        float *var201;
        var196 = var87;
        var197 = (var196 + (1 * 9));
        var198 = (var197 + (var109 * 3));
        var199 = *((var198 + var108));
        var194 = (var87 + (0 * 9));
        var195 = (var194 + (var109 * 3));
        var201 = (var195 + var108);
        *(var201) = var199;
      }
    }
    for (int var114 = 0; var114 < 3; var114++) {
      for (int var113 = 0; var113 < 3; var113++) {
        float *var188;
        float *var189;
        float *var190;
        float var191;
        float *var186;
        float *var187;
        float *var193;
        var188 = var87;
        var189 = (var188 + (2 * 9));
        var190 = (var189 + (var114 * 3));
        var191 = *((var190 + var113));
        var186 = (var87 + (1 * 9));
        var187 = (var186 + (var114 * 3));
        var193 = (var187 + var113);
        *(var193) = var191;
      }
    }
    for (int var119 = 0; var119 < 3; var119++) {
      for (int var118 = 0; var118 < 3; var118++) {
        int *var122;
        int var225;
        int var54;
        int *var120;
        int var226;
        int var53;
        float *var178;
        float *var179;
        int *var124;
        int var227;
        int var180;
        float var183;
        float *var175;
        float *var176;
        float *var185;
        var122 = &(var225);
        *(var122) = (var119 + var56);
        var54 = *(var122);
        var120 = &(var226);
        *(var120) = (var118 + var57);
        var53 = *(var120);
        var178 = (var16 + (var54 * 16384));
        var179 = (var178 + (var53 * 128));
        var124 = &(var227);
        *(var124) = (var52 + 2);
        var180 = *(var124);
        var183 = *((var179 + var180));
        var175 = (var87 + (2 * 9));
        var176 = (var175 + (var119 * 3));
        var185 = (var176 + var118);
        *(var185) = var183;
      }
    }
    var24 = var87;
    var173 = (var24 + (1 * 9));
    var174 = (var173 + (0 * 3));
    var1 = *((var174 + 0));
    var171 = (var24 + (1 * 9));
    var172 = (var171 + (0 * 3));
    var2 = *((var172 + 1));
    var169 = (var24 + (1 * 9));
    var170 = (var169 + (0 * 3));
    var3 = *((var170 + 2));
    var167 = (var24 + (1 * 9));
    var168 = (var167 + (1 * 3));
    var4 = *((var168 + 0));
    var165 = (var24 + (1 * 9));
    var166 = (var165 + (1 * 3));
    var5 = *((var166 + 1));
    var163 = (var24 + (1 * 9));
    var164 = (var163 + (1 * 3));
    var6 = *((var164 + 2));
    var161 = (var24 + (1 * 9));
    var162 = (var161 + (2 * 3));
    var7 = *((var162 + 0));
    var159 = (var24 + (1 * 9));
    var160 = (var159 + (2 * 3));
    var8 = *((var160 + 1));
    var157 = (var24 + (1 * 9));
    var158 = (var157 + (2 * 3));
    var9 = *((var158 + 2));
    var155 = (var24 + (0 * 9));
    var156 = (var155 + (1 * 3));
    var10 = *((var156 + 0));
    var153 = (var24 + (0 * 9));
    var154 = (var153 + (1 * 3));
    var11 = *((var154 + 1));
    var151 = (var24 + (0 * 9));
    var152 = (var151 + (1 * 3));
    var12 = *((var152 + 2));
    var149 = (var24 + (2 * 9));
    var150 = (var149 + (1 * 3));
    var13 = *((var150 + 0));
    var147 = (var24 + (2 * 9));
    var148 = (var147 + (1 * 3));
    var14 = *((var148 + 1));
    var145 = (var24 + (2 * 9));
    var146 = (var145 + (1 * 3));
    var15 = *((var146 + 2));
    var84 = &(var228);
    *(var84) = (var1 + var2);
    var31 = *(var84);
    var82 = &(var229);
    *(var82) = (var31 + var3);
    var32 = *(var82);
    var80 = &(var230);
    *(var80) = (var32 + var4);
    var33 = *(var80);
    var78 = &(var231);
    *(var78) = (var33 + var5);
    var34 = *(var78);
    var76 = &(var232);
    *(var76) = (var34 + var6);
    var35 = *(var76);
    var74 = &(var233);
    *(var74) = (var35 + var7);
    var36 = *(var74);
    var72 = &(var234);
    *(var72) = (var36 + var8);
    var37 = *(var72);
    var70 = &(var235);
    *(var70) = (var37 + var9);
    var38 = *(var70);
    var68 = &(var236);
    *(var68) = (var38 + var10);
    var39 = *(var68);
    var66 = &(var237);
    *(var66) = (var39 + var11);
    var40 = *(var66);
    var64 = &(var238);
    *(var64) = (var40 + var12);
    var41 = *(var64);
    var62 = &(var239);
    *(var62) = (var41 + var13);
    var42 = *(var62);
    var60 = &(var240);
    *(var60) = (var42 + var14);
    var43 = *(var60);
    var58 = &(var241);
    *(var58) = (var43 + var15);
    var44 = *(var58);
    var127 = (var55 + (var56 * 15876));
    var128 = (var127 + (var57 * 126));
    var130 = (var128 + var52);
    *(var130) = (var44 / 7.00000);
  }
}
