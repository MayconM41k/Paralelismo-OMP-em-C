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
