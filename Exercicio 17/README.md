# ExercÃ­cio 17: SincronizaÃ§Ã£o com barrier

## ðŸ“Œ Conceito Principal
SincronizaÃ§Ã£o de fases de execuÃ§Ã£o paralelas utilizando pontos de barreira (#pragma omp barrier).

---

## ðŸ’» CÃ³digo C (Limpo / Sem ComentÃ¡rios)

`c
#include <stdio.h>
#include <omp.h>

int valores_parciais[16];

int main() {
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        int total = omp_get_num_threads();

        valores_parciais[id] = (id + 1) * 10;
        printf("Thread %d [Fase 1]: valor parcial = %d\n", id, valores_parciais[id]);

        #pragma omp barrier

        int soma = 0;
        for (int i = 0; i < total; i++) {
            soma += valores_parciais[i];
        }
        printf("Thread %d [Fase 2]: soma de todas as parciais = %d\n", id, soma);
    }

    return 0;
}

`

---

### Como o CÃ³digo Funciona

1. **Fase 1 (CÃ¡lculo Parcial):**
   - Cada thread calcula seu valor parcial e armazena na sua posiÃ§Ã£o da matriz compartilhada alores_parciais[id].

2. **Ponto de Barreira (#pragma omp barrier):**
   - ForÃ§a todas as threads a aguardarem na barreira atÃ© que todas as threads tenham concluÃ­do a Fase 1.

3. **Fase 2 (Processamento Global):**
   - ApÃ³s ultrapassar a barreira, cada thread pode ler com seguranÃ§a os valores calculados por todas as outras threads na Fase 1, garantindo que nÃ£o haverÃ¡ leitura de dados incompletos.