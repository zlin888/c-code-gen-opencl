#define N 128

/* Three dimensional Jacobi kernel */
__kernel void cl_kernel(__global float * p_set, __global float * p_res) {
    __global float (*set)[N][N] = (__global float (*)[N][N])p_set;
    __global float (*res)[N][N] = (__global float (*)[N][N])p_res;
    int pos_x = get_global_id(0);
    int pos_y = get_global_id(1);
    int pos_z = get_global_id(2);

    if(pos_x > 0 && pos_x < N-1 && pos_y > 0 && pos_y < N - 1 && pos_z > 0 && pos_z < N -1){
    	res[pos_x][pos_y][pos_z] = (set[pos_x - 1][pos_y][pos_z] + set[pos_x + 1][pos_y][pos_z] +
    	                            set[pos_x][pos_y - 1][pos_z] + set[pos_x][pos_y + 1][pos_z] +
    	                            set[pos_x][pos_y][pos_z - 1] + set[pos_x][pos_y][pos_z + 1] +
    	                            set[pos_x][pos_y][pos_z]) * 0.1428571;
  	}
}
