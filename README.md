# Lista de Exercícios - OpenMP em C

Este repositório contém a solução completa para a **Lista de Exercícios – OpenMP – Prática de Comandos** (Disciplina de Tópicos em Computação de Alto Desempenho - Prof. Dr. Luiz Mário Lustosa Pascoal / Faculdade SENAI FATESG).

Todos os códigos em C foram **limpos (sem comentários)** e organizados em pastas individuais. Cada pasta possui o seu código fonte `.c` e o seu respectivo arquivo `README.md` explicando o funcionamento detalhado do programa.

---

## 📁 Estrutura do Repositório

| Pasta | Exercício | Diretiva / Conceito Principal |
| :--- | :--- | :--- |
| [`Exercicio 1`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%201/README.md) | Exercício 1: Olá, Mundo Paralelo! | `#pragma omp parallel`, `omp_get_thread_num()`, `omp_get_num_threads()` |
| [`Exercicio 2`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%202/README.md) | Exercício 2: A Thread Mestre | Identificação da thread mestre (ID 0) com `if` |
| [`Exercicio 3`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%203/README.md) | Exercício 3: Contando Threads | Leitura de ambiente e `omp_set_num_threads()` |
| [`Exercicio 4`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%204/README.md) | Exercício 4: Race Condition com shared | Demonstração prática de condição de corrida com variáveis `shared` |
| [`Exercicio 5`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%205/README.md) | Exercício 5: Isolando com private | Isolamento de variáveis privadas com `private` |
| [`Exercicio 6`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%206/README.md) | Exercício 6: Inicializando com firstprivate | Inicialização de cópia privada com valor pré-existente (`firstprivate`) |
| [`Exercicio 7`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%207/README.md) | Exercício 7: Combinando shared e private | Escopo explícito em particionamento de dados (`shared` vs `private`) |
| [`Exercicio 8`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%208/README.md) | Exercício 8: Boas Práticas com default(none) | Declaração mandatória de escopo usando `default(none)` |
| [`Exercicio 9`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%209/README.md) | Exercício 9: Distribuição Manual | Cálculo manual de `istart` e `iend` por thread |
| [`Exercicio 10`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%2010/README.md) | Exercício 10: Usando parallel for | Distribuição automática de loops com `#pragma omp parallel for` |
| [`Exercicio 11`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%2011/README.md) | Exercício 11: Soma de Vetores | Paralelização element-wise de grandes vetores |
| [`Exercicio 12`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%2012/README.md) | Exercício 12: Produto Escalar | Análise de Race Condition em acumuladores |
| [`Exercicio 13`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%2013/README.md) | Exercício 13: Preenchendo uma Matriz | Paralelização de loops aninhados no loop externo |
| [`Exercicio 14`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%2014/README.md) | Exercício 14: Comparando Estratégias de schedule | Medição de tempo com `static`, `dynamic` e `guided` |
| [`Exercicio 15`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%2015/README.md) | Exercício 15: Protegendo com critical | Proteção de seção crítica com `#pragma omp critical` |
| [`Exercicio 16`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%2016/README.md) | Exercício 16: Operações Atômicas com atomic | Comparação de performance entre `#pragma omp atomic` e `critical` |
| [`Exercicio 17`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%2017/README.md) | Exercício 17: Sincronização com barrier | Sincronização de fases com `#pragma omp barrier` |
| [`Exercicio 18`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%2018/README.md) | Exercício 18: Soma com reduction | Acumulação otimizada com `reduction(+:soma)` |
| [`Exercicio 19`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%2019/README.md) | Exercício 19: Máximo e Mínimo com reduction | Encontrar min e max com `reduction(min:menor)` e `reduction(max:maior)` |
| [`Exercicio 20`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%2020/README.md) | Exercício 20: Tarefas Independentes com sections | Paralelismo de tarefas com `#pragma omp sections` |
| [`Exercicio 21`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%2021/README.md) | Exercício 21: Cálculo de Pi com reduction | Série de Leibniz paralela e medição de Speedup |
| [`Exercicio 22`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%2022/README.md) | Exercício 22: Multiplicação Matriz-Vetor | Álgebra linear paralela e avaliação de escala |

