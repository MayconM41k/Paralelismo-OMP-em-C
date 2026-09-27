# ExercÃ­cio 6: Inicializando com firstprivate

## ðŸ“Œ Conceito Principal
InicializaÃ§Ã£o de cÃ³pias privadas a partir do valor prÃ©-existente no cÃ³digo serial usando firstprivate.

---

## ðŸ’» CÃ³digo C (Limpo / Sem ComentÃ¡rios)

`c
#include <stdio.h>
#include <omp.h>

int main() {
    int multiplicador = 5;

    #pragma omp parallel firstprivate(multiplicador)
    {
        int id = omp_get_thread_num();
        int resultado = multiplicador;

        resultado = resultado * (id + 1);

        printf("Thread %d: resultado = %d\n", id, resultado);
    }

    return 0;
}

`

---

### Como o CÃ³digo Funciona

1. **VariÃ¡vel Serial Original:**
   - int multiplicador = 5;: Declarada e inicializada no escopo principal.

2. **ClÃ¡usula irstprivate(multiplicador):**
   - #pragma omp parallel firstprivate(multiplicador) cria uma cÃ³pia privada de multiplicador para cada thread, porÃ©m **copiando o valor inicial 5** que a variÃ¡vel tinha antes de entrar no bloco paralelo.

3. **CÃ¡lculo Local:**
   - esultado = resultado * (id + 1);: Cada thread realiza a operaÃ§Ã£o baseando-se no valor herdado (5) multiplicado pelo seu ID ajustado.