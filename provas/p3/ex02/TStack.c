#include <stdio.h>
#include <stdlib.h>
#include "TStack.h"
#include "TLinkedList.h"

struct TStack{
    TLinkedList *list;
};

TStack *stack_create()
{
    TStack *st = malloc(sizeof(TStack));
        if(st != NULL){
            st->list = list_create();
            if(st->list == NULL){
                free(st);
                return NULL;
            }
        }
    return st;
}

int stack_free(TStack *st)
{
    if(st == NULL)
        return INVALID_NULL_POINTER;
    list_free(st->list);
    free(st);
    return SUCCESS;
}

int stack_push(TStack *st, struct aluno al)
{
    if(st == NULL)
        return INVALID_NULL_POINTER;
    
    return list_push_front(st->list, al);
}

int stack_pop(TStack *st)
{
    if(st == NULL)
        return INVALID_NULL_POINTER;
    
    return list_pop_front(st->list);
}

int stack_top(TStack *st, struct aluno *al)
{
    if(st == NULL)
        return INVALID_NULL_POINTER;
    
    return list_front(st->list, al);
}

// retorno 1: lista vazia
// retorno 0: lista não está vazia
int stack_empty(TStack *st)
{
    if(st == NULL)
        return INVALID_NULL_POINTER;
    
    if(list_size(st->list) == 0){
        return 1;
    }
    else 
        return 0;
}

int stack_print(TStack *st)
{
    if(st == NULL)
        return INVALID_NULL_POINTER;
    
    return list_print(st->list);
}

int stack_print_reverse(TStack *st)
{
    if(st == NULL)
        return INVALID_NULL_POINTER;
    
    return list_print_reverse(st->list);
}