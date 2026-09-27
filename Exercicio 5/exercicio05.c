/*
 * Exercício 5: Isolando com private
 * Objetivo: Entender como private cria cópias isoladas para cada thread.
 * 
 * Tarefa: Modifique o Exercício 4. Declare uma variável contador_privado como private. 
 * Cada thread deve inicializá-la com 0, incrementá-la 100 vezes e imprimir 
 * "Thread <ID>: contador = <valor>". Observe que cada thread tem seu próprio valor.
 */

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
