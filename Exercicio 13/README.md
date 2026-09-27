# ExercÃ­cio 13: Preenchendo uma Matriz

## ðŸ“Œ Conceito Principal
ParalelizaÃ§Ã£o de loops aninhados aplicados ao processamento de matrizes.

---

## ðŸ’» CÃ³digo C (Limpo / Sem ComentÃ¡rios)

`c
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

`

---

### Como o CÃ³digo Funciona

1. **ParalelizaÃ§Ã£o do Loop Externo:**
   - #pragma omp parallel for Ã© aplicado diretamente sobre o loop externo (or (int i = 0; i < L; i++)).

2. **DistribuiÃ§Ã£o por Linhas:**
   - Cada thread fica responsÃ¡vel por um conjunto de linhas inteiras da matriz.
   - Dentro de sua linha atribuÃ­da, a thread executa o loop interno de colunas j sequencialmente.

3. **EficiÃªncia de Cache:**
   - O acesso contÃ­guo por linhas (M[i][j]) preserva a localidade espacial do cache de memÃ³ria.