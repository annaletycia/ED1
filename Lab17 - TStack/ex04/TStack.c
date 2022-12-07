#include "TStack.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define N 100

struct TStack{
    char data[N];
    int qtd;
};

TStack *stack_create()
{
    TStack *st;
    st = malloc(sizeof(TStack));
    if(st == NULL)
        return NULL;
    //st->data = malloc(N * sizeof(char));
    st->qtd = 0;
    return st;
}

int stack_push(TStack *st, char s) //empilha
{   
    if(st == NULL)
        return INVALID_NULL_POINTER;

        int pos = st->qtd;
        st->data[pos] = s;
        st->qtd++;

    return SUCCESS; 
}

int stack_pop(TStack *st) //desempilha
{
    if(st == NULL)
        return INVALID_NULL_POINTER;

    st->qtd--;
        return SUCCESS;
}

int stack_top(TStack *st,char *top)
{
    if(st == NULL)
        return INVALID_NULL_POINTER;
    
    int pos = st->qtd - 1;
    *top = st->data[pos];
    return SUCCESS;
}

int stack_empty(TStack *st)
{
    if(st == NULL)
        return INVALID_NULL_POINTER;

    return st->qtd==0;
}

int stack_size(TStack *st)
{
    if(st==NULL)
        return INVALID_NULL_POINTER;
    return st->qtd;
}

int bemFormada(TStack *st, char s[])
{
    if(st == NULL)
        return INVALID_NULL_POINTER;

    for(int i=0; s[i] != '\0'; i++){
        char c;
        switch(s[i])
        {
            case ')': if(stack_empty(st)) return 0;
                      stack_top(st, &c);
                      if(c != '(') return 0;
                      stack_pop(st);
                      break;
            case ']': if(stack_empty(st)) return 0;
                      stack_top(st, &c);
                      if(c != '[') return 0;
                      stack_pop(st);
                      break;
            default: stack_push(st, s[i]);
        }
    }
    return stack_empty(st);
}


int stack_print(TStack *st)
{
    if(st == NULL)
        return INVALID_NULL_POINTER;
    
    for(int i=0; i<st->qtd; i++){
        printf("\n%c ", st->data[i]);
    }
    return SUCCESS;
}