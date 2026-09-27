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
