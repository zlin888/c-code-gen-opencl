#define NX 4096
#define NY 4096
#define DIM_X 32
#define DIM_Y 32

/* Three dimensional Jacobi kernel */
__kernel void cl_kernel(__global float * p_set, __global float * p_res) {
    __global float (*set)[NY] = (__global float (*)[NY])p_set;
    __global float (*res)[NY] = (__global float (*)[NY])p_res;

    __local float item[DIM_X][DIM_Y];

    int g_x = get_global_id(0);
    int g_y = get_global_id(1);
    int l_x = get_local_id(0);
    int l_y = get_local_id(1);
    
    //Loading data in workgroup memory
    item[l_x][l_y] = set[g_x][g_y];
    barrier(CLK_LOCAL_MEM_FENCE);	

    if(g_x > 0 && g_x < NX-1 && g_y > 0 && g_y < NY - 1){
    	if(l_x > 0 && l_y > 0 && l_x < DIM_X - 1 && l_y < DIM_Y - 1){
			res[g_x][g_y] = (item[l_x - 1][l_y] + item[l_x + 1][l_y] +
			                     item[l_x][l_y - 1] + item[l_x][l_y + 1] +
			                     item[l_x][l_y]) * 0.2;
		}else{
			res[g_x][g_y] = (set[g_x - 1][g_y] + set[g_x + 1][g_y] +
								set[g_x][g_y - 1] + set[g_x][g_y + 1] +
								set[g_x][g_y]) * 0.2;
		}
    }
}
