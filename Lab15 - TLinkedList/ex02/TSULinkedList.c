#include "TSULinkedList.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct list_node list_node;

struct list_node{
    list_node *next;
    struct aluno data;
};

struct TLinkedList{
    list_node *head;
    int size; // quantidade de elementos na lista
    int sorted; // indica se a lista é ordenada por número de matrícula: 0 – não ordenada; 1 - ordenada
};

// Função que cria a lista
TLinkedList *list_create(int sort)
{
    TLinkedList *list;
    list = malloc(sizeof(TLinkedList));
    if (list != NULL){
        list->head = NULL;
        list->size = 0;
        list->sorted = sort;
        return list;
    } else {
        return NULL;
    }
}

int list_free(TLinkedList *list)
{
    if(list == NULL)
        return INVALID_NULL_POINTER;
    
    list_node *aux = list->head;

    while(aux != NULL){
        list->head = aux->next;
        free(aux);
        aux = list->head;
    }
    free(list);
    return SUCCESS;
}

// Função que retorna tamanho da lista
int list_size(TLinkedList *list)
{
    if(list == NULL)
        return INVALID_NULL_POINTER;
    
    return list->size;
}

// Função que imprime a lista
int list_print(TLinkedList *list)
{
    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        list_node *aux;
        aux = list->head;
        int tam = list_size(list);
        if(tam == 0){
            printf("\nLista vazia!\n");
        }else{
        printf("\nImprimindo a lista (tamanho %d)\n", tam);

        while (aux != NULL)
        {
            printf("\n------------------\n");
            printf("Matricula: %d\n", aux->data.matricula);
            printf("Nome: %s\n", aux->data.nome);
            printf("Notas: %f; %f; %f;\n", aux->data.n1, aux->data.n2, aux->data.n3);

            aux = aux->next;
        }
        printf("\nFim da lista \n");
        }
        return SUCCESS;
    }
}

// Função que insere um elemento no início da lista
int list_push_front(TLinkedList *list, struct aluno al){
    if (list == NULL){
        return INVALID_NULL_POINTER;

    } else if(list->sorted == 1){
            return UNAVAILABLE_FUNCTION;
    } else {
        list_node *node;
        node = malloc(sizeof(list_node));
        if (node == NULL){
            return OUT_OF_MEMORY;
        }
        node->data = al;
        node->next = list->head;
        list->head = node;
        list->size = list->size + 1;
        return SUCCESS;
        }
}

// Função que insere um elemento no final da lista
int list_push_back(TLinkedList *list, struct aluno al){
    if(list == NULL){
        return INVALID_NULL_POINTER;
    }else if(list->sorted == 1){
            return UNAVAILABLE_FUNCTION;
        }
    else {
        list_node *node = malloc(sizeof(list_node));
        if(node == NULL){
            return OUT_OF_MEMORY;
        }
        node->data = al;
        node->next = NULL;
        if(list->head == NULL){ // a lista está vazia
            list->head = node;
            list->size = 1;
        } else { // a lista tem pelo menos um nó
            list_node *aux;
            aux = list->head;
            while(aux->next != NULL){ //percorrendo até o último elemento
                aux = aux->next;
            }
            aux->next = node;
            list->size = list->size + 1;          
        }
        return SUCCESS;
    }
}

// Função que insere um elemento na posição "pos" da lista
int list_insert(TLinkedList *list, int pos, struct aluno al)
{
    if(list == NULL)
        return INVALID_NULL_POINTER;

    else if(list->sorted == 1)
        return UNAVAILABLE_FUNCTION;
    
    else if(pos < 1 || pos > (list->size + 1)){ //posição negativa ou maior do que a ultima posicao + 1 (caso queira inserir no final)
        printf("tamanho = %d", list->size);
        return OUT_OF_RANGE;

    }else{
        list_node *node = malloc(sizeof(list_node));
        if(node == NULL)
            return OUT_OF_MEMORY;

        node->data = al;
        list_node *aux = list->head;
        list_node *prev = NULL;
        int i = 0;
        while(i != pos - 1){
            prev = aux;
            aux = aux->next;
            i++;
        }
        if(prev == NULL){//primeiro elemento da lista
            node->next = list->head;
            list->head = node;
        } else {
            prev->next = node;
            node->next = aux;
        }
        list->size = list->size + 1;
        return SUCCESS;
    }
}

