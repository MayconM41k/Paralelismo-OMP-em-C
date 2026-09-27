# ExercÃ­cio 12: Produto Escalar com Race Condition

## ðŸ“Œ Conceito Principal
AnÃ¡lise prÃ¡tica do problema de condiÃ§Ã£o de corrida na acumulaÃ§Ã£o do produto escalar de vetores.

---

## ðŸ’» CÃ³digo C (Limpo / Sem ComentÃ¡rios)

`c
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 100000

int main() {
    int A[N], B[N];
    int resultado = 0;

    for (int i = 0; i < N; i++) {
        A[i] = 1;
        B[i] = 2;
    }

    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        resultado += A[i] * B[i];
    }

    printf("Resultado do produto escalar (com Race Condition): %d\n", resultado);
    printf("Resultado esperado: %d\n", N * 2);

    return 0;
}

`

---

### Como o CÃ³digo Funciona

1. **CÃ¡lculo do Produto Escalar:**
   - Computa a soma dos produtos termo a termo de dois vetores A e B.

2. **O Problema da Abordagem Direta:**
   - O bloco #pragma omp parallel for paraleliza o loop, mas a instruÃ§Ã£o esultado += A[i] * B[i] faz com que todas as threads tentem modificar a mesma variÃ¡vel compartilhada esultado.

3. **Resultado:**
   - Devido Ã  falta de sincronizaÃ§Ã£o ou instruÃ§Ã£o de reduÃ§Ã£o, ocorrem colisÃµes de gravaÃ§Ã£o na memÃ³ria, fazendo com que o valor final seja incorreto e diferente do valor esperado.