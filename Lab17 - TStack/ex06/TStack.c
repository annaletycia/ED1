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

int stack_print(TStack *st)
{
    if(st == NULL)
        return INVALID_NULL_POINTER;
    
    for(int i=0; i<st->qtd; i++){
        printf("\n%c ", st->data[i]);
    }
    return SUCCESS;
}

char *InfixToPostfix(TStack *st, char *infix)
{
    if(st == NULL)
        return NULL;
    int n = strlen(infix);
    char *postfix = malloc((n+1)*sizeof(char));
    stack_push(st,infix[0]); //empilha '('
    int j = 0;
    for(int i=1; infix[i] != '\0'; i++){ //percorre a infixa
        char c;
        switch(infix[i])
        {
            case '(': stack_push(st,infix[i]);
                      break;
            case ')': stack_top(st,&c);
                      while(c != '('){
                          postfix[j] = c;
                          j++;
                          stack_pop(st);
                          stack_top(st,&c);
                      }
                      stack_pop(st);
                      break;
            case '+':
            case '-': stack_top(st, &c);
                      while(c != '('){
                          postfix[j] = c;
                          j++;
                          stack_pop(st);
                          stack_top(st,&c);
                      }
                      stack_push(st,infix[i]);
                      break;
            case '*':
            case '/': stack_top(st,&c);
                      while(c != '(' && c != '+' && c != '-'){
                          postfix[j] = c;
                          j++;
                          stack_pop(st);
                          stack_top(st,&c);
                      }
                      stack_push(st,infix[i]);
                      break;
            default: postfix[j] = infix[i];
                     j++;
        }
    }
    postfix[j] = '\0';
    return postfix;
}