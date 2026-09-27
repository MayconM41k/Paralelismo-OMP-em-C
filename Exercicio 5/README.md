# ExercÃ­cio 5: Isolando com private

## ðŸ“Œ Conceito Principal
Isolamento de dados e eliminaÃ§Ã£o de condiÃ§Ãµes de corrida utilizando a clÃ¡usula private.

---

## ðŸ’» CÃ³digo C (Limpo / Sem ComentÃ¡rios)

`c
#include <stdio.h>
#include <omp.h>

int main() {
    int contador_privado;

    #pragma omp parallel private(contador_privado)
    {
        int id = omp_get_thread_num();

        contador_privado = 0;
        for (int i = 0; i < 100; i++) {
            contador_privado++;
        }

        printf("Thread %d: contador = %d\n", id, contador_privado);
    }

    return 0;
}

`

---

### Como o CÃ³digo Funciona

1. **ClÃ¡usula private(contador_privado):**
   - #pragma omp parallel private(contador_privado) cria uma nova cÃ³pia independente de contador_privado na pilha (*stack*) de cada thread.

2. **InicializaÃ§Ã£o Local:**
   - contador_privado = 0;: Como variÃ¡veis private surgem sem inicializaÃ§Ã£o dentro da regiÃ£o paralela, cada thread inicializa explicitamente sua cÃ³pia local.

3. **ExecuÃ§Ã£o Segura:**
   - O incremento contador_privado++ modifica apenas a memÃ³ria privada da prÃ³pria thread, garantindo que todas contem exatamente 100 iteraÃ§Ãµes sem interferÃªncia mÃºtua.