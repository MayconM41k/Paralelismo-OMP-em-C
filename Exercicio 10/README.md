# ExercÃ­cio 10: Usando parallel for

## ðŸ“Œ Conceito Principal
ParalelizaÃ§Ã£o automÃ¡tica de loops for utilizando a diretiva combinada #pragma omp parallel for.

---

## ðŸ’» CÃ³digo C (Limpo / Sem ComentÃ¡rios)

`c
#include <stdio.h>
#include <omp.h>

int main() {
    int vetor[100];

    #pragma omp parallel for
    for (int i = 0; i < 100; i++) {
        vetor[i] = omp_get_thread_num();
    }

    printf("Vetor preenchido com parallel for:\n");
    for (int i = 0; i < 100; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}

`

---

### Como o CÃ³digo Funciona

1. **Diretiva #pragma omp parallel for:**
   - Combina a criaÃ§Ã£o da regiÃ£o paralela com a distribuiÃ§Ã£o automÃ¡tica das iteraÃ§Ãµes do loop or entre as threads.
   - A variÃ¡vel de controle do loop (int i) Ã© automaticamente tratada como private.

2. **AtribuiÃ§Ã£o Simples:**
   - etor[i] = omp_get_thread_num();: Cada iteraÃ§Ã£o atribui o ID da thread responsÃ¡vel por processÃ¡-la.

3. **ComparaÃ§Ã£o com o ExercÃ­cio 9:**
   - O cÃ³digo atinge o mesmo resultado do particionamento manual do ExercÃ­cio 9, mas com uma sintaxe muito mais limpa e legÃ­vel.