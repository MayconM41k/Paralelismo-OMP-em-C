/*
 * Exercício 11: Soma de Vetores
 * Objetivo: Praticar um caso de uso real e simples do parallel for.
 * 
 * Tarefa: Crie dois vetores A e B de tamanho N (ex: N = 1.000.000) com valores aleatórios. 
 * Paralelize a operação C[i] = A[i] + B[i] usando #pragma omp parallel for. 
 * Verifique alguns valores de C para garantir a correção.
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000000

int main() {
    int *A = (int *)malloc(N * sizeof(int));
    int *B = (int *)malloc(N * sizeof(int));
    int *C = (int *)malloc(N * sizeof(int));

    // Preenchendo vetores com valores aleatórios simples
    for (int i = 0; i < N; i++) {
        A[i] = rand() % 100;
        B[i] = rand() % 100;
    }

    // Paralelização com parallel for
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        C[i] = A[i] + B[i];
    }

    // Verificando alguns valores de C
    printf("Verificando os 5 primeiros elementos:\n");
    for (int i = 0; i < 5; i++) {
        printf("C[%d] = %d (A[%d] = %d + B[%d] = %d)\n", i, C[i], i, A[i], i, B[i]);
    }

    free(A);
    free(B);
    free(C);
    return 0;
}
