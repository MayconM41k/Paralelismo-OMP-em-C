/*
 * Exercício 19: Máximo e Mínimo com reduction
 * Objetivo: Usar reduction para operações de máximo e mínimo.
 * 
 * Tarefa: Crie um vetor com N números aleatórios. Paralelize um loop que encontra simultaneamente 
 * o maior e o menor valor usando reduction(max:maior) e reduction(min:menor). Imprima os resultados.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <omp.h>

#define N 1000000

int main() {
    int *vetor = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        vetor[i] = rand() % 100000;
    }

    int maior = INT_MIN;
    int menor = INT_MAX;

    #pragma omp parallel for reduction(max:maior) reduction(min:menor)
    for (int i = 0; i < N; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }

    printf("Maior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);

    free(vetor);
    return 0;
}
