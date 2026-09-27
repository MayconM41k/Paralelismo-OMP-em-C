# ExercÃ­cio 15: Protegendo com critical

## ðŸ“Œ Conceito Principal
Garantia de exclusÃ£o mÃºtua e proteÃ§Ã£o de seÃ§Ãµes crÃ­ticas usando #pragma omp critical.

---

## ðŸ’» CÃ³digo C (Limpo / Sem ComentÃ¡rios)

`c
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000000

int main() {
    int *vetor = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        vetor[i] = rand() % 500000;
    }
    vetor[500000] = 999999;

    int maior_sem_protecao = vetor[0];
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        if (vetor[i] > maior_sem_protecao) {
            maior_sem_protecao = vetor[i];
        }
    }
    printf("Maior valor (Sem proteção / Race Condition): %d\n", maior_sem_protecao);

    int maior_correto = vetor[0];
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        #pragma omp critical
        {
            if (vetor[i] > maior_correto) {
                maior_correto = vetor[i];
            }
        }
    }
    printf("Maior valor (Corrigido com #pragma omp critical): %d\n", maior_correto);

    free(vetor);
    return 0;
}

`

---

### Como o CÃ³digo Funciona

1. **VersÃ£o Incorreta (Sem ProteÃ§Ã£o):**
   - MÃºltiplas threads atualizam maior_sem_protecao concorrentemente, gerando race condition.

2. **Diretiva #pragma omp critical:**
   - Define um bloco de exclusÃ£o mÃºtua. Apenas **uma Ãºnica thread por vez** pode executar o cÃ³digo contido dentro da seÃ§Ã£o critical.

3. **CorreÃ§Ã£o:**
   - Ao proteger o if (vetor[i] > maior_correto), a verificaÃ§Ã£o e atualizaÃ§Ã£o ocorrem de forma segura, garantindo que o maior valor correto do vetor seja encontrado.