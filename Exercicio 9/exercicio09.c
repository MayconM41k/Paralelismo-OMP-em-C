/*
 * Exercício 9: Distribuição Manual com istart/iend
 * Objetivo: Entender a lógica por trás da diretiva for.
 * 
 * Tarefa: Crie um vetor de 100 posições. Usando o código de cálculo manual de istart e iend (apresentado na aula), 
 * paralelize um loop onde cada thread preenche sua fatia do vetor com o seu próprio ID. 
 * Imprima o vetor para verificar que cada thread preencheu sua região.
 */

#include <stdio.h>
#include <omp.h>

int main() {
    int vetor[100];

    #pragma omp parallel shared(vetor)
    {
        int id = omp_get_thread_num();
        int nthreads = omp_get_num_threads();

        int istart = id * 100 / nthreads;
        int iend = (id + 1) * 100 / nthreads;

        for (int i = istart; i < iend; i++) {
            vetor[i] = id;
        }
    }

    printf("Vetor preenchido (Manual):\n");
    for (int i = 0; i < 100; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
