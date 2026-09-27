/*
 * Exercício 1: Olá, Mundo Paralelo!
 * Objetivo: Familiarizar-se com a criação de uma região paralela.
 * 
 * Tarefa: Crie um programa em C que entre em uma região paralela. 
 * Cada thread deve imprimir: "Olá! Sou a thread <ID> de <N_THREADS> threads.".
 * Compile com -fopenmp e execute com OMP_NUM_THREADS=4.
 * Dica: Use omp_get_thread_num() e omp_get_num_threads().
 */

#include <stdio.h>
#include <omp.h>

int main() {
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        int n_threads = omp_get_num_threads();

        printf("Olá! Sou a thread %d de %d threads.\n", id, n_threads);
    }

    return 0;
}
