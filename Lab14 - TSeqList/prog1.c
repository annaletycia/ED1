#include <stdio.h>
#include <stdlib.h>
#include "TSeqList.h"

int main(){
     
    struct aluno a[4] = {{"Bruna", 2, 8.7,5.2,6.5},
                        {"Anna", 1, 9.6, 9.7, 9.8},
                        {"Caio", 3, 7.4, 5.4, 1.2},
                        {"Davi", 4, 6.4, 8.5, 2.5,}};
    

// Cria lista
    Lista *lista_alunos_facom;
    lista_alunos_facom = cria_lista();

    if( lista_alunos_facom == NULL){
        printf("\nErro! Lista nao alocada!\n");
    }else{
        printf("\nLista alocada com sucesso!\n\n");
    }


// Preenche de forma ordenada os alunos na lista
    for(int i=0; i<4; i++){
        if(insere_lista_ordenada(lista_alunos_facom, a[i]) == -1){
        printf("Erro! Lista invalida ou lista cheia!\n");
        }
    }


// Imprime lista
    if(imprime_lista(lista_alunos_facom) == -1){
        printf("Erro! Lista invalida!");
    }
    printf("\n\n\n\n");


// Insere elemento no início da lista
    struct aluno novo = {"Amanda", 7, 8.5, 6.5, 9.0};

    printf("Inserindo novo aluno(a) no inicio da lista!\n");
    if(insere_lista_inicio(lista_alunos_facom, novo) == -1){
        printf("Erro! Lista invalida ou cheia!\n");
    }else{
        imprime_lista(lista_alunos_facom);
    }


// Insere elemento no final da lista
    struct aluno novato = {"Elaine", 5, 6.5, 4.2, 8.0};

    printf("Adicionando novo aluno(a) no fim da lista:\n");
    if(insere_lista_fim(lista_alunos_facom, novato) == -1){
        printf("Erro! Lista invalida ou lista sem espaco!\n");
    }else{
        imprime_lista(lista_alunos_facom);
    }


// Consulta elemento de acordo com a posição
    struct aluno quem;
    if(consulta_lista_pos(lista_alunos_facom, 2, &quem) == -1){
        printf("Erro! Lista invalida!\n");
    }else{
        printf("Consulta de acordo com a posicao realizada!\n");
    }


// Consulta elemento de acordo com o número da matrícula
    struct aluno who;
    if(consulta_lista_mat(lista_alunos_facom, 4, &who) == -1){
        printf("Erro! Lista invalida!\n");
    }else{
        printf("Consulta de acordo com a matricula realizada!\n");
    }


// Remove último elemento da lista
    printf("\n\n\n\n");
    printf("Removendo ultimo aluno(a):\n");
    if(remove_lista_fim(lista_alunos_facom) == -1){
        printf("Erro! Lista invalida ou vazia!\n");
    }else{
        imprime_lista(lista_alunos_facom);
    }


// Indica tamanho da lista
    int tamanho = tamanho_lista(lista_alunos_facom);
    if(tamanho == -1){
        printf("Erro! Lista invalida!\n");
    }else{
        printf("O tamanho da lista indicada eh: %d\n", tamanho);
    }


// Remove primeiro elemento da lista
    printf("\nRemovendo primeiro aluno:\n");
    if(remove_lista_inicio(lista_alunos_facom) == -1){
        printf("Lista invalida ou vazia!\n");
    }
    printf("\n\n");
    imprime_lista(lista_alunos_facom);


// Indica se a lista está cheia
    int cheia = lista_cheia(lista_alunos_facom);
    if(cheia == -1){
        printf("Erro! Lista invalida!\n");
    }else if(cheia == 0){
        printf("Lista nao cheia!\n");
    }else{
        printf("Lista cheia!\n");
    }


// Indica se a lista está vazia
    int vazia = lista_vazia(lista_alunos_facom);
    if(vazia == -1){
        printf("Erro! Lista invalida!\n");
    }else if(vazia == 0){
        printf("Lista nao vazia!\n");
    }else{
        printf("Lista vazia!\n");
    }


// Remove da lista o elemento da matrícula indicada
    if(remove_lista(lista_alunos_facom, 3) == -1){
        printf("Erro! Lista invalida ou vazia ou aluno nao encontrado!\n");
    }else{
        printf("\n\n");
        imprime_lista(lista_alunos_facom);
    }


// Remove da lista o elemento da matrícula indicada (modo otimizado)
    if(remove_lista_otimizado(lista_alunos_facom, 2) == -1){
        printf("Erro! Lista invalida ou vazia ou aluno nao encontrado!\n");
    }else{
        printf("\n\n");
        imprime_lista(lista_alunos_facom);
    }


// Libera lista 
    if(free_lista(lista_alunos_facom) == -1){
        printf("\nErro! Lista invalida!\n");
    }else{
        printf("\nLista liberada com sucesso!\n\n");
    }

return 0;
}