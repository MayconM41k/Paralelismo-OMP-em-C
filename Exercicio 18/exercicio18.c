/*
 * Exercício 18: Soma com reduction
 * Objetivo: Usar reduction para operações de acumulação.
 * 
 * Tarefa: Crie um vetor com N números aleatórios. Use #pragma omp parallel for com a cláusula 
 * reduction(+:soma) para calcular a soma de todos os elementos. 
 * Compare o desempenho com a versão usando atomic ou critical.
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 10000000

int main() {
    int *vetor = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        vetor[i] = rand() % 10;
    }

    // 1. Versão com reduction(+:soma)
    long long soma = 0;
    double inicio = omp_get_wtime();
    #pragma omp parallel for reduction(+:soma)
    for (int i = 0; i < N; i++) {
        soma += vetor[i];
    }
    double fim = omp_get_wtime();
    printf("1. REDUCTION: Soma = %lld | Tempo: %.4f seg\n", soma, fim - inicio);

    // 2. Versão com atomic
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
