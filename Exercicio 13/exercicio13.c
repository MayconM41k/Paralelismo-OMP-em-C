#include <stdio.h>
#include <omp.h>

#define L 1000
#define C 1000

int M[L][C];

int main() {

    #pragma omp parallel for
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            M[i][j] = i + j;
        }
    }

    printf("M[0][0] = %d (Esperado: 0)\n", M[0][0]);
    printf("M[100][200] = %d (Esperado: 300)\n", M[100][200]);
    printf("M[999][999] = %d (Esperado: 1998)\n", M[999][999]);

    return 0;
}
