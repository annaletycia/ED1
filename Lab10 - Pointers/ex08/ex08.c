#include <stdio.h>

int main(){

    int x;
    float y;
    void *p;

    p = &x;
    printf("Digite um numero:");
    scanf("%d", p);
    printf("int = %d\n", *(int *)p);
    
    p = &y;
    printf("Digite outro numero:");
    scanf("%f", p);
    printf("float = %f\n", *(float *)p);

    return 0;
}
/*
8) Ponteiros void: é um ponteiro genérico, que aponta para qualquer tipo. Sua declaração é deste tipo:

void *nome_ponteiro

Um ponteiro void pode apontar para qualquer tipo. Entretanto, antes de usá-los, é necessário fazer um type cast 
para o tipo que ele aponta. Por exemplo: (int *)  ou (float *)  ou  (double *).Faça um programa com dois números, 
um inteiro e um double. Crie um ponteiro void e use-o para ler os valores desses dois números com o comando scanf. 
Após a leitura, mostre na tela os números lidos, mas use no printf somente o ponteiro para mostrar os valores.
*/