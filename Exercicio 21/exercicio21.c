/*
 * Exercício 21: Cálculo de Pi com reduction
 * Objetivo: Aplicar reduction a um problema matemático clássico (Série de Leibniz).
 * 
 * Contexto: π / 4 = 1 - 1/3 + 1/5 - 1/7 + 1/9 - ...
 * Dica do Professor: O termo i da série pode ser calculado como pow(-1, i) / (2 * i + 1).
 * 
 * Tarefa:
 * • Crie um programa que calcule uma aproximação de Pi usando N = 1.000.000.000 (ou N menor para execução rápida).
 * • Paralelize o loop que calcula a soma dos termos usando #pragma omp parallel for.
 * • Use a cláusula reduction(+:soma_parcial) para acumular a soma dos termos de forma segura.
 * • Multiplique o resultado final por 4 para obter a estimativa de Pi.
 * • Compare o tempo de execução da versão serial com a versão paralela (com 2, 4, 8 threads).
 */

#include <stdio.h>
#include <math.h>
#include <omp.h>

#define N 100000000L // 100 milhões para rodar rápido e dar resultado preciso

int main() {
    double soma_parcial = 0.0;
    double inicio, fim;

    // 1. Versão Serial
    inicio = omp_get_wtime();
    for (long i = 0; i < N; i++) {
        soma_parcial += pow(-1, i) / (2.0 * i + 1.0);
    }
    double pi_serial = soma_parcial * 4.0;
    fim = omp_get_wtime();
    double tempo_serial = fim - inicio;
    printf("Serial:   Pi = %.8f | Tempo: %.4f seg\n", pi_serial, tempo_serial);

    // 2. Versão Paralela (testando com 2, 4 e 8 threads)
    int threads_lista[] = {2, 4, 8};
    for (int k = 0; k < 3; k++) {
        int t = threads_lista[k];
        omp_set_num_threads(t);
        soma_parcial = 0.0;

        inicio = omp_get_wtime();
        #pragma omp parallel for reduction(+:soma_parcial)
        for (long i = 0; i < N; i++) {
            soma_parcial += pow(-1, i) / (2.0 * i + 1.0);
        }
        double pi_paralelo = soma_parcial * 4.0;
        fim = omp_get_wtime();

        printf("Paralelo (%d threads): Pi = %.8f | Tempo: %.4f seg\n", t, pi_paralelo, fim - inicio);
    }

    return 0;
}
