#include <stdio.h>

double Fatorial(double num)
{   
    double fat;

   if(num == 0){
        fat = 1;
    }
    else{
        for(fat=1; num>1; num--){
        fat = fat * num;
        }
    }
        return fat;
}

void DesenhaLinha(int tam)
{   
    for(int i=0; i<tam; i++)
    {
       printf("=");
    }  
}

int main(){

    double num, tam, fat;
    int i=0;

    printf("Digite o tamanho da linha: ");
    scanf("%lf", &tam);
    printf("Digite o numero que deseja calcular o fatorial: ");
    scanf("%lf", &num);

    fat = Fatorial(num);

    DesenhaLinha(tam);
    printf("\nO fatorial de %lf eh %.0f\n", num, fat);
    DesenhaLinha(tam);

    return 0;
}

/*
=> Faça uma função para calcular o fatorial de um número. Use essa função
para calcular o fatorial de um número que o usuário digitar.
Colocar todas as funções E/S (entrada e saída) no programa principal.
(use também a função DesenhaLinha – esta pode conter comandos de saída fora do programa principal). 

Ex: Fatorial(5) tem como saída 120 
    DesenhaLinha(10) tem  como saída ==========

No programa principal, solicite ao usuário o tamanho da linha a ser desenhada e o número que se
deseja calcular o fatorial.

-------------------------------------------------------------------------------
Exemplo de Saída:

Digite o tamanho da linha: 10
Digite o numero que deseja calcular o fatorial: 5
==========
O fatorial de 5 eh 120
==========
-------------------------------------------------------------------------------
*/