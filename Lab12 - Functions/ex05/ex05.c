#include <stdio.h>
#include <math.h>

int QuadradoPerfeito(int x)
{
    int flag = 1;
        if(x % 2 == 0){
            if(x % 4 != 0)
            flag = 0;
        }else{
            if(x % 8 !=1){
                flag = 0;
            }
        }
return flag;
}

int main()
{
    int num;
    printf("<<<Quadrado Perfeito>>>\n");
    printf("Digite um numero: ");
    scanf("%d", &num);

    if(QuadradoPerfeito(num)){
        printf("O numero %d eh um quadrado perfeito!\n", num);
    }else{
        printf("O numero %d nao eh um quadrado perfeito!\n", num);
    }

    return 0;
}

/*
=> Faça uma função para verificar se um número 
é um quadrado perfeito (retorne Verdadeiro caso seja).   

Ex: QuadradoPerfeito(4) retorna verdadeiro; 
    QuadradoPerfeito(10) retorna falso; 

obs: Pode-se retornar os valores 0 (para verdadeiro) e 1 (para falso).

No programa principal, solicite ao usuário o valor de n.

-------------------------------------------------------------------------------
Exemplo de Saída 1:

Digite o valor de n: 4
O numero 4 eh um quadrado perfeito
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
Exemplo de Saída 2:

Digite o valor de n: 10
O numero 10 não eh um quadrado perfeito
-------------------------------------------------------------------------------
*/