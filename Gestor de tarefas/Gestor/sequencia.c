#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sequecia.h"
sequencia *inicializar_sequencia(){
    sequencia *seq=(sequencia*)malloc(sizeof(sequencia));
    seq->item=NULL;
    return seq;
}
void priencher_sequencia(sequencia *seq, char *vet_seq) {
    int i = 0;
    if (seq->item == NULL) {
        sequecia_iitem *item = (sequecia_iitem *)malloc(sizeof(sequecia_iitem));
        item->c = vet_seq[i];
        item->prox = NULL;
        seq->item = item;   
        i++;
    }
    sequecia_iitem *ultimo = seq->item;
    while (ultimo->prox != NULL) {
        ultimo = ultimo->prox;
    }
    for (; i < strlen(vet_seq); i++) {
        sequecia_iitem *item = (sequecia_iitem *)malloc(sizeof(sequecia_iitem));
        item->c = vet_seq[i];
        item->prox = NULL;
        ultimo->prox = item;
        ultimo = item; 
    }

}

void limpar_sequencia(sequencia *seq){
    sequecia_iitem *item=seq->item;
    while(item){
        sequecia_iitem *actual= item;
        item=item->prox;
        free(actual);
    }
    free(seq);
}
int count_seq(sequencia *seq){
    int el=0;
    if(seq!=NULL){
        sequecia_iitem *item=seq->item;
        while(item!=NULL){
            el++;
            item=item->prox;
        }
    }
    return el;
    
}
int equals_seq(sequencia *seq_1,sequencia *seq_2){
    int size_seq_1=count_seq(seq_1);
    int size_seq_2=count_seq(seq_2);
    if(size_seq_1!=size_seq_2){
        return 0;
    }
    sequecia_iitem *item1=seq_1->item;
    sequecia_iitem *item2=seq_2->item;
    while(item1){
     if(item1->c!=item2->c){
        return 0;
     }
     item1=item1->prox;
     item2=item2->prox;
    }
    return 1;
}
void mostrar_seq(sequencia *seq){
    sequecia_iitem *item=seq->item;
    while(item!=NULL){
        printf("%c",item->c);
        item=item->prox;
    }
}
