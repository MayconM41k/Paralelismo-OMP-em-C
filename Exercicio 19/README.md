# ExercÃ­cio 19: MÃ¡ximo e MÃ­nimo com reduction

## ðŸ“Œ Conceito Principal
AplicaÃ§Ã£o da clÃ¡usula reduction para busca paralela de valores mÃ¡ximos e mÃ­nimos.

---

## ðŸ’» CÃ³digo C (Limpo / Sem ComentÃ¡rios)

`c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <omp.h>

#define N 1000000

int main() {
    int *vetor = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        vetor[i] = rand() % 100000;
    }

    int maior = INT_MIN;
    int menor = INT_MAX;

    #pragma omp parallel for reduction(max:maior) reduction(min:menor)
    for (int i = 0; i < N; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }

    printf("Maior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);

    free(vetor);
    return 0;
}

`

---

### Como o CÃ³digo Funciona

1. **MÃºltiplas ClÃ¡usulas de ReduÃ§Ã£o:**
   - eduction(max:maior): Cria cÃ³pias privadas de maior inicializadas com o menor valor possÃ­vel (INT_MIN).
   - eduction(min:menor): Cria cÃ³pias privadas de menor inicializadas com o maior valor possÃ­vel (INT_MAX).

2. **ExecuÃ§Ã£o:**
   - Cada thread determina o mÃ¡ximo e o mÃ­nimo dentro da sua subfatia do vetor.
   - No encerramento do loop, os resultados parciais das threads sÃ£o reduzidos aos valores globais corretos de mÃ¡ximo e mÃ­nimo.