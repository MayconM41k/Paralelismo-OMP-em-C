# ExercÃ­cio 21: CÃ¡lculo de Pi com reduction

## ðŸ“Œ Conceito Principal
ParalelizaÃ§Ã£o da SÃ©rie de Leibniz para aproximaÃ§Ã£o de Pi e mediÃ§Ã£o empÃ­rica de Speedup.

---

## ðŸ’» CÃ³digo C (Limpo / Sem ComentÃ¡rios)

`c
#include <stdio.h>
#include <math.h>
#include <omp.h>

#define N 100000000L

int main() {
    double soma_parcial = 0.0;
    double inicio, fim;

    inicio = omp_get_wtime();
    for (long i = 0; i < N; i++) {
        soma_parcial += pow(-1, i) / (2.0 * i + 1.0);
    }
    double pi_serial = soma_parcial * 4.0;
    fim = omp_get_wtime();
    double tempo_serial = fim - inicio;
    printf("Serial:   Pi = %.8f | Tempo: %.4f seg\n", pi_serial, tempo_serial);

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

`

---

### Como o CÃ³digo Funciona

1. **FÃ³rmula MatemÃ¡tica:**
   - Aproxima o valor de Pi atravÃ©s da SÃ©rie de Leibniz: Pi / 4 = 1 - 1/3 + 1/5 - 1/7 + ...

2. **VersÃ£o Serial vs Paralela:**
   - Executa primeiro a soma serial de 100.000.000 de termos.
   - Em seguida, executa a versÃ£o paralela utilizando #pragma omp parallel for reduction(+:soma_parcial) variando o nÃºmero de threads (2, 4 e 8).

3. **MediÃ§Ã£o de Tempo:**
   - A funÃ§Ã£o omp_get_wtime() captura o tempo inicial e final para calcular e exibir a aceleraÃ§Ã£o (*speedup*) obtida com a paralelizaÃ§Ã£o.