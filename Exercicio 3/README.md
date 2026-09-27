# ExercÃ­cio 3: Contando Threads

## ðŸ“Œ Conceito Principal
Consulta e verificaÃ§Ã£o da quantidade de threads no ambiente de execuÃ§Ã£o OpenMP.

---

## ðŸ’» CÃ³digo C (Limpo / Sem ComentÃ¡rios)

`c
#include <stdio.h>
#include <omp.h>

int main() {
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        int total = omp_get_num_threads();

        printf("Thread ID: %d | Total de Threads: %d\n", id, total);
    }

    return 0;
}

`

---

### Como o CÃ³digo Funciona

1. **RegiÃ£o Paralela (#pragma omp parallel):**
   - Instancia as threads de acordo com a variÃ¡vel de ambiente OMP_NUM_THREADS definida no sistema.

2. **Leitura das InformaÃ§Ãµes do Ambiente:**
   - int id = omp_get_thread_num();: Armazena o ID da thread atual.
   - int total = omp_get_num_threads();: LÃª a quantidade total de threads em execuÃ§Ã£o.

3. **ExibiÃ§Ã£o dos Resultados:**
   - printf(...): Imprime o ID individual de cada thread junto com o total geral de threads alocadas no ambiente.