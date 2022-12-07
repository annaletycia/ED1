#include <stdio.h>
#include "TStack.h"
#include <string.h>

int main()
{
    TStack *st;
    st = stack_create();

    char string[5]; // bem-formada
    string[0] = '[';
    string[1] = '(';
    string[2] = ')';
    string[3] = ']';
    if(bemFormada(st, string) == 1)
        printf("\nA sequencia eh bem-formada!");
    else
        printf("\nA sequencia eh mal-formada!");

    char seq[5]; // mal-formada
    seq[0] = '(';
    seq[1] = '[';
    seq[2] = ')';
    seq[3] = ']';

    if(bemFormada(st, seq) == 1)
        printf("\nA sequencia eh bem-formada!");
    else
        printf("\nA sequencia eh mal-formada!");
    //printf("\ntamanho da pilha: %d", stack_size(st));

    void fun(int n)
    {
        TStack *p = stack_create();
        while(n>0){
            stack_push(p, n%2);
            n = (int) n/2;
        }
        while(!stack_empty(p)){
            printf("%d", stack_pop(p))
        }
    }
    return 0;
}