#include <stdio.h>
#include "TStack.h"
#include <string.h>

int main()
{
    TStack *st;
    st = stack_create();

    char *inf; 
    strcpy(inf, "(A+B*C)");
    //strcpy(inf, "(A*(B*C+D))");
    //strcpy(inf, "(A*(((B+C)*(D*E))+F))");
    printf("Expressao infixa: %s\n", inf);

    char *post;
    post = InfixToPostfix(st, inf);
    printf("Expressao posfixa: %s\n", post);
    //gcc -o prog.exe prog.c TStack.c
    return 0;
}