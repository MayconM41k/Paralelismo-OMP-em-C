/*
 * Exercício 10: Usando parallel for
 * Objetivo: Usar a forma automática e simples de paralelizar loops.
 * 
 * Tarefa: Converta o Exercício 9 para usar #pragma omp parallel for. 
 * O resultado deve ser o mesmo, mas o código será muito mais limpo e legível.
 */

#include <stdio.h>
#include <omp.h>

int main() {
    int vetor[100];

    #pragma omp parallel for
    for (int i = 0; i < 100; i++) {
        vetor[i] = omp_get_thread_num();
    }

    printf("Vetor preenchido com parallel for:\n");
    for (int i = 0; i < 100; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
