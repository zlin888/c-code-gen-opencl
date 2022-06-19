#define NX 128 
#define NY 128 
#define NZ 128 

#define DEPTH 64

/* Three dimensional Jacobi kernel */
__kernel void cl_kernel(__global float *p_set, __global float *p_res) {
    int pos_z = get_global_id(2);
    
    if(pos_z % DEPTH == 0){    
        __global float (*set)[NY][NZ] = (__global float (*)[NY][NZ])p_set;
        __global float (*res)[NY][NZ] = (__global float (*)[NY][NZ])p_res;        
        int pos_x = get_global_id(0);
        int pos_y = get_global_id(1);
        int i;
        
        float reg[28]; 
        if (pos_z == 0) {
            for(int i = 0; i < 9; i++) {
                reg[i] = 0;
            }
        }
        else {
            for(int i = 0; i < 3; i++) {
                int base = 0;
                reg[base + i] = set[pos_x-1][pos_y+i-1][pos_z-1];
                reg[base + i + 3] = set[pos_x][pos_y+i-1][pos_z-1];
                reg[base + i + 6] = set[pos_x+1][pos_y+i-1][pos_z-1];
            }
        }
        
        for(int i = 0; i < 3; i++) {
            int base = 9;
            reg[base + i] = set[pos_x-1][pos_y+i-1][pos_z];
            reg[base + i + 3] = set[pos_x][pos_y+i-1][pos_z];
            reg[base + i + 6] = set[pos_x+1][pos_y+i-1][pos_z];
        }

        for(int i = 0; i < 3; i++) {
            int base = 18;
            reg[base + i] = set[pos_x-1][pos_y+i-1][pos_z+1];
            reg[base + i + 3] = set[pos_x][pos_y+i-1][pos_z+1];
            reg[base + i + 6] = set[pos_x+1][pos_y+i-1][pos_z+1];
        }
        
        for(i = 0; i < DEPTH; i++){
            if(pos_x > 0 && pos_y > 0 && pos_z > 0 && pos_x < NX - 1 && pos_y < NY - 1 && pos_z < NZ - 1){

            reg[0] = reg[10];
            reg[1] = reg[11];
            reg[2] = reg[12];
            reg[3] = reg[13];
            reg[4] = reg[14];
            reg[5] = reg[15];
            reg[6] = reg[16];
            reg[7] = reg[17];
            reg[8] = reg[18];

            reg[10] = reg[19]; 
            reg[11] = reg[20]; 
            reg[12] = reg[21]; 
            reg[13] = reg[22]; 
            reg[14] = reg[23]; 
            reg[15] = reg[24]; 
            reg[16] = reg[25]; 
            reg[17] = reg[26]; 
            reg[18] = reg[27];

        for(int i = 0; i < 3; i++) {
            int base = 18;
            reg[base + i] = set[pos_x-1][pos_y+i-1][pos_z+1];
            reg[base + i + 3] = set[pos_x][pos_y+i-1][pos_z+1];
            reg[base + i + 6] = set[pos_x+1][pos_y+i-1][pos_z+1];
        }

            res[pos_x][pos_y][pos_z] =  (
                                         reg[0]
                                       + reg[1]
                                       + reg[2]
                                       + reg[3]
                                       + reg[4]
                                       + reg[5]
                                       + reg[6]
                                       + reg[7]
                                       + reg[8]
                                       + reg[9]
                                       + reg[10]
                                       + reg[11]
                                       + reg[12]
                                       + reg[13]
                                       + reg[14]
                                       + reg[15]
                                       + reg[16]
                                       + reg[17]
                                       + reg[18]

                                       + reg[19]
                                       + reg[20]
                                       + reg[21]
                                       + reg[22]
                                       + reg[23]
                                       + reg[24]
                                       + reg[25]
                                       + reg[26]
                                       + reg[27]

                                          ) * 0.1;
            }
            pos_z++;
        }
    }
}
