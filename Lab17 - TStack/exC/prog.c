#include <stdio.h>
#include <stdlib.h>
#include "TStack.h"

int main(){
        TStack *st;
        char ch;
        int size;

        printf("Digite o tamanho da pilha: ");
        scanf("%d", &size);
        
        st = stack_create(size);
        if (st == NULL){
        printf("ERRO!");
        }
        
        for(int i = 0; i<size; i++){
        printf("\nDigite o caractere %d que deseja inserir na pilha: ", i+1);
        scanf(" %c", &ch);
        stack_push(st, ch);
        printf("%c inserido ", ch);
        }

        stack_print(st);

        stack_pop(st);
        stack_print(st);
    }