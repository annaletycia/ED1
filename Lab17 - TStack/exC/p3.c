#include <stdio.h>
#include <stdlib.h>
/* ex03
Crie uma função que faz a junção de dois vetores inteiros. 
A função deve ter como entrada os dois vetores e seus
respectivos tamanhos. A alocação de espaço necessário para
o vetor concatenado deve ser feita dentro da função 
(a função então deve devolver para o programa principal 
o vetor alocado e também o tamanho desse novo vetor). 
A função deve retornar um valor inteiro: (0 - zero)
se a junção ocorreu de forma correta; (-1) em caso de erro.
Mostre o uso da função no programa principal. Não é
permitido criar novos tipos de dados para a solução
do exercício (ou seja, sem uso de structs).

Vetor 1: [1, 5, 2]
Vetor 2: [10, 30] 
Concatenção Vetor 1, Vetor 2

Vetor Concatenado = [ 1, 5, 2, 10, 30]

*/

// check:<<<erro: vetor resultante deve ser passado como ponteiro de ponteiro>>>>
int concatena(int *vetor1, int *vetor2, int n1, int n2, int *vetor, int *vetorp)
{
    vetor = (int *)malloc((n1+n2) * sizeof(int));// check:<<<erro: seria 'vetor' não?>>>>
    *vetorp = n1+n2;// check:<<<erro: sizeof de ponteiro! nao retorna o tamanho do vetor>>>>

    if (vetorp != NULL)
    {
        for(int i=0; i<n1; i++){
        vetor[i] = vetor1[i];
        }
        for(int i=0; i<n2; i++){ 
        vetor[i+n2] = vetor2[i];// check:<<<erro: fixar valor vai deixar errada a função>>>>
        }
        return 0;
    }
    return -1;
}

int main()
{

    int vetor1[7] = {1, 2, 3, 4, 5, 6, 7};
    int vetor2[3] = {8, 9, 10};
    int *vetorp;
    int n1;
    int n2;
    int *vetor;

    int concat;
    concat = concatena(vetor1, vetor2, n1, n2, vetor, vetorp);

    if(concat==0){
        printf("Vetor = ");
        for (int i = 0; i < n1+n2; i++){
        printf("%d, ", vetor[i]);
        }
    } else {
        printf("Erro!\n");
    }
    
    free(vetorp);
    return 0;
}