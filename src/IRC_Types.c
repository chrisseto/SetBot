#include "../headers/IRC_Types.h"

void create_list(List *n, int initsize)
{
	n->size = initsize;
	n->used = 0;
	n->array = (char **)malloc(initsize * sizeof(char *));
}

void add_element(List *list, char *handle)
{
	if(list->size == list->used)
	{
		list->size++;
		list->array = (char **)realloc(list->array,list->size*sizeof(char *));
	}
	list->array[list->used++] = handle;
}

void remove_element(List *list, char *handle)
{
	
}

int list_contains(List *list, char *search)
{
	
}
