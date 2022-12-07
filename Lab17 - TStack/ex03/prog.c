#include <stdio.h>
#include <string.h>
#include "TStack.h"

int main(){

    int tamanho;
    printf("Insira o tamanho maximo da pilha: ");
    scanf("%d", &tamanho);
    char elem[4];
    elem[0] = 'u';
    elem[1] = 'f';
    elem[2] = 'a';
    elem[3] = 'a';

    TStack *st;
    st = stack_create(tamanho);
    printf("\nLista criada\n");

    for(int i = 0; i<4; i++){
    stack_push(st, elem[i]);
    }
    printf("\nElementos inseridos\n");

    stack_print(st);

   // stack_pop(st);
    //stack_print(st);
    printf("\nTamanho da pilha: %d\n", stack_size(st));

    if(stack_full(st) == 1)
        printf("\nLista cheia\n");
    else
        printf("\nLista nao esta cheia\n");
    if(stack_empty(st) == 1)
        printf("\nLista vazia\n");
    else    
        printf("\nLista nao esta vazia\n");
    
    char topo;
    stack_top(st, &topo);
    printf("\nO elemento do topo eh: %c\n", topo);

    stack_free(st);
    st = NULL;
    return 0;
}