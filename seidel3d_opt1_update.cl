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
        
        float reg[15]; 
        if (pos_z == 0) {
            reg[0] = 0;
            reg[1] = 0;
            reg[2] = 0;
            reg[3] = 0;
            reg[4] = 0;
        }
        else {
            reg[0] = set[pos_x-1][pos_y][pos_z-1];
            reg[1] = set[pos_x][pos_y-1][pos_z-1];
            reg[2] = set[pos_x][pos_y][pos_z-1];
            reg[3] = set[pos_x][pos_y+1][pos_z-1];
            reg[4] = set[pos_x+1][pos_y][pos_z-1];
        }
        reg[5] = set[pos_x-1][pos_y][pos_z];
        reg[6] = set[pos_x][pos_y-1][pos_z];
        reg[7] = set[pos_x][pos_y][pos_z];
        reg[8] = set[pos_x][pos_y+1][pos_z];
        reg[9] = set[pos_x+1][pos_y][pos_z];

        reg[10] = set[pos_x-1][pos_y][pos_z+1];
        reg[11] = set[pos_x][pos_y-1][pos_z+1];
        reg[12] = set[pos_x][pos_y][pos_z+1];
        reg[13] = set[pos_x][pos_y+1][pos_z+1];
        reg[14] = set[pos_x+1][pos_y][pos_z+1];

        
        for(i = 0; i < DEPTH; i++){
            if(pos_x > 0 && pos_y > 0 && pos_z > 0 && pos_x < NX - 1 && pos_y < NY - 1 && pos_z < NZ - 1){

            reg[0] = reg[5];
            reg[1] = reg[6];
            reg[2] = reg[7];
            reg[3] = reg[8];
            reg[4] = reg[9];
            reg[5] = reg[10];
            reg[6] = reg[11];
            reg[7] = reg[12];
            reg[8] = reg[13];
            reg[9] = reg[14];
            reg[10] = set[pos_x-1][pos_y][pos_z+1];
            reg[11] = set[pos_x][pos_y-1][pos_z+1];
            reg[12] = set[pos_x][pos_y][pos_z+1];
            reg[13] = set[pos_x][pos_y+1][pos_z+1];
            reg[14] = set[pos_x+1][pos_y][pos_z+1];
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
                                          ) * 0.1;
            }
            pos_z++;
        }
    }
}
