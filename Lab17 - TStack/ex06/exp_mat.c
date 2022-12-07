#include <stdio.h>
#include <string.h>
#include "TStack.h"

int main()
{
    char equacao[101];
    float valores[26];
    float num;
    char c; 

    printf("Digite a expressao (maximo 100 caracteres) entre parenteses: ");
    fgets(equacao,100,stdin);
    equacao[strcspn(equacao, "\n")] = '\0'; //substitui o \n da equacao pelo \0, indicando o fim da string
    //encontra a posicao do vetor [equacao] em que esta o '\n'

    printf("\nExpressao digitada:\n%s",equacao);

    for (int i = 0; i< strlen(equacao); i++) //percorre o vetor [equacao]
    {
        c = equacao[i];

        if (c == '+' || c == '-' || c == '*' || c == '/'){
            printf("\noperador: %c", c);
        } else if (c>=65 && c <= 90){ // testa se a letra é maior que A e menor que Z
            printf("\noperando: %c (%d)", c,c);
            printf("\nDigite o valor para %c = ",c);
            scanf("%f",&valores[c-65]); // letra A é mapeada na posição zero do vetor
        }

    }
    TStack *st;
    st = stack_create();
    char *post;
    post = InfixToPostfix(st, equacao);
    printf("\nExpressao posfixa: %s\n", post);
    

 /*  for(int k=0; post[k] != '\0'; k++)
   {    
       char num1, num2, op;
       switch(post[k]){
           case '+':
           case '-':
           case '/':
           case '*': stack_top(st, &num1);
                     stack_pop(st);
                     stack_top(st, &num2);
                     stack_pop(st);
                     num1 * num2 = op;
           default: stack_push()
       }
            
    }
*/
//gcc -o exp_mat.exe exp_mat.c TStack.c
//(A*(((B+C)*(D*E))+F))
    return 0;
}