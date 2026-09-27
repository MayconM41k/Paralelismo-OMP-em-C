# ExercÃ­cio 16: OperaÃ§Ãµes AtÃ´micas com atomic

## ðŸ“Œ Conceito Principal
OtimizaÃ§Ã£o de sincronizaÃ§Ã£o para operaÃ§Ãµes simples em memÃ³ria utilizando #pragma omp atomic.

---

## ðŸ’» CÃ³digo C (Limpo / Sem ComentÃ¡rios)

`c
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 10000000

int contador_global = 0;

int main() {
    int *vetor = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        vetor[i] = i;
    }

    contador_global = 0;
    double inicio = omp_get_wtime();
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        if (vetor[i] % 3 == 0) {
            #pragma omp atomic
            contador_global++;
        }
    }
    double fim = omp_get_wtime();
    printf("Versão ATOMIC:   Contador = %d | Tempo: %.4f seg\n", contador_global, fim - inicio);

    contador_global = 0;
    inicio = omp_get_wtime();
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        if (vetor[i] % 3 == 0) {
            #pragma omp critical
            {
                contador_global++;
            }
        }
    }
    fim = omp_get_wtime();
    printf("Versão CRITICAL: Contador = %d | Tempo: %.4f seg\n", contador_global, fim - inicio);

    free(vetor);
    return 0;
}

`

---

### Como o CÃ³digo Funciona

1. **Diretiva #pragma omp atomic:**
   - Garante que uma operaÃ§Ã£o de atualizaÃ§Ã£o de memÃ³ria especÃ­fica (como contador_global++) seja executada de forma atÃ´mica no nÃ­vel do hardware.

2. **ComparaÃ§Ã£o com #pragma omp critical:**
   - O programa executa a mesma contagem usando tomic e critical.
   - tomic possui um overhead imensamente menor que critical, pois nÃ£o necessita de travas complexas de software (locks), sendo ideal para operaÃ§Ãµes aritmÃ©ticas simples.