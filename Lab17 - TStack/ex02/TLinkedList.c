#include <stdlib.h>
#include <stdio.h>
#include "TLinkedList.h"

typedef struct list_node list_node;

struct list_node
{
    struct aluno data;
    list_node *next;
};

struct TLinkedList
{
    list_node *head;
};

TLinkedList *list_create()
{
    TLinkedList *list;
    list = malloc(sizeof(TLinkedList));
    if (list != NULL)
    {
        list->head = NULL;
        return list;
    } else {
        return NULL;
    }
}

int list_free(TLinkedList *list)
{
    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        list_node *aux;

        aux = list->head;
        while (aux != NULL)
        {
            list->head = aux->next;
            free(aux);
            aux = list->head;
        }

        // segunda forma
        // while (list->head != NULL)
        // {
        //     aux = list->head;
        //     list->head = list->head->next;
        //     free(aux);
        // }
        free(list);
        return SUCCESS;
    }
}

// insere o aluno no início da lista
int list_push_front(TLinkedList *list, struct aluno al)
{
    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        list_node *node;
        node = malloc(sizeof(list_node));
        if (node == NULL)
        {
            return OUT_OF_MEMORY;
        }
        node->data = al;
        node->next = list->head;
        list->head = node;

        return SUCCESS;
    }
}

// insere o aluno no final da lista
int list_push_back(TLinkedList *list, struct aluno al)
{
    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        list_node *node;
        node = malloc(sizeof(list_node));
        if (node == NULL)
            return OUT_OF_MEMORY;
        node->data = al;
        node->next = NULL;
        if (list->head == NULL)
        { // a lista está vazia
            list->head = node;
        }
        else
        { // a lista tem pelo menos um nó
            list_node *aux;
            aux = list->head;
            while (aux->next != NULL)
            {
                aux = aux->next;
            }
            aux->next = node;
        }
        return SUCCESS;
    }
}

// insere o aluno na posição ‘pos’
int list_insert(TLinkedList *list, int pos, struct aluno al)
{
    if(list == NULL){
        return INVALID_NULL_POINTER;
    }
    else{
        list_node *node;
        node = malloc(sizeof(list_node));
        if(node == NULL)
            return OUT_OF_MEMORY;       
        node->data = al;
        
        int qtd = list_size(list);
        list_node *aux = list->head;
        list_node *prev = NULL;

        if(pos < 1 || pos > list_size(list) + 1){
            return OUT_OF_RANGE;
        }
        else{
            int i=0;
            while(aux != NULL && i != pos-1){
                prev = aux;
                aux = aux->next;
                i++;
            }
            if(prev == NULL){ // primeiro elemento da lista
                    node->next = list->head;
                    list->head = node;
                } else {
                prev->next = node;
                node->next = aux->next;
                }
        return SUCCESS;
        }
    }
}

// imprime a lista
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

int list_size(TLinkedList *list)
{
    if (list == NULL){
        return INVALID_NULL_POINTER;
    } 
    else {
        int contador = 0;
        list_node *aux;
        aux = list->head;
        while (aux != NULL)
        {
            aux = aux->next;
            contador = contador + 1;
        }
        return contador;
    }
}

int list_find_pos(TLinkedList *list, int pos, struct aluno *al)
{
    if(list == NULL){
        return INVALID_NULL_POINTER;
    }
    int qtd = list_size(list);
    list_node *aux;
    aux = list->head;

    if(pos < 1 || pos > qtd){
        return OUT_OF_RANGE;
    }
    else{
        int i=0;
        while(i<qtd && i != pos-1){
            aux = aux->next;
            i++;
        }
        if(i == qtd){
            return ELEM_NOT_FOUND;
        }else{
        *al = aux->data;
        return SUCCESS;
        }
    }
}

int list_find_mat(TLinkedList *list, int nmat, struct aluno *al)
{
    if(list == NULL){
        return INVALID_NULL_POINTER;
    }
        int qtd = list_size(list);
        list_node *aux;
        aux = list->head;
        int i = 0;
        while(i < qtd && aux->data.matricula != nmat){
            aux = aux->next;
            i++;
        }
        if(i == qtd){
            return ELEM_NOT_FOUND;
        }
        else{
            *al = aux->data;
            return SUCCESS; 
        }
}

