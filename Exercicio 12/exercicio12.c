/*
 * Exercício 12: Produto Escalar
 * Objetivo: Paralelizar um loop simples com uma operação aritmética.
 * 
 * Tarefa: Crie dois vetores A e B de tamanho N. Paralelize o cálculo do produto escalar (dot product): 
 * resultado = Σ(A[i] * B[i]). Use um loop parallel for simples. Qual é o problema com essa abordagem? 
 * (Dica: múltiplas threads atualizando a mesma variável resultado).
 * 
 * RESPOSTA: O problema com essa abordagem é a OCORRÊNCIA DE RACE CONDITION (condição de corrida).
 * Como várias threads tentam atualizar simultaneamente a variável 'resultado' sem nenhuma proteção,
 * os valores parciais se sobrescrevem e o resultado final fica incorreto e imprevisível.
 */

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

    // Loop parallel for simples solicitado no exercício (provoca race condition)
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        resultado += A[i] * B[i]; // Problema: Race Condition na variável 'resultado'
    }

    printf("Resultado do produto escalar (com Race Condition): %d\n", resultado);
    printf("Resultado esperado: %d\n", N * 2);

    return 0;
}
