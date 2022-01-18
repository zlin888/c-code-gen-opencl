#define NX (2 << 12)
#define NY (2 << 12) 

__kernel 
void cl_kernel(__global float * p_set, __global float * p_res) {
    __global float (*set)[NY] = (__global float (*)[NY])p_set;
    __global float (*res)[NY] = (__global float (*)[NY])p_res;
    int pos_x = get_global_id(0);
    int pos_y = get_global_id(1);
    
    if(pos_x > 0 && pos_x < NX-1 && pos_y > 0 && pos_y < NY - 1){
    	res[pos_x][pos_y] = (set[pos_x - 1][pos_y] + set[pos_x + 1][pos_y] +
    	                     set[pos_x][pos_y - 1] + set[pos_x][pos_y + 1] +
    	                     set[pos_x][pos_y]) * 0.2;
    }
}
