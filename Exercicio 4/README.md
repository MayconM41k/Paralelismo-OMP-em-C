# ExercÃ­cio 4: Race Condition com shared

## ðŸ“Œ Conceito Principal
DemonstraÃ§Ã£o de condiÃ§Ã£o de corrida (Race Condition) com variÃ¡veis compartilhadas (shared).

---

## ðŸ’» CÃ³digo C (Limpo / Sem ComentÃ¡rios)

`c
#include <stdio.h>
#include <omp.h>

int main() {
    int contador = 0;

    #pragma omp parallel shared(contador)
    {
        for (int i = 0; i < 100; i++) {
            contador++;
        }
    }

    printf("Valor final de contador: %d\n", contador);

    return 0;
}

`

---

### Como o CÃ³digo Funciona

1. **DeclaraÃ§Ã£o da VariÃ¡vel Compartilhada:**
   - int contador = 0;: VariÃ¡vel alocada na memÃ³ria principal antes da regiÃ£o paralela.

2. **ClÃ¡usula shared(contador):**
   - #pragma omp parallel shared(contador) indica que todas as threads apontam para o mesmo endereÃ§o de memÃ³ria de contador.

3. **CondiÃ§Ã£o de Corrida (contador++):**
   - Dentro do loop, cada thread tenta incrementar contador 100 vezes.
   - A operaÃ§Ã£o contador++ nÃ£o Ã© atÃ´mica (envolve leitura, modificaÃ§Ã£o e escrita). Quando mÃºltiplas threads tentam alterar a memÃ³ria simultaneamente sem sincronizaÃ§Ã£o, ocorrem sobreescritas de dados, gerando um resultado final inconsistente.