#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tarefa.h"
#include "sequecia.h"

#define MAX_ARG 3

void quebrar_comando(char *linha, char **comando) {
    int i = 0;
    char *token = strtok(linha, " \n");
    while (token != NULL && i < MAX_ARG) {
        comando[i++] = token;
        token = strtok(NULL, " \n");
    }
    comando[i] = NULL;
}

int main() {
    list_tarefa *lista_tarefas = inicializar_list_tarefa();
    char *linha = NULL;
    size_t tamanho = 0;

    printf("$:");
    while (getline(&linha, &tamanho, stdin) != -1) {
        char *comando[MAX_ARG + 1];
        quebrar_comando(linha, comando);

        if (strcmp(comando[0], "new") == 0 && comando[1] && comando[2]) {
            int prioridade = atoi(comando[1]);
            if (prioridade >= 0 && prioridade <= 5) {
                inserir_tarefa_prioritaria(lista_tarefas, prioridade, comando[2]);
            } else {
                printf("Prioridade invalida. Use valores entre 0 e 5.\n");
            }
        } else if (strcmp(comando[0], "list") == 0 && comando[1]) {
            int prioridade = atoi(comando[1]);
            mostrar_tarefa_normal(lista_tarefas, prioridade);
        } else if (strcmp(comando[0], "complete") == 0 && comando[1]) {
            completar_tarefa(lista_tarefas, comando[1]);
        } else if (strcmp(comando[0], "exit") == 0) {
            break;
        } else {
            printf("Comando invalido. Use: new <prioridade> <id>, list <prioridade>, complete <id> ou exit.\n");
        }

        printf("$:");
    }

    free(linha);
    limpar_list_tarefa(lista_tarefas);
    return 0;
}

