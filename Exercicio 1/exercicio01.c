#include <stdio.h>
#include <omp.h>

int main() {
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        int n_threads = omp_get_num_threads();

        printf("Olá! Sou a thread %d de %d threads.\n", id, n_threads);
    }

    return 0;
}
