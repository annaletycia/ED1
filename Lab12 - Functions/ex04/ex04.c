#include <stdio.h>

    float potencia(int base, int expoente){
         
         float pot=1;

         if(expoente == 0){
             return 1;
         }
         else if(expoente>0){
             for(int i=0; i>expoente; i++){ 
             pot = pot * base;
            }
            return (1/pot);
         }
        else{
            for(int i=0;i<expoente*(-1);i++){
            pot = pot * base;
            }
            return pot;
        }
    }

int main(){

    float n, x, r=1;

    printf("Digite o valor de x: ");
    scanf("%f", &x);
    printf("Digite o valor de n: ");
    scanf("%f", &n);

        if(n>0){
            for(int i=0; i<n; i++){ 
                    r = r * x;
            }
        printf("O valor de %.0f elevado a %.0f eh %.2f\n", x, n, r);
        }
        else if(n<0){
            r = 1;
            for(int i=n*(-1); i>n; i--){ 
                r = r * x;
            }
        double pot = 1/r;
        printf("O valor de %.0f elevado a %.0f eh %.2f\n", x, n, pot);
        }

    return 0;
}

/*
=> Faça uma função para calcular xn. Não utilizar o operador pow (nem ^ - que não existe em C).
No programa principal permita ao usuário informar o valor de x e de n (inteiro). 
Lembre que n pode assumir valor negativo.

Ex: Elevado(2,4) tem como saída 16; 
    

No programa principal, solicite ao usuário o valor de x e o valor de n.

-------------------------------------------------------------------------------
Exemplo de Saída:

Digite o valor de x: 2
Digite o valor de n: 4
O valor de 2 elevado a 4 eh 16
-------------------------------------------------------------------------------
*/