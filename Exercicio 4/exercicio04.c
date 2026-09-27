/*
 * Exercício 4: Race Condition com shared
 * Objetivo: Visualizar uma race condition na prática.
 * 
 * Tarefa: Declare uma variável contador compartilhada inicializada com 0. Dentro de uma região paralela, 
 * faça cada thread incrementar contador 100 vezes em um loop. Ao final, imprima o valor de contador. 
 * Será igual a N_THREADS * 100? Execute várias vezes e observe a inconsistência.
 */

#include <stdio.h>
#include <omp.h>

int main() {
    int contador = 0;

    #pragma omp parallel shared(contador)
    {
        for (int i = 0; i < 100; i++) {
            contador++; // Race condition
        }
    }

    printf("Valor final de contador: %d\n", contador);

    return 0;
}
