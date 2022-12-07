//Implemente o TAD Pilha utilizando alocação sequencial. Dica: muito código será semelhante ao de lista sequencial. 
//Ao invés de armazenar um aluno, cada elemento da pilha armazenará um caractere (tipo char). O tamanho máximo da pilha 
//deverá ser informado pelo usuário durante a criação da pilha (e esse tamanho não poderá ser alterado ao longo do tempo).

#include <stdlib.h>
#include <stdio.h>
#include "TStack.h"

struct TStack{
    char *data;
    int qtd;
    int MAX;
};

TStack *stack_create(int tamanho)
{
    TStack *st;
    st = malloc(sizeof(TStack));
    if (st != NULL){
        st->data = malloc(tamanho * sizeof(char));
        st->qtd = 0;
        st->MAX = tamanho;
        if (st->data == NULL){
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

    free(st->data);
    free(st);
    return SUCCESS; 
}

int stack_size(TStack *st)
{
    if(st == NULL)
        return INVALID_NULL_POINTER;
    
    return (st->qtd);
}

int stack_push(TStack *st, char elem)
{
    if (st == NULL)
        return INVALID_NULL_POINTER;
    if(st->qtd == st->MAX)
        return OUT_OF_MEMORY;

    st->data[st->qtd] = elem;
    st->qtd++;
    return SUCCESS;
}

int stack_pop(TStack *st)
{
    if(st == NULL)
        return INVALID_NULL_POINTER;
    
    st->qtd--;
}

int stack_top(TStack *st,char *top)
{
    if(st == NULL)
        return INVALID_NULL_POINTER;

    int i = (st->qtd) - 1;
    *top = st->data[i];
    return SUCCESS;
}

int stack_empty(TStack *st)
{
    if(st == NULL)
        return INVALID_NULL_POINTER;
    
    return (st->qtd == 0);
}

int stack_full(TStack *st)
{
    if(st == NULL)
        return INVALID_NULL_POINTER;
    
    return (st->qtd == st->MAX);
}

int stack_print(TStack *st)
{
    if(st == NULL)
        return INVALID_NULL_POINTER;
    
    for(int i=0; i<st->qtd; i++){
        printf("%c ", st->data[i]);
    }
    return SUCCESS;
}