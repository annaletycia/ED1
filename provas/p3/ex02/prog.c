#include <stdio.h>
#include <string.h>
#include "TStack.h"

int main()
{   
    struct aluno a, b, c ,d;
    strcpy(a.nome,"Joao");
    a.matricula = 1;
    a.n1 = 0;    a.n2 = 2;    a.n3 = 0;

    strcpy(b.nome,"Maria");
    b.matricula = 2;
    b.n1 = 2;    b.n2 = 0;    b.n3 = 0;

    strcpy(c.nome,"Jose");
    c.matricula = 3;
    c.n1 = 0;    c.n2 = 0;    c.n3 = 4;

    strcpy(d.nome,"Ana");
    d.matricula = 4;
    d.n1 = 0;    d.n2 = 0;    d.n3 = 2;

    TStack *st;
    st = stack_create();
    printf("\nStack criada\n");

    stack_push(st, a); // <a>
    stack_push(st, b); // <b,a>
    stack_push(st, c); // <c,b,a>
    stack_push(st, d); // <d,c,b,a>
    printf("\nElementos inseridos\n");

    stack_print(st);
    if(stack_print_reverse(st) != 0){
        printf("ERRO!");
    }

    stack_free(st);
    st = NULL;
    return 0;
}