---

## 📘 Explicação Detalhada do Funcionamento de Cada Código

### 🔹 Região Paralela e Identificação (Exercícios 1 a 3)
* **`#include <omp.h>`**: Inclui as declarações das funções da API de runtime do OpenMP.
* **`#pragma omp parallel`**: Cria um grupo de threads. Cada thread executa o bloco delimitado por `{ ... }` em paralelo.
* **`omp_get_thread_num()`**: Retorna o identificador numérico único (0 a N-1) da thread que está executando a instrução.
* **`omp_get_num_threads()`**: Consulta a quantidade total de threads alocadas na região paralela.
* **Controle da Mestre (`if (id == 0)`)**: Permite separar tarefas exclusivas da thread mestre das demais threads trabalhadoras.

### 🔹 Escopo de Dados e Condição de Corrida (Exercícios 4 a 8)
* **`shared(var)`**: A variável compartilha o mesmo endereço de memória entre todas as threads. Se múltiplas threads escreverem sem sincronização, ocorre **Race Condition**.
* **`private(var)`**: Cria uma cópia não inicializada da variável na pilha (*stack*) própria de cada thread, eliminando a disputa de memória.
* **`firstprivate(var)`**: Cria uma cópia privada para cada thread, mas **inicializa** a cópia com o valor que a variável possuía antes de entrar no bloco paralelo.
* **`default(none)`**: Desativa o escopo implícito e obriga o desenvolvedor a declarar explicitamente o escopo (`shared`, `private`, etc.) de todas as variáveis no bloco paralelo.

### 🔹 Paralelismo de Loops (Exercícios 9 a 14)
* **Particionamento Manual (`istart`/`iend`)**: Calcula matematicamente os limites do loop para cada thread com base no seu ID e no total de threads.
* **`#pragma omp parallel for`**: Automatiza a criação da região paralela e o particionamento das iterações do loop `for` entre as threads.
* **`schedule(static)`**: Divide as iterações em blocos de tamanho fixo antes da execução.
* **`schedule(dynamic, chunk)`**: Distribui os blocos de iterações em tempo de execução conforme as threads ficam ociosas.
* **`schedule(guided)`**: Inicia com blocos grandes de iterações e reduz o tamanho dos blocos exponencialmente à medida que a execução avança.

### 🔹 Sincronização e Proteção de Memória (Exercícios 15 a 17)
* **`#pragma omp critical`**: Cria uma seção crítica de exclusão mútua. Apenas **uma thread por vez** pode executar aquele bloco de código.
* **`#pragma omp atomic`**: Garante atualização atômica no nível de instrução do processador. Muito mais leve e eficiente que o `critical` para operações simples de incremento/atribuição.
* **`#pragma omp barrier`**: Ponto de barreira onde todas as threads devem aguardar até que todas tenham alcançado essa linha antes de prosseguir para a próxima fase.

### 🔹 Redução e Tarefas Independentes (Exercícios 18 a 22)
* **`reduction(operador:var)`**: Cria cópias locais privadas de `var` inicializadas com o elemento neutro do operador (ex: 0 para `+`, `INT_MIN` para `max`). Ao final do loop, o OpenMP combina todas as cópias locais na variável original de forma segura e paralela.
* **`#pragma omp sections` / `#pragma omp section`**: Permite definir blocos funcionais de código independentes para serem executados em paralelo por threads diferentes.
* **Medição com `omp_get_wtime()`**: Captura o tempo de execução em segundos com alta precisão para cálculo de aceleração (*speedup*).

---

## 🛠️ Como Compilar e Executar

### Compilando Todos os Exercícios no Windows
```cmd
.\compilar_todos.bat
```

### Compilando com Makefile (Linux / macOS / MSYS2)
```bash
make
```

### Executando um Exercício
Para definir o número de threads e executar qualquer um dos binários gerados:

```powershell
$env:OMP_NUM_THREADS=4
.\exercicio01.exe
```
