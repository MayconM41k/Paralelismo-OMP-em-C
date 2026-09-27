/*
 * Exercício 2: A Thread Mestre
 * Objetivo: Diferenciar a thread mestre das demais.
 * 
 * Tarefa: Dentro de uma região paralela, faça a thread mestre (ID 0) imprimir "Sou a thread MESTRE!" 
 * e todas as outras imprimirem "Sou uma thread trabalhadora.". Use um if com omp_get_thread_num().
 */

#include <stdio.h>
#include <omp.h>

int main() {
    #pragma omp parallel
    {
        int id = omp_get_thread_num();

        if (id == 0) {
            printf("Sou a thread MESTRE!\n");
        } else {
            printf("Sou uma thread trabalhadora.\n");
        }
    }

    return 0;
}
