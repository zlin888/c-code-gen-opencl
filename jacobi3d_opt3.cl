#define NX 128
#define NY 128
#define NZ 128

#define DIM_X 4
#define DIM_Y 4
#define DIM_Z 4

/* Three dimensional Jacobi kernel */
__kernel void cl_kernel(__global float * p_set, __global float * p_res) {
    __global float (*set)[NY][NZ] = (__global float (*)[NY][NZ])p_set;
    __global float (*res)[NY][NZ] = (__global float (*)[NY][NZ])p_res;
    int g_x = get_global_id(0);
    int g_y = get_global_id(1);
    int g_z = get_global_id(2);
    int l_x = get_local_id(0);
    int l_y = get_local_id(1);
    int l_z = get_local_id(2);   
    
    __local float p_item[DIM_X][DIM_Y][DIM_Z];
    item[l_x][l_y][l_z] = set[g_x][g_y][g_z];
    barrier(CLK_LOCAL_MEM_FENCE);
    
    if(g_x > 0 && g_x < NX - 1 && g_y > 0 && g_y < NY - 1 && g_z > 0 && g_z < NZ - 1){
    	if(l_x > 0 && l_y > 0 && l_z > 0 && l_x < DIM_X-1 && l_y < DIM_Y-1 && l_z < DIM_Z-1)
    		res[g_x][g_y][g_z] = (item[l_x - 1][l_y][l_z] + item[l_x + 1][l_y][l_z] +
    									item[l_x][l_y - 1][l_z] + item[l_x][l_y + 1][l_z] +
    									item[l_x][l_y][l_z - 1] + item[l_x][l_y][l_z + 1] +
    									item[l_x][l_y][l_z]) * 0.1428571;
    	else
    		res[g_x][g_y][g_z] = (set[g_x - 1][g_y][g_z] + set[g_x + 1][g_y][g_z] +
    	    	                        set[g_x][g_y - 1][g_z] + set[g_x][g_y + 1][g_z] +
    	    	                        set[g_x][g_y][g_z - 1] + set[g_x][g_y][g_z + 1] +
    	    	                        set[g_x][g_y][g_z]) * 0.1428571;
    }
}
