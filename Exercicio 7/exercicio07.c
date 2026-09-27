/*
 * Exercício 7: Combinando shared e private
 * Objetivo: Praticar a declaração explícita de múltiplas variáveis com escopos diferentes.
 * 
 * Tarefa: Crie um vetor global dados[10] com valores 1 a 10. Dentro de uma região paralela, 
 * declare uma variável soma_local como private. Cada thread deve somar os elementos do vetor 
 * que lhe "pertencem" (ex: thread 0 soma índices 0-2, thread 1 soma 3-5, etc.) em sua soma_local 
 * e imprimir o resultado. O vetor dados é shared.
 */

#include <stdio.h>
#include <omp.h>

int dados[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int main() {
    int soma_local;

    #pragma omp parallel shared(dados) private(soma_local)
    {
        int id = omp_get_thread_num();
        int nthreads = omp_get_num_threads();

        soma_local = 0;

        int inicio = (id * 10) / nthreads;
        int fim = ((id + 1) * 10) / nthreads;

        for (int i = inicio; i < fim; i++) {
            soma_local += dados[i];
        }

        printf("Thread %d: soma_local = %d\n", id, soma_local);
    }

    return 0;
}
