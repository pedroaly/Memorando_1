/*
 * list.c - implementation of the integer list functions 
 */


#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "list.h"



list_t* lst_new()
{
   list_t *list;
   list = (list_t*) malloc(sizeof(list_t));
   list->first = NULL;
   return list;
}


void lst_destroy(list_t *list)
{
	struct lst_iitem *item, *nextitem;

	item = list->first;
	while (item != NULL){
		nextitem = item->next;
		free(item);
		item = nextitem;
	}
	free(list);
}
int idade;
void insert_new_process(list_t *list, int pid, time_t starttime)
{
	lst_iitem_t *item;

	item = (lst_iitem_t *) malloc (sizeof(lst_iitem_t));
	item->pid = pid;
	item->starttime = starttime;
	item->endtime = 0;
	item->next = list->first;
	list->first = item;
}


void update_terminated_process(list_t *list, int pid, time_t endtime)
{
	lst_iitem_t *item=list->first;
	while(item!=NULL){
		if(item->pid==pid){
			item->endtime=endtime;
		}
		item=item->next;
	}
  
}

void lst_print(list_t *list)
{
	lst_iitem_t *item;

	printf("Process list with start and end time:\n");
	item = list->first;
	/* while(1){ */ /* use it only to demonstrate gdb potencial */
	while (item != NULL){
		printf("PID  Inicio: %d\t%s", item->pid, ctime(&(item->starttime)));
		printf("PID Fim \t: %s", ctime(&(item->endtime)));
		item = item->next;
	}
	printf("-- end of list.\n");
}
