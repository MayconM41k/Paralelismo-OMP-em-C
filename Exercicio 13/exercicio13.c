/*
 * Exercício 13: Preenchendo uma Matriz
 * Objetivo: Paralelizar loops aninhados.
 * 
 * Tarefa: Crie uma matriz M[L][C] (ex: 1000x1000). Paralelize o loop que preenche a matriz 
 * com M[i][j] = i + j. Use #pragma omp parallel for no loop externo (linhas). 
 * Verifique alguns valores para garantir a correção.
 */

#include <stdio.h>
#include <omp.h>

#define L 1000
#define C 1000

int M[L][C];

int main() {
    // Paralelizando apenas o loop externo (linhas) conforme pedido
    #pragma omp parallel for
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            M[i][j] = i + j;
        }
    }

    // Verificando alguns valores amostrais
    printf("M[0][0] = %d (Esperado: 0)\n", M[0][0]);
    printf("M[100][200] = %d (Esperado: 300)\n", M[100][200]);
    printf("M[999][999] = %d (Esperado: 1998)\n", M[999][999]);

    return 0;
}
