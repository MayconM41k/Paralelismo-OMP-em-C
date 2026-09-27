#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 100000

int main() {
    int A[N], B[N];
    int resultado = 0;

    for (int i = 0; i < N; i++) {
        A[i] = 1;
        B[i] = 2;
    }

    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        resultado += A[i] * B[i];
    }

    printf("Resultado do produto escalar (com Race Condition): %d\n", resultado);
    printf("Resultado esperado: %d\n", N * 2);

    return 0;
}
