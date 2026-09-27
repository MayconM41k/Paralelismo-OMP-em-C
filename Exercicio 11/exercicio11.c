#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000000

int main() {
    int *A = (int *)malloc(N * sizeof(int));
    int *B = (int *)malloc(N * sizeof(int));
    int *C = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        A[i] = rand() % 100;
        B[i] = rand() % 100;
    }

    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        C[i] = A[i] + B[i];
    }

    printf("Verificando os 5 primeiros elementos:\n");
    for (int i = 0; i < 5; i++) {
        printf("C[%d] = %d (A[%d] = %d + B[%d] = %d)\n", i, C[i], i, A[i], i, B[i]);
    }

    free(A);
    free(B);
    free(C);
    return 0;
}
