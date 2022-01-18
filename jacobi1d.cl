#define VECTOR_SIZE 2048

__kernel
void saxpy_kernel(__global float *A,
                  __global float *C)
{                                   
    int gi = get_global_id(0);   
    if (gi > 0 && gi < VECTOR_SIZE - 1) {
        C[gi] = (A[gi - 1] + A[gi] + A[gi +1 ]) * 0.333; }
} 