/*
 * Exercício 16: Operações Atômicas com atomic
 * Objetivo: Usar atomic para operações simples e rápidas.
 * 
 * Tarefa: Crie um programa que conte quantos números em um vetor são múltiplos de 3. 
 * Use uma variável global contador. Dentro de um parallel for, se vetor[i] % 3 == 0, 
 * incremente o contador usando #pragma omp atomic. Compare o desempenho com a versão usando critical.
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 10000000

int contador_global = 0;

int main() {
    int *vetor = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        vetor[i] = i;
    }

    // 1. Versão usando #pragma omp atomic
    contador_global = 0;
    double inicio = omp_get_wtime();
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        if (vetor[i] % 3 == 0) {
            #pragma omp atomic
            contador_global++;
        }
    }
    double fim = omp_get_wtime();
    printf("Versão ATOMIC:   Contador = %d | Tempo: %.4f seg\n", contador_global, fim - inicio);

    // 2. Versão usando #pragma omp critical
    contador_global = 0;
    inicio = omp_get_wtime();
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        if (vetor[i] % 3 == 0) {
            #pragma omp critical
            {
                contador_global++;
            }
        }
    }
    fim = omp_get_wtime();
    printf("Versão CRITICAL: Contador = %d | Tempo: %.4f seg\n", contador_global, fim - inicio);

    free(vetor);
    return 0;
}
