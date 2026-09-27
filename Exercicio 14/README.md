# ExercÃ­cio 14: Comparando EstratÃ©gias de schedule

## ðŸ“Œ Conceito Principal
AnÃ¡lise de desempenho comparativa entre as polÃ­ticas de escalonamento static, dynamic e guided.

---

## ðŸ’» CÃ³digo C (Limpo / Sem ComentÃ¡rios)

`c
#include <stdio.h>
#include <omp.h>

#define N 1000

int main() {
    double inicio, fim;

    inicio = omp_get_wtime();
    #pragma omp parallel for schedule(static)
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < (N - i) * 1000; k++) {

        }
    }
    fim = omp_get_wtime();
    printf("1. schedule(static):     %.4f segundos\n", fim - inicio);

    inicio = omp_get_wtime();
    #pragma omp parallel for schedule(dynamic, 1)
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < (N - i) * 1000; k++) {

        }
    }
    fim = omp_get_wtime();
    printf("2. schedule(dynamic, 1): %.4f segundos\n", fim - inicio);

    inicio = omp_get_wtime();
    #pragma omp parallel for schedule(guided)
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < (N - i) * 1000; k++) {

        }
    }
    fim = omp_get_wtime();
    printf("3. schedule(guided):     %.4f segundos\n", fim - inicio);

    return 0;
}

`

---

### Como o CÃ³digo Funciona

1. **SimulaÃ§Ã£o de Carga Desequilibrada:**
   - O loop interno realiza (N - i) * 1000 iteraÃ§Ãµes, ou seja, as primeiras iteraÃ§Ãµes possuem muito mais trabalho que as Ãºltimas.

2. **EstratÃ©gia schedule(static):**
   - Divide as iteraÃ§Ãµes em blocos fixos antes de iniciar a execuÃ§Ã£o. Gera desbalanceamento de carga pois threads com as primeiras iteraÃ§Ãµes demoram muito mais.

3. **EstratÃ©gia schedule(dynamic, 1):**
   - Distribui iteraÃ§Ãµes dinamicamente em tempo de execuÃ§Ã£o conforme as threads concluem suas tarefas anteriores.

4. **EstratÃ©gia schedule(guided):**
   - Inicia distribuindo blocos grandes de iteraÃ§Ãµes e vai reduzindo o tamanho dos blocos progressivamente, combinando baixo overhead com bom balanceamento.