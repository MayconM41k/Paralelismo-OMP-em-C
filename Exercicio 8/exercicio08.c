#include <stdio.h>
#include <omp.h>

int dados[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int main() {
    int soma_local;

    #pragma omp parallel default(none) shared(dados) private(soma_local)
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
