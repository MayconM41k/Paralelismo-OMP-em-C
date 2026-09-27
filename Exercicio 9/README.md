# ExercÃ­cio 9: DistribuiÃ§Ã£o Manual com istart/iend

## ðŸ“Œ Conceito Principal
DivisÃ£o manual de iteraÃ§Ãµes de loop entre threads utilizando a lÃ³gica de limites istart e iend.

---

## ðŸ’» CÃ³digo C (Limpo / Sem ComentÃ¡rios)

`c
#include <stdio.h>
#include <omp.h>

int main() {
    int vetor[100];

    #pragma omp parallel shared(vetor)
    {
        int id = omp_get_thread_num();
        int nthreads = omp_get_num_threads();

        int istart = id * 100 / nthreads;
        int iend = (id + 1) * 100 / nthreads;

        for (int i = istart; i < iend; i++) {
            vetor[i] = id;
        }
    }

    printf("Vetor preenchido (Manual):\n");
    for (int i = 0; i < 100; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}

`

---

### Como o CÃ³digo Funciona

1. **CÃ¡lculo dos Limites de IteraÃ§Ã£o:**
   - int istart = id * 100 / nthreads;: Determina o Ã­ndice de inÃ­cio do bloco para a thread atual.
   - int iend = (id + 1) * 100 / nthreads;: Determina o Ã­ndice de fim (exclusivo).

2. **Preenchimento Paralelo:**
   - O loop or (int i = istart; i < iend; i++) faz com que cada thread escreva seu prÃ³prio ID apenas no intervalo do vetor pelo qual Ã© responsÃ¡vel.

3. **SaÃ­da:**
   - A impressÃ£o final do vetor demonstra que o vetor foi preenchido em blocos contÃ­guos correspondentes a cada thread.