# ExercÃ­cio 22: MultiplicaÃ§Ã£o Matriz-Vetor

## ðŸ“Œ Conceito Principal
ParalelizaÃ§Ã£o de multiplicaÃ§Ã£o de matriz por vetor em Ã¡lgebra linear computacional.

---

## ðŸ’» CÃ³digo C (Limpo / Sem ComentÃ¡rios)

`c
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void multiplicar_matriz_vetor(int L, int C) {
    double *M = (double *)malloc((size_t)L * C * sizeof(double));
    double *V = (double *)malloc(C * sizeof(double));
    double *R = (double *)malloc(L * sizeof(double));

    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            M[(size_t)i * C + j] = 1.0;
        }
    }
    for (int j = 0; j < C; j++) {
        V[j] = 2.0;
    }

    double inicio = omp_get_wtime();

    #pragma omp parallel for
    for (int i = 0; i < L; i++) {
        double soma = 0.0;
        for (int j = 0; j < C; j++) {
            soma += M[(size_t)i * C + j] * V[j];
        }
        R[i] = soma;
    }

    double fim = omp_get_wtime();
    printf("Matriz %dx%d | Tempo Paralelo: %.4f segundos\n", L, C, fim - inicio);

    free(M);
    free(V);
    free(R);
}

int main() {
    printf("--- Multiplicação Matriz-Vetor Paralela ---\n");
    multiplicar_matriz_vetor(1000, 1000);
    multiplicar_matriz_vetor(3000, 3000);

    return 0;
}

`

---

### Como o CÃ³digo Funciona

1. **Mapeamento de Matriz 1D:**
   - A matriz M de dimensÃ£o L x C Ã© alocada dinamicamente como um vetor contÃ­guo 1D acessado via M[i * C + j].

2. **ParalelizaÃ§Ã£o das Linhas:**
   - O loop externo de linhas (i) Ã© paralelizado com #pragma omp parallel for.
   - Cada thread processa a multiplicaÃ§Ã£o escalar completa de uma linha da matriz pelo vetor V e armazena o resultado no elemento R[i].

3. **Escalabilidade:**
   - O programa testa matrizes de 1000 x 1000 e 3000 x 3000, demonstrando o ganho de tempo e escala do cÃ³digo paralelo em cargas elevadas.