# ExercÃ­cio 20: Tarefas Independentes com sections

## ðŸ“Œ Conceito Principal
Paralelismo de seÃ§Ãµes/tarefas funcionais utilizando as diretivas #pragma omp sections e section.

---

## ðŸ’» CÃ³digo C (Limpo / Sem ComentÃ¡rios)

`c
#include <stdio.h>
#include <omp.h>

#define N 100

int main() {
    int v1[N], v2[5] = {1, 2, 3, 4, 5}, v3[N];

    for (int i = 0; i < N; i++) {
        v1[i] = i + 1;
        v3[i] = 500 - i;
    }

    #pragma omp parallel
    {
        #pragma omp sections
        {

            #pragma omp section
            {
                int id = omp_get_thread_num();
                int soma = 0;
                for (int i = 0; i < N; i++) soma += v1[i];
                printf("Seção 1 (Thread %d): Soma = %d\n", id, soma);
            }

            #pragma omp section
            {
                int id = omp_get_thread_num();
                int produto = 1;
                for (int i = 0; i < 5; i++) produto *= v2[i];
                printf("Seção 2 (Thread %d): Produto = %d\n", id, produto);
            }

            #pragma omp section
            {
                int id = omp_get_thread_num();
                int min = v3[0];
                for (int i = 1; i < N; i++) {
                    if (v3[i] < min) min = v3[i];
                }
                printf("Seção 3 (Thread %d): Mínimo = %d\n", id, min);
            }
        }
    }

    return 0;
}

`

---

### Como o CÃ³digo Funciona

1. **Diretiva #pragma omp sections:**
   - Agrupa um conjunto de seÃ§Ãµes de cÃ³digo funcionalmente independentes para serem distribuÃ­das entre a equipe de threads.

2. **Sub-seÃ§Ãµes (#pragma omp section):**
   - Cada bloco #pragma omp section define uma tarefa distinta (SeÃ§Ã£o 1: soma, SeÃ§Ã£o 2: produto, SeÃ§Ã£o 3: busca de mÃ­nimo).

3. **ExecuÃ§Ã£o Paralela:**
   - Threads livres da equipe pegam cada uma das seÃ§Ãµes e as executam concorrentemente.