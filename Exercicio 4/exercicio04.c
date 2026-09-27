#include <stdio.h>
#include <omp.h>

int main() {
    int contador = 0;

    #pragma omp parallel shared(contador)
    {
        for (int i = 0; i < 100; i++) {
            contador++;
        }
    }

    printf("Valor final de contador: %d\n", contador);

    return 0;
}
