#include <stdio.h>
#include <math.h>

int main(){

    float bolinhas[4];
    float prob[4];

    printf("<<Probabilidades>>\n");
    printf("\nDigite a quantide de bolinhas\n");

    int i=0;
    float soma=0;
    printf("Verde: ");
    scanf("%f", &bolinhas[i]);
    soma = soma + bolinhas[i];
    printf("Azul: ");
    i++;
    scanf("%f", &bolinhas[i]);
    soma = soma + bolinhas[i];
    printf("Amarela: ");
    i++;
    scanf("%f", &bolinhas[i]);
    soma = soma + bolinhas[i];
    printf("Vermelha ");
    i++;
    scanf("%f", &bolinhas[i]);
    soma = soma + bolinhas[i];

        for(i=0;i<4;i++){
             prob[i] = (bolinhas[i]/soma)*100.0;
        }

    float maiorP = prob[0];

        for(i=0;i<4;i++){
            if(prob[i]>maiorP){
                maiorP = prob[i];
            }
        }

    printf("\nProbabilidades\n");
    if(maiorP == prob[0]){
        printf("Verde: %.2f%% <<Maior probabilidade\n", prob[0]);
    }else{
    printf("Verde: %.1f%%\n", floor(prob[0]*10.0f)/10.0f);
    }
    if(maiorP == prob[1]){
        printf("Azul: %.2f%% <<Maior probabilidade\n", prob[1]);
    }else{
    printf("Azul: %.1f%%\n", floor(prob[1]*10.0f)/10.0f);
    }
    if(maiorP == prob[2]){
        printf("Amarela: %.2f%% <<Maior probabilidade\n", prob[2]);
    }else{       
    printf("Amarela: %.1f%%\n", floor(prob[2]*10.0f)/10.0f);
    }
    if(maiorP == prob[3]){
        printf("Vermelha: %.2f%% <<Maior probabilidade\n",prob[3]);
    }else{
    printf("Vermelha: %.1f%%\n", floor(prob[3]*10.0f)/10.0f);
    }
return 0;
}

/*
Uma piscina de bolinhas possui bolas azuis, verdes, amarelas e vermelhas. 
Faça um programa em que o usuário digita a quantidade de bolinhas de cada
cor existente em uma piscina e mostra a probabilidade de ocorrência de cada 
cor, indicando qual possui a maior probabilidade

Exemplo de saída:
<< Probabilidades >>

Digite a quantidade de bolinhas
Verde: 51
Azul: 60
Amarela: 70
Vermelha: 80

Probabilidades
Verde: 19.5%
Azul: 22.9%
Amarela: 26.8%
Vermelha: 30.6% << Maior probabilidade
*/