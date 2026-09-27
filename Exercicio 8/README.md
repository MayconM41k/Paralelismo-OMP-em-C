# ExercÃ­cio 8: Boas PrÃ¡ticas com default(none)

## ðŸ“Œ Conceito Principal
Enforcement de declaraÃ§Ã£o explÃ­cita de escopo de dados usando a clÃ¡usula default(none).

---

## ðŸ’» CÃ³digo C (Limpo / Sem ComentÃ¡rios)

`c
#include <stdio.h>
#include <omp.h>

int dados[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int main() {
    int soma_local;

    #pragma omp parallel default(none) shared(dados) private(soma_local)
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

1. **ClÃ¡usula default(none):**
   - Desativa o escopo padrÃ£o implÃ­cito do OpenMP.
   - Obriga o programador a declarar explicitamente o escopo (shared, private, etc.) de **todas** as variÃ¡veis externas usadas dentro do bloco paralelo.

2. **DeclaraÃ§Ã£o Explicita de Escopos:**
   - shared(dados): Define que o vetor Ã© compartilhado.
   - private(soma_local): Defines que a variÃ¡vel de soma Ã© privada para cada thread.

3. **Vantagem de Engenharia:**
   - Evita bugs sutis de compartilhamento indevido de memÃ³ria causados por regras padrÃ£o implÃ­citas.