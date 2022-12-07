#include "TDLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct DLNode DLNode;

struct DLNode{
    struct aluno data;
    DLNode *next;
    DLNode *prev;
};

struct TDLinkedList{
    DLNode *begin;
    DLNode *end;
    int size;
};

TDLinkedList *list_create()
{
    TDLinkedList *list = malloc(sizeof(TDLinkedList));
    
    if(list != NULL)
    {        
        list->size = 0;
        list->end = NULL;
        list->begin = NULL;
        return list;
    } else {
        return NULL;
    }
}

int list_free(TDLinkedList *list)
{
    if(list == NULL)
        return INVALID_NULL_POINTER;
    DLNode *aux = list->begin;
    while(aux != NULL){
        list->begin = aux->next;
        free(aux);
        aux = aux->next;
    }
    list->size = 0;
    list->end = NULL;
    free(list);
}

int list_size(TDLinkedList *list)
{
    if(list == NULL)
        return INVALID_NULL_POINTER;
    else
        return list->size;
}

int list_print_forward(TDLinkedList *list)
{
    if(list == NULL)
        return INVALID_NULL_POINTER;

    DLNode *aux = list->begin;
    if(list->size == 0){
        printf("\nLista vazia!\n");
    } else {
        printf("Imprimindo lista (tamanho: %d)", list->size);
        while (aux != NULL)
        {
            printf("\n------------------\n");
            printf("Matricula: %d\n", aux->data.matricula);
            printf("Nome: %s\n", aux->data.nome);
            printf("Notas: %f; %f; %f;\n", aux->data.n1, aux->data.n2, aux->data.n3);

            aux = aux->next;
        }
        printf("\nFim da lista!\n");
    }
}

int list_print_reverse(TDLinkedList *list)
{
    if(list == NULL)
        return INVALID_NULL_POINTER;

    DLNode *aux = list->end;
    if(list->size == 0)
        printf("\nLista vazia!\n");
    else {
        printf("Imprimindo lista (tamanho %d)\n", list->size);
        while(aux != NULL){
            printf("\n------------------\n");
            printf("Matricula: %d\n", aux->data.matricula);
            printf("Nome: %s\n", aux->data.nome);
            printf("Notas: %f; %f; %f;\n", aux->data.n1, aux->data.n2, aux->data.n3);

            aux = aux->prev;
        }
        printf("\nFim da lista!\n");
    }
}

int list_push_front(TDLinkedList *list, struct aluno al)
{
    if(list == NULL)
        return INVALID_NULL_POINTER;

    DLNode *node = malloc(sizeof(DLNode));
        if(node == NULL)
            return OUT_OF_MEMORY;

        node->data = al;
        node->prev = NULL;
        node->next = list->begin;
        if(list->begin == NULL){ // lista vazia
            list->begin = node;
            list->end = node;
            list->size = 1;
        } else { // a lista possui pelo menos um nó
            list->begin->prev = node;
            list->begin = node;
            list->size = list->size + 1;
        }
        return SUCCESS;
}

int list_push_back(TDLinkedList *list, struct aluno al)
{
    if(list == NULL)
        return INVALID_NULL_POINTER;
    DLNode *node = malloc(sizeof(DLNode));
    if (node == NULL)
        return OUT_OF_MEMORY;
        node->data = al;
    if(list->begin == NULL)
    { // primeiro elemento
        list->begin = node;
        list->end = node;
        list->size++;
    } else 
    { //tem ao menos um elemento
    list->end->next = node;
    node->prev = list->end;
    list->end = node;
    list->size++;
    }
    return SUCCESS;
}

int list_insert(TDLinkedList *list, int pos, struct aluno al)
{
    if(list == NULL){
        return INVALID_NULL_POINTER;
    }
    else if(pos < 1 || pos > list->size + 1){ //posição inválida
        return OUT_OF_RANGE;
    }
    else{
        DLNode *node = malloc(sizeof(DLNode));
        if(node == NULL){
            return OUT_OF_MEMORY;}
        node->data = al;
        if(list->size == 0) //lista vazia
        {
            node->next = NULL;
            node->prev = NULL;
            list->begin = node;
            list->end = node;
            list->size = 1;
        } 
        else if(pos == 1) // insere na primeira posição
        { 
            node->prev = NULL;
            node->next = list->begin;
            list->begin->prev = node;
            list->begin = node;
            list->size = list->size + 1;
        }
        else if( pos == list->size + 1) // insere no fim da lista
        {
            node->next = NULL;
            node->prev = list->end;
            list->end->next = node;
            list->end = node;
            list->size++;
        }
        else //insere no meio
        {
            DLNode *aux = list->begin;
            int i = 1;
            while(i < pos - 1){
                aux = aux->next;
                i++;
            }
            node->prev = aux;
            node->next = aux->next;
            aux->next->prev = node;
            aux->next = node;
            list->size++;
        }
    }
    return SUCCESS;
}

