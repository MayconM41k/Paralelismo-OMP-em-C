/*
 * Exercício 3: Contando Threads
 * Objetivo: Praticar a leitura de informações sobre o ambiente paralelo.
 * 
 * Tarefa: Crie um programa que, dentro de uma região paralela, cada thread imprima seu ID 
 * e o número total de threads. Execute com diferentes valores de OMP_NUM_THREADS (2, 4, 8).
 */

#include <stdio.h>
#include <omp.h>

int main() {
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        int total = omp_get_num_threads();

        printf("Thread ID: %d | Total de Threads: %d\n", id, total);
    }

    return 0;
}
