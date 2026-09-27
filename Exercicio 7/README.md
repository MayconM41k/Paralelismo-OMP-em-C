# ExercÃ­cio 7: Combinando shared e private

## ðŸ“Œ Conceito Principal
Particionamento de dados combinado com declaraÃ§Ã£o explÃ­cita de variÃ¡veis shared e private.

---

## ðŸ’» CÃ³digo C (Limpo / Sem ComentÃ¡rios)

`c
#include <stdio.h>
#include <omp.h>

int dados[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int main() {
    int soma_local;

    #pragma omp parallel shared(dados) private(soma_local)
    {
        int id = omp_get_thread_num();
        int nthreads = omp_get_num_threads();

        soma_local = 0;

        int inicio = (id * 10) / nthreads;
        int fim = ((id + 1) * 10) / nthreads;

        for (int i = inicio; i < fim; i++) {
            soma_local += dados[i];
        }

        printf("Thread %d: soma_local = %d\n", id, soma_local);
    }

    return 0;
}

`

---

### Como o CÃ³digo Funciona

1. **Escopo de Dados:**
   - shared(dados): O vetor global de 10 elementos Ã© compartilhado para leitura entre todas as threads.
   - private(soma_local): Cada thread possui seu prÃ³prio acumulador local inicializado em 0.

2. **Particionamento Manual de Ãndices:**
   - int inicio = (id * 10) / nthreads; e int fim = ((id + 1) * 10) / nthreads;: Calculam a fatia de Ã­ndices do vetor que cada thread deve somar.

3. **AcumulaÃ§Ã£o sem Race Condition:**
   - A soma Ã© realizada apenas na variÃ¡vel privada soma_local, permitindo execuÃ§Ã£o paralela segura sem necessidade de bloqueios.