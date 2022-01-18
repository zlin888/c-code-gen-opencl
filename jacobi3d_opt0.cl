#define N 128

#define DEPTH 4

/* Three dimensional Jacobi kernel */
__kernel void cl_kernel(__global float *p_set, __global float *p_res) {
    int pos_y = get_global_id(1);
    
    if(pos_y % DEPTH == 0){    
        __global float (*set)[N][N] = (__global float (*)[N][N])p_set;
        __global float (*res)[N][N] = (__global float (*)[N][N])p_res;        
        int pos_x = get_global_id(0);
        int pos_z = get_global_id(2);
        int i;
        
        float reg[] = {set[pos_x][pos_y][pos_z], set[pos_x][pos_y + 1][pos_z], 
                       set[pos_x][pos_y + 2][pos_z], set[pos_x][pos_y + 3][pos_z]};
                       	
        if(pos_x > 0 && pos_z > 0 && pos_x < N - 1 && pos_z < N - 1){
			if(pos_y != 0){		
				res[pos_x][pos_y][pos_z] = (set[pos_x - 1][pos_y][pos_z] + set[pos_x + 1][pos_y][pos_z] +
										   set[pos_x][pos_y - 1][pos_z] + reg[0] + reg[1] +
										   set[pos_x][pos_y][pos_z - 1] + set[pos_x][pos_y][pos_z + 1]) * 0.142857;
			}
			
			pos_y++;
		
			res[pos_x][pos_y][pos_z] = (set[pos_x - 1][pos_y][pos_z] + set[pos_x + 1][pos_y][pos_z] +
										   reg[0] + reg[1] + reg[2] +
										   set[pos_x][pos_y][pos_z - 1] + set[pos_x][pos_y][pos_z + 1]) * 0.142857;
			pos_y++;		
		
			res[pos_x][pos_y][pos_z] = (set[pos_x - 1][pos_y][pos_z] + set[pos_x + 1][pos_y][pos_z] +
										   reg[1] + reg[2] + reg[3] +
										   set[pos_x][pos_y][pos_z - 1] + set[pos_x][pos_y][pos_z + 1]) * 0.142857;
			pos_y++;
			if(pos_y != N - 1){
				res[pos_x][pos_y][pos_z] = (set[pos_x - 1][pos_y][pos_z] + set[pos_x + 1][pos_y][pos_z] +
										   	   reg[2] + reg[3] + set[pos_x][pos_y + 1][pos_z] +
										  	   set[pos_x][pos_y][pos_z -1] + set[pos_x][pos_y][pos_z + 1]) * 0.142857;						    			}	
    	}
    }
}
