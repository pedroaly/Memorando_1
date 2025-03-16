#include <stdlib.h>
#include <stdio.h>
#include "tarefa.h"
#include "sequecia.h"
#include <time.h>
list_tarefa *inicializar_list_tarefa(){
    list_tarefa *lst_t=(list_tarefa*)malloc(sizeof(list_tarefa));
    lst_t->item=NULL;
    return lst_t;
}
void inserir_tarefa_prioritaria(list_tarefa *list_t, int prioridade, char *vet_id_tarefa) {
   
    tarefa *item = (tarefa *)malloc(sizeof(tarefa));  
    item->prioridade = prioridade;
    item->seq_id = inicializar_sequencia();
    item->data=time(NULL);
    priencher_sequencia(item->seq_id, vet_id_tarefa);
    item->prox = NULL;
    if (list_t->item == NULL || list_t->item->prioridade < prioridade) {
        item->prox = list_t->item;
        list_t->item = item;
        return;
    }
    tarefa *iitem = list_t->item->prox;
    while (iitem != NULL) {
        if(equals_seq( item->seq_id,iitem->seq_id)){
            printf("Tarefa Ja existe no gestor como um ID");
            free(item);
            return;
        }
        iitem=iitem->prox;
    }
    tarefa *anterior = list_t->item;
    tarefa *actual = list_t->item->prox;

    while (actual != NULL && actual->prioridade >= prioridade) {
        anterior = actual;
        actual = actual->prox;
    }

    anterior->prox = item;
    item->prox = actual;
}


void inserir_ordenado_data(list_tarefa *list, tarefa *item) {
    if (list->item == NULL || difftime(list->item->data, item->data) > 0) {
        item->prox = list->item;
        list->item = item;
        return;
    }

    tarefa *anterior = list->item;
    tarefa *atual = list->item->prox;

    while (atual != NULL && difftime(atual->data, item->data) <= 0) {
        anterior = atual;
        atual = atual->prox;
    }

    anterior->prox = item;
    item->prox = atual;
}
void mostrar_tarefa_normal(list_tarefa *list_t, int prioridade) {
    list_tarefa *listas[6];
    for (int i = 0; i < 6; i++) {
        listas[i] = inicializar_list_tarefa();
    }

    tarefa *actual = list_t->item;
    while (actual != NULL) {
        if (actual->prioridade >= prioridade) {
            tarefa *nova_tarefa = (tarefa *)malloc(sizeof(tarefa));
            *nova_tarefa = *actual;
            nova_tarefa->prox = NULL;
            inserir_ordenado_data(listas[actual->prioridade], nova_tarefa);
        }
        actual = actual->prox;
    }
    for (int i = 5; i >= 0; i--) {
        if (listas[i]->item != NULL) {
            printf("Prioridade %d:\n", i);
            tarefa *item = listas[i]->item;
            while (item != NULL) {
                printf("ID: ");
                mostrar_seq(item->seq_id);
                printf(" | Data: %s", ctime(&item->data));
                item = item->prox;
            }
            printf("\n");
        }
    }

    for (int i = 0; i < 6; i++) {
        limpar_list_tarefa(listas[i]);
    }
}
void limpar_list_tarefa(list_tarefa *list_t){
    if(list_t->item!=NULL){
        tarefa *item=list_t->item;
        while(item){
            tarefa *ante=item;
            item=item->prox;
            free(ante);
        }  
    }
    free(list_t);    
}
void completar_tarefa(list_tarefa *list_t, char *vet_tarefa) {
    sequencia *seq_tarefa = inicializar_sequencia();
    priencher_sequencia(seq_tarefa, vet_tarefa);

    if (equals_seq(seq_tarefa, list_t->item->seq_id)) {
        tarefa *remover = list_t->item;
        list_t->item = list_t->item->prox;
        limpar_sequencia(remover->seq_id);
        free(remover);
        limpar_sequencia(seq_tarefa);
        return;
    }

    tarefa *ante = list_t->item;
    tarefa *item = list_t->item->prox;

    while (item != NULL && !equals_seq(seq_tarefa, item->seq_id)) {
        ante = item;
        item = item->prox;
    }
    if (item != NULL) {
        ante->prox = item->prox;
        limpar_sequencia(item->seq_id);
        free(item);
        limpar_sequencia(seq_tarefa);
    } else {
        printf("TAREFA INEXISTENTE");
        limpar_sequencia(seq_tarefa);
    }
}
