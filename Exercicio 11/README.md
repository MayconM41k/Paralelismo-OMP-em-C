# ExercÃ­cio 11: Soma de Vetores

## ðŸ“Œ Conceito Principal
OperaÃ§Ã£o element-wise paralela em vetores de grande porte com alocaÃ§Ã£o dinÃ¢mica de memÃ³ria.

---

## ðŸ’» CÃ³digo C (Limpo / Sem ComentÃ¡rios)

`c
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000000

int main() {
    int *A = (int *)malloc(N * sizeof(int));
    int *B = (int *)malloc(N * sizeof(int));
    int *C = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        A[i] = rand() % 100;
        B[i] = rand() % 100;
    }

    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        C[i] = A[i] + B[i];
    }

    printf("Verificando os 5 primeiros elementos:\n");
    for (int i = 0; i < 5; i++) {
        printf("C[%d] = %d (A[%d] = %d + B[%d] = %d)\n", i, C[i], i, A[i], i, B[i]);
    }

    free(A);
    free(B);
    free(C);
    return 0;
}

`

---

### Como o CÃ³digo Funciona

1. **AlocaÃ§Ã£o DinÃ¢mica de MemÃ³ria:**
   - malloc(N * sizeof(int)): Aloca dinamicamente trÃªs vetores A, B e C de tamanho N = 1.000.000 na *heap*.

2. **ParalelizaÃ§Ã£o da Soma Elemento a Elemento:**
   - #pragma omp parallel for: Distribui o milhÃ£o de iteraÃ§Ãµes da operaÃ§Ã£o C[i] = A[i] + B[i] entre as threads disponÃ­veis.
   - Como cada elemento C[i] Ã© calculado de forma totalmente independente dos outros, nÃ£o hÃ¡ dependÃªncia de dados (*embarrassingly parallel*).

3. **LiberaÃ§Ã£o de MemÃ³ria:**
   - ree(A), ree(B), ree(C) liberam a memÃ³ria alocada ao final da execuÃ§Ã£o.