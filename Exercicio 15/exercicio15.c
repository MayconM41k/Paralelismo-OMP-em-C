/*
 * Exercício 15: Protegendo com critical
 * Objetivo: Usar critical para proteger seções de código.
 * 
 * Tarefa: Crie um programa que encontre o maior valor em um vetor de números aleatórios. 
 * Escreva uma versão paralela que tenha uma race condition óbvia (sem proteção). 
 * Depois, corrija usando #pragma omp critical para proteger a comparação e atualização do maior valor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000000

int main() {
    int *vetor = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        vetor[i] = rand() % 500000;
    }
    vetor[500000] = 999999; // Maior valor conhecido

    // Versão sem proteção (com Race Condition óbvia)
    int maior_sem_protecao = vetor[0];
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        if (vetor[i] > maior_sem_protecao) {
            maior_sem_protecao = vetor[i]; // Race condition
        }
    }
    printf("Maior valor (Sem proteção / Race Condition): %d\n", maior_sem_protecao);

    // Versão corrigida com #pragma omp critical
    int maior_correto = vetor[0];
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        #pragma omp critical
        {
            if (vetor[i] > maior_correto) {
                maior_correto = vetor[i];
            }
        }
    }
    printf("Maior valor (Corrigido com #pragma omp critical): %d\n", maior_correto);

    free(vetor);
    return 0;
}