// Função que insere elementos em ordem de matrícula
int list_insert_sorted(TLinkedList *list, struct aluno al)
{
    if(list == NULL)
        return INVALID_NULL_POINTER;
    else if(list->sorted == 0)
        return UNAVAILABLE_FUNCTION;
    else{
        list_node *node = malloc(sizeof(list_node));
        if(node == NULL){
            return OUT_OF_MEMORY;
        }
        node->data = al;
        if(list->head == NULL){ //lista vazia
            node->next = NULL;
            list->head = node;
            list->size = 1;
            return SUCCESS;
        } else{
            list_node *aux = list->head;
            list_node *prev = NULL;
            while(aux != NULL && al.matricula > aux->data.matricula){
                prev = aux;
                aux = aux->next;
            }
            if(prev == NULL){ //primeiro elemento da lista
                node->next = list->head;
                list->head = node;  
                list->size = list->size + 1;
                return SUCCESS;
            } else{
            node->next = aux;
            prev->next = node;
            list->size = list->size + 1;
            return SUCCESS;
            }
        }
    }
}

int list_pop_front(TLinkedList *list)
{
    if(list == NULL)
        return INVALID_NULL_POINTER;
    
    list_node *aux = list->head;
    list->head = aux->next;
    list->size = list->size - 1;
    free(aux);
    return SUCCESS;
}

int list_pop_back(TLinkedList *list)
{
    if(list == NULL)
        return INVALID_NULL_POINTER;
    
    list_node *aux = list->head;
    list_node *prev = NULL;
    while(aux->next != NULL){
        prev = aux;
        aux = aux->next;
    }
    if(prev == NULL){ //unico elemento da lista
        list->head = NULL;
        aux = NULL;
    } else{
    prev->next = NULL;
    aux = NULL;
    }
    
    list->size = list->size - 1;
    return SUCCESS;
}

int list_erase_pos(TLinkedList *list, int pos)
{
    if(list == NULL)
        return INVALID_NULL_POINTER;
    else if(pos < 1 || pos > list_size(list))
        return OUT_OF_RANGE;
    else{
        list_node *aux = list->head;
        list_node *prev = NULL;
        int i = 0;
        while(i != pos - 1){
            prev = aux;
            aux = aux->next;
            i++;
        }
        if(prev == NULL){
            list->head = aux->next;
            aux = NULL;

        }else{
            prev->next = aux->next;
            aux = NULL;
        }
        list->size = list->size - 1;
        return SUCCESS;
    }
}

int list_erase_data(TLinkedList *list, int nmat)
{
    if(list == NULL)
        return INVALID_NULL_POINTER;
    
    list_node *aux = list->head;
    list_node *prev = NULL;
    while(aux!=NULL && nmat != aux->data.matricula){
        prev = aux;
        aux = aux->next;
    }
    if(prev == NULL){
        list->head = aux->next;
        aux = NULL;
    } else {
        prev->next = aux->next;
        aux = NULL;
    }
    list->size = list->size - 1;
    return SUCCESS;
}

int list_find_pos(TLinkedList *list, int pos, struct aluno *al)
{
    if(list == NULL)
        return INVALID_NULL_POINTER;
    else if(pos < 1 || pos > list_size(list))
        return OUT_OF_RANGE;
    else{
        list_node *aux = list->head;
        int i = 0;
        while(i != pos - 1){
            aux = aux->next;
        }
        *al = aux->data;
        return SUCCESS;
    }
}

int list_find_mat(TLinkedList *list, int nmat, struct aluno *al)
{
    if(list == NULL)
        return INVALID_NULL_POINTER;
    
    list_node *aux = list->head;
    while(aux != NULL && nmat > aux->data.matricula){
        aux = aux->next;
    }
    if(aux == NULL){
        return ELEM_NOT_FOUND;
    } else {
        *al = aux->data;
        return SUCCESS;
    }
}

int list_front(TLinkedList *list, struct aluno *al)
{
    if(list == NULL)
        return INVALID_NULL_POINTER;
    
    *al = list->head->data;
    return SUCCESS;
}

int list_back(TLinkedList *list, struct aluno *al)
{
    if(list == NULL)
        return INVALID_NULL_POINTER;

    list_node *aux = list->head;
    while(aux->next != NULL){
        aux = aux->next;
    }
    *al = aux->data;
    return SUCCESS;
}

// dado um número de matrícula, retorna a posição na lista
int list_get_pos(TLinkedList *list, int nmat, int *pos)
{
    if(list == NULL)
        return INVALID_NULL_POINTER;
    list_node *aux = list->head;
    int i = 0;
    while(aux != NULL && nmat != aux->data.matricula){
        aux = aux->next;
        i++;
    }
    if(aux == NULL){
        return ELEM_NOT_FOUND;
    } else{
    *pos = i + 1;
    return SUCCESS;
    }
}