int list_pop_front(TDLinkedList *list)
{
    if(list == NULL)
        return INVALID_NULL_POINTER;
    else{
        if(list->size == 1){ //apenas um elemento
            list->begin = NULL;
            list->end = NULL;
            list->size--;
        } else { //mais de um elemento
            DLNode *aux = list->begin->next;

            aux->prev = NULL;
            list->begin = aux;
            list->size--;
        }
        return SUCCESS;
    }
}

int list_pop_back(TDLinkedList *list)
{
    if(list == NULL)
        return INVALID_NULL_POINTER;
    else
    {   
        if(list->size == 1) //somente um elemento
        {
            list->begin = NULL;
            list->end = NULL;
            list->size--;
        } else  //mais de um elemento
        {
            DLNode *aux = list->end->prev;

            aux->next = NULL;
            list->end = aux;
            list->size--;
        }
    }
    return SUCCESS;
}

int list_erase(TDLinkedList *list, int pos)
{
    if(list == NULL)
        return INVALID_NULL_POINTER;
    else if(pos < 1 || pos > list->size)
        return OUT_OF_RANGE;
    else{
    
        DLNode *aux = list->begin;
        DLNode *last = list->end;
        int i = 1;
        if(pos == 1)
        {
            list->begin = aux->next;
            aux->next->prev = NULL;
            free(aux);
            list->size--;
        } 
        else if (pos == list->size)
        {
            last->prev->next = NULL;
            list->end = last->prev;
            free(last);
            list->size--;
        } else {
            while(i != pos){
                aux = aux->next;
                i++;
            }
            aux->prev->next = aux->next;
            aux->next->prev = aux->prev;
            free(aux);
            list->size--;
        }
    }
    return SUCCESS;
}

int list_find_pos(TDLinkedList *list, int pos, struct aluno *al)
{
    if(list == NULL)
        return INVALID_NULL_POINTER;
    else if(pos < 1 || pos > list->size)
        return OUT_OF_RANGE;
    else {
        int i = 1;
        DLNode *aux = list->begin;
        while(i != pos){
            aux = aux->next;
            i++;
        }
        *al = aux->data;
        return SUCCESS;
    }
}

int list_find_mat(TDLinkedList *list, int nmat, struct aluno *al)
{
    if(list == NULL)
        return INVALID_NULL_POINTER;
    
    DLNode *aux = list->begin;
    while(aux != NULL && nmat != aux->data.matricula){
        aux = aux->next;
    }
    *al = aux->data;
}

int list_front(TDLinkedList *list, struct aluno *al)
{
    if(list == NULL)
        return INVALID_NULL_POINTER;
    
    *al = list->begin->data;

    return SUCCESS;
}

int list_back(TDLinkedList *list, struct aluno *al)
{
    if(list == NULL)
        return INVALID_NULL_POINTER;
    
    *al = list->end->data;

    return SUCCESS;
}

int list_get_pos(TDLinkedList *list, int nmat, int *pos)
{ 
    if(list == NULL)
        return INVALID_NULL_POINTER;
    
    int i = 1;
    DLNode *aux = list->begin;
    while(aux != NULL && nmat != aux->data.matricula){
        aux=aux->next;
        i++;
    }
    if(aux == NULL)
        return ELEM_NOT_FOUND;
    else{
        *pos = i;
        return SUCCESS;
    }
}

// retira da lista todos os alunos que possuem nota zero nas três provas
int list_erase_zeros(TDLinkedList *list)
{
    if(list == NULL)
        return INVALID_NULL_POINTER;
    // check:<<<erro: e1.2 Não apagou corretamente. Ao usar list_erase(list,pos) tem que lembrar que a lista diminui de tamanho a cada chamada e o 'pos' não faz mais sentido>>>>
    DLNode *aux = list->begin;

    while(aux!=NULL){
        if(aux->data.n1 == 0 && aux->data.n2 == 0 && aux->data.n3 == 0){
            aux->prev->next = aux->next;
            aux->next->prev = aux->prev;
            list->size--;
        }
        aux = aux->next;
    }
    return SUCCESS;
}

// transfere os elementos de uma lista para outra a partir de uma determinada posição 'pos'
// Retorno da função: 
// 0 para sucesso; 
// -1 para qualquer tipo de erro
int list_splice(TDLinkedList *dest, TDLinkedList *source, int pos)
{
    if(dest == NULL || source == NULL) //ponteiros nulos/inválidos
        return -1;
    else if(pos < 1 || pos > dest->size + 1) //posição inválida
        return -1;
    else{
        if(pos == dest->size+1) // última posição
        {
            dest->end->next = source->begin;
            source->begin->prev = dest->end;
            dest->end = source->end;

        }
        else if(pos == 1) // primeira posição
        {
            dest->begin->prev = source->end;
            source->end->next = dest->begin;
            dest->begin = source->begin;
        }
        else{ // posição no meio da lista

            DLNode *aux = dest->begin;
            int i = 1;
            while(aux != NULL && i != pos){
                aux = aux->next;
                i++;
            }
            aux->prev->next = source->begin;
            source->end->next = aux;
            }
    }
    dest->size = dest->size + source->size; // refefinindo tamanho da nova lista
    source = NULL; // lista de origem nula
    return 0;
}