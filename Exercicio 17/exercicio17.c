#include <stdio.h>
#include <omp.h>

int valores_parciais[16];

int main() {
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        int total = omp_get_num_threads();

        valores_parciais[id] = (id + 1) * 10;
        printf("Thread %d [Fase 1]: valor parcial = %d\n", id, valores_parciais[id]);

        #pragma omp barrier

        int soma = 0;
        for (int i = 0; i < total; i++) {
            soma += valores_parciais[i];
        }
        printf("Thread %d [Fase 2]: soma de todas as parciais = %d\n", id, soma);
    }

    return 0;
}
