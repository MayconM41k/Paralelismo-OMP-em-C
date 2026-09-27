#include <stdio.h>
#include <omp.h>

#define N 1000

int main() {
    double inicio, fim;

    inicio = omp_get_wtime();
    #pragma omp parallel for schedule(static)
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < (N - i) * 1000; k++) {

        }
    }
    fim = omp_get_wtime();
    printf("1. schedule(static):     %.4f segundos\n", fim - inicio);

    inicio = omp_get_wtime();
    #pragma omp parallel for schedule(dynamic, 1)
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < (N - i) * 1000; k++) {

        }
    }
    fim = omp_get_wtime();
    printf("2. schedule(dynamic, 1): %.4f segundos\n", fim - inicio);

    inicio = omp_get_wtime();
    #pragma omp parallel for schedule(guided)
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < (N - i) * 1000; k++) {

        }
    }
    fim = omp_get_wtime();
    printf("3. schedule(guided):     %.4f segundos\n", fim - inicio);

    return 0;
}