// dado um número de matrícula, retorna a posição na lista
int list_get_pos(TLinkedList *list, int nmat, int *pos)
{
    if(list == NULL)
        return INVALID_NULL_POINTER;
    
    int tam = list_size(list);
    if(*pos < 1 || *pos > (tam + 1))
        return OUT_OF_RANGE;

    int qtd = list_size(list);
    list_node *aux;
    aux = list->head;
    int i = 0;
    while(i < qtd && nmat != aux->data.matricula){
        aux = aux->next;
        i++;
    }
    if(i == qtd){
        return ELEM_NOT_FOUND;
    }else{
    *pos = i + 1;
    return SUCCESS;
    }
}

// retorna o aluno que está no início da lista 
int list_front(TLinkedList *list, struct aluno *al)
{
    if(list == NULL){
        return INVALID_NULL_POINTER;
    }

    list_node *aux;
    aux = list->head;
    *al = aux->data;

    return SUCCESS;
}

// retorna o aluno que está no final da lista 
int list_back(TLinkedList *list, struct aluno *al)
{
    if(list == NULL){
        return INVALID_NULL_POINTER;
    }
    list_node *aux;
    aux = list->head;
    while(aux->next != NULL){
        aux = aux->next;
    }
    *al = aux->data;
    return SUCCESS;
}

// retira da lista o primeiro aluno
int list_pop_front(TLinkedList *list)
{
    if(list == NULL){
        return INVALID_NULL_POINTER;
    }
    list_node *aux;
    aux = list->head;
    list->head = aux->next;
    free(aux);

    return SUCCESS;
}

// retira da lista o último aluno 
int list_pop_back(TLinkedList *list)
{
    if(list == NULL){
        return INVALID_NULL_POINTER;
    }
    list_node *aux;
    aux = list->head;

    list_node *ant;
    ant = aux->next;

    while(ant->next != NULL){
        aux = aux->next;
        ant = aux->next;
    }
    aux->next = NULL;
    free(ant);
    
    //segunda forma (?)
    // while(aux->next != NULL){
    //   aux = aux->next; 
    // }
    // aux = NULL;

    return SUCCESS;
}

// retira da lista o aluno da posição ‘pos’ (posição inicia em 1) 
int list_erase_pos(TLinkedList *list, int pos)
{
    if(list == NULL)
        return INVALID_NULL_POINTER;
    
    int tam = list_size(list);

    if(pos < 1 || pos > tam)
        return OUT_OF_RANGE;

    else{

    list_node *aux = list->head;
    list_node *ant = NULL;
    
    if(tam == 1){
        list->head = NULL;
        aux = NULL;
    }

    int i=0;
    while(i != pos - 1){
        ant = aux;
        aux = aux->next;
        i++;
    }
    if(ant == NULL){
        list->head = aux->next;
        aux = NULL;
        free(aux);
    }else{
    ant->next = aux->next;
    free(aux);
    }
    return SUCCESS;
    }
}

// retira da lista o aluno de matricula ‘mat’ 
int list_erase_data(TLinkedList *list, int nmat)
{
    if(list == NULL){
        return INVALID_NULL_POINTER;
    }

    list_node *aux = list->head;
    list_node *prev = NULL;
    int tam = list_size(list);
    
    if(tam == 1){ //apenas um elemento na lista
        free(aux);
        list->head = NULL;
        return SUCCESS;
    }else{      
        int i = 0;
        while(i < tam && nmat != aux->data.matricula){
            prev = aux;
            aux = aux->next;
            i++;
        }
        if(i == tam){
            return ELEM_NOT_FOUND;
        }else{
            if(prev == NULL){ //primeiro elemento da lista
                list->head = aux->next;
                aux = NULL;
                free(aux);
            }else{
            prev->next = aux->next;
            aux = NULL;
            free(aux);
            }
    return SUCCESS;
        }
    }
}

//insere ordenado
int list_insert_sorted(TLinkedList *list, struct aluno al)
{
    if(list == NULL)
        return INVALID_NULL_POINTER;

    list_node *node;
    node = malloc(sizeof(list_node));

    if(node == NULL)
        return OUT_OF_MEMORY;

    node->data = al;

        list_node *aux = list->head;
        list_node *prev = NULL;

        while(aux != NULL && al.matricula > aux->data.matricula){
            prev = aux;
            aux = aux->next;
        }
        if(prev == NULL){ // (aux == list->head) inserção na cabeça (lista vazia ou menor nmat)
            node->next = aux;
            list->head = node;
        } else {
        prev->next = node;
        node->next = aux;
        }
    return SUCCESS;
}