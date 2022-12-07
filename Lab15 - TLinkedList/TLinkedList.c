#include <stdlib.h>
#include <stdio.h>
#include "TLinkedList.h"

typedef struct list_node list_node;

struct list_node {
    struct aluno data;
    list_node *next;  
};

struct TLinkedList {
    list_node *head;
    int size; // quantidade de elementos na lista
    int sorted; // indica se a lista é ordenada por número de matrícula: 0 – não ordenada ; 1 - ordenada 
};

TLinkedList *list_create(int bl)
{
    TLinkedList *list;
    list = malloc(sizeof(TLinkedList));
    if (list != NULL){
        list->head = NULL;
        list->size = 0;
        list->sorted = bl;
    }
    return list;
}

int list_free(TLinkedList *list)
{
    if (list == NULL){
        return INVALID_NULL_POINTER;
    } else{
        list_node *aux;
        aux = list->head;
        while (aux != NULL){
            list->head = aux->next;
            free(aux);
            aux = list->head;
        }

        // // solucao 2
        // while (list->head != NULL){
        //     aux = list->head;
        //     list->head = list->head->next;
        //     free(aux);
        // }

        free(list);
    }
}

int list_size(TLinkedList *list)
{
    if(list == NULL)
        return INVALID_NULL_POINTER;
    
    return list->size;
}

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

        if(list->size == 0){
            printf("\nLista vazia!\n");
        }else{
        printf("\nImprimindo a lista (tamanho %d)\n", list->size);

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
            node->next = list->head;
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

int list_insert(TLinkedList *list, int pos, struct aluno al)
{
    if(list == NULL)
        return INVALID_NULL_POINTER;

    else if(list->sorted == 1)
        return UNAVAILABLE_FUNCTION;
    
    else if(pos < 0)
        return OUT_OF_RANGE;

    else{
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
        prev->next = node;
        node->next = aux->next;
        list->size++;

        return SUCCESS;
    }
}