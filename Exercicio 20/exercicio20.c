/*
 * Exercício 20: Tarefas Independentes com sections
 * Objetivo: Paralelizar tarefas independentes.
 * 
 * Tarefa: Crie um programa com uma região paralela que use sections para executar três tarefas independentes simultaneamente:
 * Seção 1: Calcula a soma de todos os elementos de um vetor.
 * Seção 2: Calcula o produto de todos os elementos de um (pequeno) vetor.
 * Seção 3: Encontra o valor mínimo no vetor.
 * Cada seção deve imprimir seu resultado e o ID da thread que a executou.
 */

#include <stdio.h>
#include <omp.h>

#define N 100

int main() {
    int v1[N], v2[5] = {1, 2, 3, 4, 5}, v3[N];

    for (int i = 0; i < N; i++) {
        v1[i] = i + 1;
        v3[i] = 500 - i;
    }

    #pragma omp parallel
    {
        #pragma omp sections
        {
            // Seção 1: Soma de todos os elementos
            #pragma omp section
            {
                int id = omp_get_thread_num();
                int soma = 0;
                for (int i = 0; i < N; i++) soma += v1[i];
                printf("Seção 1 (Thread %d): Soma = %d\n", id, soma);
            }

            // Seção 2: Produto dos elementos
            #pragma omp section
            {
                int id = omp_get_thread_num();
                int produto = 1;
                for (int i = 0; i < 5; i++) produto *= v2[i];
                printf("Seção 2 (Thread %d): Produto = %d\n", id, produto);
            }

            // Seção 3: Valor mínimo no vetor
            #pragma omp section
            {
                int id = omp_get_thread_num();
                int min = v3[0];
                for (int i = 1; i < N; i++) {
                    if (v3[i] < min) min = v3[i];
                }
                printf("Seção 3 (Thread %d): Mínimo = %d\n", id, min);
            }
        }
    }

    return 0;
}
