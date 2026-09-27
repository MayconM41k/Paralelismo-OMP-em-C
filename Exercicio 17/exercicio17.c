/*
 * Exercício 17: Sincronização com barrier
 * Objetivo: Usar barrier para sincronizar threads em um ponto específico.
 * 
 * Tarefa: Crie um programa onde cada thread executa duas fases de trabalho. Na primeira fase, 
 * cada thread calcula um valor parcial. Depois, há uma barreira. Na segunda fase, 
 * cada thread usa os valores calculados por todas as threads na primeira fase. 
 * Use #pragma omp barrier entre as duas fases.
 */

#include <stdio.h>
#include <omp.h>

int valores_parciais[16];

int main() {
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        int total = omp_get_num_threads();

        // Primeira fase: calcula um valor parcial
        valores_parciais[id] = (id + 1) * 10;
        printf("Thread %d [Fase 1]: valor parcial = %d\n", id, valores_parciais[id]);

        // Barreira de sincronização entre as duas fases
        #pragma omp barrier

        // Segunda fase: usa os valores calculados por todas as threads na primeira fase
        int soma = 0;
        for (int i = 0; i < total; i++) {
            soma += valores_parciais[i];
        }
        printf("Thread %d [Fase 2]: soma de todas as parciais = %d\n", id, soma);
    }

    return 0;
}
