//Implemente o TAD de lista circular dinâmica. Elabore um pequeno programa que use a lista circular.

#include "TCircLinkedList.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct CircNode CircNode;

struct CircNode{
    CircNode *next;
    struct aluno data;
};

struct CircList{
    CircNode *end;
    int size;
};

CircList *circlist_create()
{
    CircList *clist = malloc(sizeof(CircList));
    if(clist == NULL)
        return NULL;
    clist->end = NULL;
    clist->size = 0;
    return clist;
}

int circlist_free(CircList *clist)
{
    if(clist == NULL)
        return INVALID_NULL_POINTER;
    
}

int push_front_circlist(CircList *clist, struct aluno al)
{
    if(clist == NULL)
        return INVALID_NULL_POINTER;
    
    CircNode *node = malloc(sizeof(CircNode));
    if(node == NULL)
        return OUT_OF_MEMORY;
    node->data = al;

    if(clist->size != 0){
        node->next = clist->end->next;
        clist->end->next = node;
        clist->size++;
        return SUCCESS;
    }else{ //primeiro elemento
      clist->size++;
      clist->end = node;
      node->next = node;
      return SUCCESS;
    }
}

int push_back_circlist(CircList *clist, struct aluno al)
{
    if(clist == NULL)
        return INVALID_NULL_POINTER;

    CircNode *node = malloc(sizeof(CircNode));
    if(node == NULL)
        return OUT_OF_MEMORY;
    node->data = al;

    if(clist->size != 0){
        node->next = clist->end->next;
        clist->end->next = node;
        clist->end = node;
        clist->size++;
    }else{ //primeiro elemento
        clist->size++;
        clist->end = node;
        node->next = node;
    }
    return SUCCESS;
}

int pop_front_circlist(CircList *clist)
{
    if(clist == NULL)
        return INVALID_NULL_POINTER;
    
    else if(clist->size == 1){ //caso a lista tenha somente um elemento
        free(clist->end);
        clist->size--;
        return SUCCESS;
    } else {
        CircNode *aux = clist->end->next; //primeiro elemento da lista
        clist->end->next = aux->next;
        clist->size--;
        free(aux);
        return SUCCESS;
    }
}

int pop_back_circlist(CircList *clist)
{
    if(clist == NULL)
        return INVALID_NULL_POINTER;
    
    else if(clist->size == 1){ //caso a lista tenha somente um elemento
        free(clist->end);
        clist->size--;
        return SUCCESS;
    } else{
        CircNode *aux = clist->end;
        while(aux->next != clist->end){ //enquanto o next do aux for diferente de end
            aux = aux->next; //avançar um elemento até chegar no penúltimo da lista
        }
    aux->next = clist->end->next;
    free(clist->end);
    clist->end = aux;
    clist->size--;
    }

}

int insert_circlist(CircList *clist, int pos, struct aluno al)
{
    if(clist == NULL)
        return INVALID_NULL_POINTER;
    
    else{
        CircNode *node;
        node = malloc(sizeof(CircNode));
        if(node == NULL)
            return OUT_OF_MEMORY;       
        node->data = al;
        
        int qtd = circlist_size(clist);
        CircNode *aux = clist->end->next; //aponta pro primeiro elemento da lista
        CircNode *prev = NULL;

        if(pos < 1 || pos > circlist_size(clist) + 1){
            return OUT_OF_RANGE;
        }
        else{
            int i=0;
            while(aux->next != clist->end->next && i != pos-1){
                prev = aux;
                aux = aux->next;
                i++;
            }
            if(prev == NULL){ // inserção no começo
                    node->next = node;
                    clist->end= node;
                    clist->size++;
            }else if(pos == clist->size+1){ //inserção no final
                node->next = clist->end->next;
                clist->end->next = node;
                clist->end = node;
                clist->size++;

            }else { // inserção no meio
                prev->next = node;
                node->next = aux;
                clist->size++;

                }
        return SUCCESS;
        }
    }
}

int print_circlist(CircList *clist)
{
    if(clist == NULL)
        return INVALID_NULL_POINTER;
    
    CircNode *aux = clist->end->next;
    int i = 0;
    printf("Imprimindo lista circular (tamanho %d)\n", clist->size);
    while(i<clist->size){
        printf("Matricula: %d\n", aux->data.matricula);
            printf("Nome: %s\n", aux->data.nome);
            printf("Notas: %f %f %f\n", aux->data.n1,
                                        aux->data.n2,
                                        aux->data.n3);
            printf("-----------------------------------\n");
        aux = aux->next;
        i++;
        }
    printf("Fim da lista\n");
    return SUCCESS;
}

int circlist_size(CircList *clist)
{
    if(clist == NULL)
        return INVALID_NULL_POINTER;
    
    return clist->size;
}

int circlist_front(CircList *clist, struct aluno *al)
{
    if(clist == NULL)
        return INVALID_NULL_POINTER;
    
    *al = clist->end->next->data;
    return SUCCESS;
}