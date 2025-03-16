#include "sequecia.h"
#include <stdlib.h>
#include <time.h>
typedef struct tarefa_item{
    sequencia *seq_id;
    __time_t data; 
    int prioridade;
    struct tarefa_item *prox;
}tarefa;

typedef struct{
    tarefa *item;
}list_tarefa;

list_tarefa *inicializar_list_tarefa();
void inserir_ordenado_data(list_tarefa *list, tarefa *item);
void inserir_tarefa_prioritaria(list_tarefa *list_t, int prioridade, char *vet_id_tarefa);
void mostrar_tarefa_normal(list_tarefa *list_t, int prioridade);
void completar_tarefa(list_tarefa *list_t,char *vet_tarefa);
void limpar_list_tarefa(list_tarefa *list_t);
