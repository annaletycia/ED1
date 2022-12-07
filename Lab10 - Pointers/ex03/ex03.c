#include <stdio.h>

int main(){

  int val[5] = {2,4,5,8,10};
  int *p;

    printf("val={");
    for(int i=0;i<5;i++){
        p = &val[i];
        printf("%d ", *p);
    }
    printf("}");

    return 0;
}

/* 
3) Existem operadores específicos em C para trabalhar com ponteiros. Um desses operadores é o símbolo *. 
Note que o mesmo símbolo é usado para declarar um ponteiro e também para multiplicação – mas essas operações não são relacionadas. 
O operador * serve para desreferenciar (dereferencing) um ponteiro – ou seja, ele retorna o conteúdo do endereço de memória que ele
referencia/aponta. Ao usar o operador *, o tipo retornado será o mesmo tipo apontado pelo ponteiro. 
Veja um exemplo:
int   a = 40; // cria uma variável do tipo inteiro, chamada a, e inicializa com valor 40 
int   *p; // cria uma variável do tipo ponteiro para inteiro, chamada p, e o conteúdo inicial é lixo
p = &a; // faz p receber o endereço de a
printf("\n O valor da variavel a eh: %d", *p);
O resultado do printf é 40. 
Note que foi usado %d (inteiro), mas a variável usada foi a p (que é int *), mas p foi antes desreferenciada.  
Utilizando o conceito de desreferenciamento, continue o exercício 1, mostrando agora todo o vetor val em um printf, 
mas com o segundo argumento sendo um ponteiro para os elementos de val. Não use a variável val. 
Mostre o mapa de memória deste código ao final da execução
*/