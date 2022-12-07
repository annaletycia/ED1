//Implemente o TAD Fila sequencial para que suporte filas de tamanhos variáveis, mas que ainda utilize vetores para armazenar os elementos da fila.
//Ao criar a fila, passe como parâmetro um tamanho inicial máximo de elementos da fila 

//Ex: 100 -> qu = queue_create(100);

//Caso o usuário tente inserir mais elementos do que a fila suporta, o TAD deve automaticamente realocar mais memória, adicionando a mesma 
//quantidade inicial de elementos. Ou seja, se ao criar o TAD o usuário alocou inicialmente 100 elementos, quando o usuário tentar inserir 
//o 101º elemento o TAD deverá alocar antes mais 100 elementos, totalizando 200 elementos no máximo. Se o usuário posteriormente tentar inserir 
//o 201º elemento, mais 100 elementos serão alocados, totalizando 300 no máximo.

//Ao remover elementos a memória já previamente alocada deve ser mantida. No entanto, crie uma função chamada compactar_lista, que reduzir o 
//tamanho do vetor da fila para o menor tamanho possível que seja múltiplo do tamanho inicial da fila.

//Exemplo:
//Fila com 1000 posições máximas
//Atualmente com 560 elementos. 
//Tamanho inicial: 100
//Ao reduzir a fila ficará terá no máximo 600 posições alocadas.
//Ceil(560/100)*100 

#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include "TQueue.h"

int main()
{
    struct aluno a[4] = {{"Bruna", 2, 8.7,5.2,6.5},
                        {"Anna", 1, 9.6, 9.7, 9.8},
                        {"Caio", 3, 7.4, 5.4, 1.2},
                        {"Davi", 4, 6.4, 8.5, 2.5,}};
    

    int tam_inicial;
    printf("Qual o tamanho inicial da fila? ");
    scanf("%d", &tam_inicial);

    TQueue *fila_lanche;
    fila_lanche = queue_create(tam_inicial);

    printf("\nTamanho da fila inicialmente: %d\n", queue_size(fila_lanche));

    for(int i=0; i<4; i++){
        queue_push(fila_lanche, a[i]);
    }
    printf("\nTamanho da fila apos inserir alunos: %d\n", queue_size(fila_lanche));

    struct aluno primeiro;
    if (queue_front(fila_lanche, &primeiro) != 0)
        printf("Erro");
    printf("O primeiro aluno da fila no momento eh: %d\n", primeiro.matricula);
    printf("%s %d %f %f %f\n", primeiro.nome, primeiro.matricula, primeiro.n1, primeiro.n2, primeiro.n3);


    /*queue_pop(fila_lanche);
    printf("\nTamanho apos remover o primeiro da fila: %d\n", queue_size(fila_lanche));

    queue_front(fila_lanche, &primeiro);
    printf("O primeiro aluno da fila agora eh: %s\n", primeiro.nome);
*/
    queue_free(fila_lanche);
    return 0;
}