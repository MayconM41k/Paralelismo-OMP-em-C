# ExercÃ­cio 2: A Thread Mestre

## ðŸ“Œ Conceito Principal
DiferenciaÃ§Ã£o do comportamento da thread mestre (ID 0) das demais threads trabalhadoras.

---

## ðŸ’» CÃ³digo C (Limpo / Sem ComentÃ¡rios)

`c
#include <stdio.h>
#include <omp.h>

int main() {
    #pragma omp parallel
    {
        int id = omp_get_thread_num();

        if (id == 0) {
            printf("Sou a thread MESTRE!\n");
        } else {
            printf("Sou uma thread trabalhadora.\n");
        }
    }

    return 0;
}

`

---

### Como o CÃ³digo Funciona

1. **RegiÃ£o Paralela (#pragma omp parallel):**
   - Cria o grupo de threads paralelas para execuÃ§Ã£o simultÃ¢nea do bloco.

2. **IdentificaÃ§Ã£o da Thread Mestre (if (id == 0)):**
   - A funÃ§Ã£o omp_get_thread_num() obtÃ©m o ID da thread atual.
   - A estrutura condicional if (id == 0) garante que somente a thread com ID 0 (thread mestre) execute o bloco do if e imprima "Sou a thread MESTRE!".
   - As demais threads (id > 0) entram no bloco else e imprimem "Sou uma thread trabalhadora.".