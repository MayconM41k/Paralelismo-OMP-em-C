/*
 * Exercício 14: Comparando Estratégias de schedule
 * Objetivo: Observar o efeito das diferentes políticas de escalonamento.
 * 
 * Tarefa: Crie um loop onde o trabalho de cada iteração é desigual. Por exemplo, a iteração i realiza (N-i) * 1000 operações 
 * (simule com um loop vazio). Paralelize o loop e execute três vezes com diferentes políticas:
 * 1 schedule(static)
 * 2 schedule(dynamic, 1)
 * 3 schedule(guided)
 * Meça o tempo total de execução para cada política. Qual se saiu melhor para essa carga de trabalho desbalanceada?
 */

#include <stdio.h>
#include <omp.h>

#define N 1000

int main() {
    double inicio, fim;

    // 1. schedule(static)
    inicio = omp_get_wtime();
    #pragma omp parallel for schedule(static)
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < (N - i) * 1000; k++) {
            // Loop vazio simulando trabalho
        }
    }
    fim = omp_get_wtime();
    printf("1. schedule(static):     %.4f segundos\n", fim - inicio);

    // 2. schedule(dynamic, 1)
    inicio = omp_get_wtime();
    #pragma omp parallel for schedule(dynamic, 1)
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < (N - i) * 1000; k++) {
            // Loop vazio simulando trabalho
        }
    }
    fim = omp_get_wtime();
    printf("2. schedule(dynamic, 1): %.4f segundos\n", fim - inicio);

    // 3. schedule(guided)
    inicio = omp_get_wtime();
    #pragma omp parallel for schedule(guided)
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < (N - i) * 1000; k++) {
            // Loop vazio simulando trabalho
        }
    }
    fim = omp_get_wtime();
    printf("3. schedule(guided):     %.4f segundos\n", fim - inicio);

    return 0;
}
