#include <stdio.h>
#include <stdlib.h>
#include "TStack.h"

struct TStack{
    char *data;
    int sizemax;
    int qtd;
};

TStack *stack_create(int sizemax){
    TStack *st;
    st = malloc(sizeof(struct TStack));
    if (st == NULL){
        return st;
    } else{
        st->qtd = 0;
        st->sizemax = sizemax;
        st->data = malloc(sizeof(char)*sizemax);
        if(st->data == NULL){
            free(st);
            st = NULL;
        }
        return st;
        }
}

int stack_free(TStack *st)
{
    if (st == NULL)
        return INVALID_NULL_POINTER;
    free(st->data);
    free(st);
    return SUCCESS;
}

int stack_push(TStack *st, char dado)
{
    if(st==NULL){
        return INVALID_NULL_POINTER;
    }
    else 
    if((st->qtd) == st->sizemax){
        return OUT_OF_RANGE;
    }
    else{
        st->data[st->qtd] = dado;
        st->qtd++;
        return SUCCESS;
    }
}


int stack_pop(TStack *st)
{
    if (st == NULL)
        return INVALID_NULL_POINTER;
    st->qtd--;
    return SUCCESS;
}

int stack_top(TStack *st, char *dado)
{
    if (st == NULL)
        return INVALID_NULL_POINTER;
    *dado = st->data[(st->qtd)-1];
    return SUCCESS;
}


int stack_empty(TStack *st)
{
    if (st == NULL)
        return INVALID_NULL_POINTER;
    if (st->qtd == 0){
        return SUCCESS;
    }
}

int stack_full(TStack *st)
{
    if (st == NULL)
        return INVALID_NULL_POINTER;
    else{
    st->qtd == st->sizemax;
    return SUCCESS;
    }
}

int stack_print(TStack *st)
{
    if (st == NULL)
        return INVALID_NULL_POINTER;
        for(int i = 0; i<st->qtd; i++){
        printf("%c\n", st->data[i]);
        }
    return SUCCESS;
}