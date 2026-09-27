/*
 * Exercício 22: Multiplicação de Matriz-Vetor
 * Objetivo: Paralelizar uma operação de álgebra linear fundamental.
 * 
 * Tarefa: Implemente a multiplicação de uma matriz M (tamanho L x C) por um vetor V (tamanho C), 
 * resultando em um vetor R (tamanho L). A operação para cada elemento é:
 * R[i] = Σ(M[i][j] * V[j]) para j = 0 até C-1
 * 
 * • Paralelize o loop externo (que itera sobre as linhas i da matriz) usando #pragma omp parallel for.
 * • Teste com matrizes de diferentes tamanhos (ex: 1000x1000, 3000x3000) e meça o desempenho.
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void multiplicar_matriz_vetor(int L, int C) {
    double *M = (double *)malloc((size_t)L * C * sizeof(double));
    double *V = (double *)malloc(C * sizeof(double));
    double *R = (double *)malloc(L * sizeof(double));

    // Inicialização simples
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            M[(size_t)i * C + j] = 1.0;
        }
    }
    for (int j = 0; j < C; j++) {
        V[j] = 2.0;
    }

    double inicio = omp_get_wtime();

    // Paralelização do loop externo (linhas i) com parallel for
    #pragma omp parallel for
    for (int i = 0; i < L; i++) {
        double soma = 0.0;
        for (int j = 0; j < C; j++) {
            soma += M[(size_t)i * C + j] * V[j];
        }
        R[i] = soma;
    }

    double fim = omp_get_wtime();
    printf("Matriz %dx%d | Tempo Paralelo: %.4f segundos\n", L, C, fim - inicio);

    free(M);
    free(V);
    free(R);
}

int main() {
    printf("--- Multiplicação Matriz-Vetor Paralela ---\n");
    multiplicar_matriz_vetor(1000, 1000);
    multiplicar_matriz_vetor(3000, 3000);

    return 0;
}
