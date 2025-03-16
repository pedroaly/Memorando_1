#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
typedef struct sequecia_item{
    char c;
    struct sequecia_item *prox;
}sequecia_iitem;

typedef struct{
    sequecia_iitem *item;
}sequencia;

sequencia *inicializar_sequencia();

void priencher_sequencia(sequencia *seq,char *vet_seq);
void limpar_sequencia(sequencia *seq);
int equals_seq(sequencia *seq_1,sequencia *seq_2);
int count_seq(sequencia *seq);
void mostrar_seq(sequencia *seq);

 #endif
