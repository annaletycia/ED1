// .c
#include <stdio.h>
#include <stdlib.h>
#include "TSeqList.h"

struct lista{

    int qtd;
    struct aluno *dados;
};

// Descrição:
// Função que inicializa o TAD da lista
// Não recebe parâmetros
// Retorna o endereço de memória da lista criada dinamicamente
Lista *cria_lista(){

    struct lista *li = malloc(sizeof(struct lista));
    if(li == NULL){
        return NULL;
    }else{
        li->qtd = 0;
        return li;
    }
}

// Descrição:
// Função que libera o espaço alocado dinamicamente pela lista
// Retorno:
// retorno -1: código de erro
// retorno 0: código de sucesso
int free_lista(Lista *li){

    if(li == NULL){
        return -1;
    }else{
        free(li);
        return 0;
    }
}

// Descrição:
// Função que insere um aluno em uma lista de modo ordenado
// Recebe como parâmetro a lista e a struct aluno que será alocada nela
// Retorno:
// retorno -1: código de erro
// retorno  0: código de sucesso
int insere_lista_ordenada(Lista *li, struct aluno a){
    if(li == NULL){
        return -1;
    }
    else if(li->qtd == MAX){ //lista cheia
        return -1;
    }
    int i=0;
    while(i<li->qtd && li->dados[i].mat < a.mat){
        i++;
    }
    for(int k = li->qtd-1; k >= i; k--){
        li->dados[k+1] = li->dados[k]; 
    }
    li->dados[i] = a;
    li->qtd++;
    return 0;
}

// Descrição:
// Função que recebe uma lista e a imprime
// Retorno:
// retorno -1: código de erro
// retorno  0: código de sucesso
int imprime_lista(Lista *li){
    if(li == NULL){
        return -1;
    }else{
        for(int i=0; i<li->qtd; i++){
            printf("Matricula: %d\n", li->dados[i].mat);
            printf("Nome: %s\n", li->dados[i].nome);
            printf("Notas: %f %f %f\n", li->dados[i].n1,
                                        li->dados[i].n2,
                                        li->dados[i].n3);
            printf("-----------------------------------\n");
        }
        return 0;
    }
}

// Descrição:
// Função que insere um novo elemento no início de uma lista
// Retorno:
// retorno -1: código de erro
// retorno  0: código de sucesso
int insere_lista_inicio(Lista *li, struct aluno a){
    if(li == NULL || li->qtd == MAX){ //lista inválida ou cheia
        return -1;
    }
    for(int k=li->qtd-1; k>=0; k--){
        li->dados[k+1] = li->dados[k];
    }
    li->dados[0] = a;
    li->qtd++;
    return 0;
}


// Descrição:
// Função que insere um novo elemento no final de uma lista
// Retorno:
// retorno -1: código de erro
// retorno  0: código de sucesso
int insere_lista_fim(Lista *li, struct aluno a){
    if(li == NULL){
        return -1;
    }
    else if(li->qtd == MAX){ //lista cheia
        return -1;
    }
    li->dados[li->qtd] = a;
    li->qtd++;
    return 0;
}

// Descrição:
// Função que remove o último elemento de uma lista
// Retorno:
// retorno -1: código de erro
// retorno  0: código de sucesso
int remove_lista_fim(Lista *li){
    if(li == NULL){
        return -1;
    }
    else if(li->qtd == 0){
        return -1;
    }
    li->qtd--;
    return 0;
}

// Descrição:
// Função que indica o tamanho de uma lista
// Retorno:
// Retorno -1: código de erro
// Em caso de sucesso, retorna o número de elementos presentes na lista
int tamanho_lista(Lista *li){
    if(li == NULL){
        return -1;
    }
    else{
        return li->qtd;
    }
}

// Descrição:
// Função que indica se a lista está ou não cheia
// Retorno:
// Retorno -1: código de erro
// Retorno 1: lista cheia
// Retorno 0: lista não está cheia
int lista_cheia(Lista *li){
    if(li == NULL){
        return -1;
    }
    else if(li->qtd == MAX){
        return 1;
    }else{
        return 0;
    }
}

// Descrição:
// Função que indica se a lista está ou não vazia
// Retorno:
// Retorno -1: código de erro
// Retorno 1: lista vazia
// Retorno 0: lista não está vazia
int lista_vazia(Lista *li){
    if(li == NULL){
        return -1;
    }
    return (li->qtd == MAX);
}

// Descrição:
// Função que remove o primeiro elemento da lista
// Retorno:
// retorno -1: código de erro
// retorno 0: código de sucesso
int remove_lista_inicio(Lista *li){
    if(li == NULL || li->qtd == 0){ //se a lista for vazia, não será possível remover elemento algum
        return -1;
    }
    for(int i=0; i < li->qtd-1; i++){ //percorre da posição 0 do vetor até o último elemento, levando em consideração que a quantidade foi diminuída
        li->dados[i] = li->dados[i+1];
    }
    li->qtd--;
    return 0;
}

// Descrição:
// Função que remove o aluno da lista de acordo com o número de matrícula indicado
// Retorno:
// retorno -1: código de erro
// retorno 0: código de sucesso
int remove_lista(Lista *li, int mat){
    if(li == NULL || li->qtd == 0){
        return -1;
    }
    int i = 0;
    while(i < li->qtd && li->dados[i].mat != mat){ //busca
        i++;
    }
    if(i == li->qtd){ //elemento não encontrado
        return -1;
    }
    for(int k = i; k < li->qtd-1; k++){ 
        li->dados[k] = li->dados[k+1]; //realocação de todos os elementos a partir de i, que será removido
    }
    li->qtd--;
    return 0;
}

// Descrição:
// Função que remove o aluno da lista de acordo com o número de matrícula indicado de modo otimizado
// Retorno:
// retorno -1: código de erro
// retorno 0: código de sucesso
int remove_lista_otimizado(Lista *li, int mat){
    if(li == NULL || li->qtd == 0){
        return -1;
    }
    int i = 0;
    while(i < li->qtd && li->dados[i].mat != mat){ //busca
        i++;
    }
    if(i == li->qtd){ //elemento não encontrado
        return -1;
    }

    li->dados[i] = li->dados[li->qtd-1]; //substitui o conteúdo da posição i pelo conteúdo do último elemento da lista
    li->qtd--;
    return 0;
}

// Descrição:
// Função que consulta os dados do aluno de acordo com a posição dele na lista
// Retorno:
// retorno -1: código de erro
// retorno 0: código de sucesso
int consulta_lista_pos(Lista *li, int pos, struct aluno *a){
    if(li == NULL || pos <= 0 || pos > li->qtd){  //lista inválida ou posição inexistente
        return -1;
    }
    *a = li->dados[pos-1];
    return 0;
}

// Descrição:
// Função que consulta na lista os dados do aluno de acordo com o número de matrícula
// Retorno:
// retorno -1: código de erro
// retorno 0: código de sucesso
int consulta_lista_mat(Lista *li, int mat, struct aluno *a){
    if(li==NULL){
        return -1;
    }
    int i = 0;
    while(i < li->qtd && li->dados[i].mat != mat){  //busca
        i++;
    }
    if(i == li-> qtd){ //elemento não encontrado
        return -1;
    }
    *a = li->dados[i];
    return 0;
}