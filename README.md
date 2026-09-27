# Lista de Exercícios - OpenMP em C

Este repositório contém a solução completa para a **Lista de Exercícios – OpenMP – Prática de Comandos** (Disciplina de Tópicos em Computação de Alto Desempenho - Prof. Dr. Luiz Mário Lustosa Pascoal / Faculdade SENAI FATESG).

---

## 📁 Estrutura de Pastas e Arquivos

Cada exercício possui sua própria pasta dedicada (`Exercicio 1`, `Exercicio 2`, ..., `Exercicio 22`), bem como os fontes `.c` individuais e independentes:

| Arquivo | Exercício | Diretiva / Conceito Principal |
| :--- | :--- | :--- |
| [`Exercicio 1/exercicio01.c`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%201/exercicio01.c) | Exercício 1: Olá, Mundo Paralelo! | `#pragma omp parallel`, `omp_get_thread_num()`, `omp_get_num_threads()` |
| [`Exercicio 2/exercicio02.c`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%202/exercicio02.c) | Exercício 2: A Thread Mestre | Identificação da thread mestre (ID 0) com `if` |
| [`Exercicio 3/exercicio03.c`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%203/exercicio03.c) | Exercício 3: Contando Threads | Leitura de ambiente e `omp_set_num_threads()` |
| [`Exercicio 4/exercicio04.c`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%204/exercicio04.c) | Exercício 4: Race Condition com shared | Demonstração prática de condição de corrida com variáveis `shared` |
| [`Exercicio 5/exercicio05.c`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%205/exercicio05.c) | Exercício 5: Isolando com private | Isolamento de variáveis privadas com `private` |
| [`Exercicio 6/exercicio06.c`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%206/exercicio06.c) | Exercício 6: Inicializando com firstprivate | Inicialização de cópia privada com valor pré-existente (`firstprivate`) |
| [`Exercicio 7/exercicio07.c`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%207/exercicio07.c) | Exercício 7: Combinando shared e private | Escopo explícito em particionamento de dados (`shared` vs `private`) |
| [`Exercicio 8/exercicio08.c`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%208/exercicio08.c) | Exercício 8: Boas Práticas com default(none) | Declaração mandatória de escopo usando `default(none)` |
| [`Exercicio 9/exercicio09.c`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%209/exercicio09.c) | Exercício 9: Distribuição Manual | Cálculo manual de `istart` e `iend` por thread |
| [`Exercicio 10/exercicio10.c`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%2010/exercicio10.c) | Exercício 10: Usando parallel for | Distribuição automática de loops com `#pragma omp parallel for` |
| [`Exercicio 11/exercicio11.c`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%2011/exercicio11.c) | Exercício 11: Soma de Vetores | Paralelização element-wise de grandes vetores |
| [`Exercicio 12/exercicio12.c`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%2012/exercicio12.c) | Exercício 12: Produto Escalar | Análise de Race Condition em acumuladores |
| [`Exercicio 13/exercicio13.c`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%2013/exercicio13.c) | Exercício 13: Preenchendo uma Matriz | Paralelização de loops aninhados no loop externo |
| [`Exercicio 14/exercicio14.c`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%2014/exercicio14.c) | Exercício 14: Comparando Estratégias de schedule | Medição de tempo com `static`, `dynamic` e `guided` |
| [`Exercicio 15/exercicio15.c`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%2015/exercicio15.c) | Exercício 15: Protegendo com critical | Proteção de seção crítica com `#pragma omp critical` |
| [`Exercicio 16/exercicio16.c`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%2016/exercicio16.c) | Exercício 16: Operações Atômicas com atomic | Comparação de performance entre `#pragma omp atomic` e `critical` |
| [`Exercicio 17/exercicio17.c`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%2017/exercicio17.c) | Exercício 17: Sincronização com barrier | Sincronização de fases com `#pragma omp barrier` |
| [`Exercicio 18/exercicio18.c`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%2018/exercicio18.c) | Exercício 18: Soma com reduction | Acumulação otimizada com `reduction(+:soma)` |
| [`Exercicio 19/exercicio19.c`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%2019/exercicio19.c) | Exercício 19: Máximo e Mínimo com reduction | Encontrar min e max com `reduction(min:menor)` e `reduction(max:maior)` |
| [`Exercicio 20/exercicio20.c`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%2020/exercicio20.c) | Exercício 20: Tarefas Independentes com sections | Paralelismo de tarefas com `#pragma omp sections` |
| [`Exercicio 21/exercicio21.c`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%2021/exercicio21.c) | Exercício 21: Cálculo de Pi com reduction | Série de Leibniz paralela e medição de Speedup |
| [`Exercicio 22/exercicio22.c`](file:///c:/Users/Maycon/Downloads/ParalelismoOMPemC/Exercicio%2022/exercicio22.c) | Exercício 22: Multiplicação Matriz-Vetor | Álgebra linear paralela e avaliação de escala |

---

## 🛠️ Como Compilar e Executar

### No Windows (MinGW / GCC)
Para compilar um exercício individual:
```cmd
gcc -fopenmp "Exercicio 1\exercicio01.c" -o exercicio01.exe
$env:OMP_NUM_THREADS=4; .\exercicio01.exe
```

Para compilar todos de uma vez:
```cmd
.\compilar_todos.bat
```

### No Linux / macOS
Para compilar com `make`:
```bash
make
OMP_NUM_THREADS=4 ./exercicio01
```
