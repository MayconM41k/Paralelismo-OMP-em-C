#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 10000000

int main() {
    int *vetor = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        vetor[i] = rand() % 10;
    }

    long long soma = 0;
    double inicio = omp_get_wtime();
    #pragma omp parallel for reduction(+:soma)
    for (int i = 0; i < N; i++) {
        soma += vetor[i];
    }
    double fim = omp_get_wtime();
    printf("1. REDUCTION: Soma = %lld | Tempo: %.4f seg\n", soma, fim - inicio);

    long long soma_atomic = 0;
    inicio = omp_get_wtime();
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        #pragma omp atomic
        soma_atomic += vetor[i];
    }
    fim = omp_get_wtime();
    printf("2. ATOMIC:    Soma = %lld | Tempo: %.4f seg\n", soma_atomic, fim - inicio);

    free(vetor);
    return 0;
}
