#include <stdio.h>
#include <omp.h>

int main() {
    #pragma omp parallel
    {
        int id = omp_get_thread_num();

        if (id == 0) {
            printf("Sou a thread MESTRE!\n");
        } else {
            printf("Sou uma thread trabalhadora.\n");
        }
    }

    return 0;
}
