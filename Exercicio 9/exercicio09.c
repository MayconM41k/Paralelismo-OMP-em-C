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
