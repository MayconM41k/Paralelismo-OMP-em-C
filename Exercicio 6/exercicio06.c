/*
 * Exercício 6: Inicializando com firstprivate
 * Objetivo: Usar firstprivate para inicializar cópias privadas com um valor pré-existente.
 * 
 * Tarefa: Declare uma variável multiplicador = 5 fora da região paralela. Dentro da região, 
 * declare resultado como firstprivate(multiplicador). Cada thread deve calcular 
 * resultado = resultado * (omp_get_thread_num() + 1) e imprimir o valor final. 
 * Todas as threads começam com resultado = 5.
 */

#include <stdio.h>
#include <omp.h>

int main() {
    int multiplicador = 5;

    #pragma omp parallel firstprivate(multiplicador)
    {
        int id = omp_get_thread_num();
        int resultado = multiplicador;

        resultado = resultado * (id + 1);

        printf("Thread %d: resultado = %d\n", id, resultado);
    }

    return 0;
}
