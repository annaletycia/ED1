#include "TQueue.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct queue_node queue_node;

struct queue_node
{
    struct aluno data;
    queue_node *next;
};

struct TQueue{
    queue_node *front;
    queue_node *end;
    int size;
};

TQueue *queue_create()
{
    TQueue *queue = malloc(sizeof(TQueue));
        if(queue == NULL)
            return NULL;

        queue->front = NULL;
        queue->end = NULL;
        queue->size = 0;
        return queue; 
}

int queue_free(TQueue *queue)
{
    if(queue == NULL)
        return INVALID_NULL_POINTER;
    
    queue_node *aux = queue->front;
    while(aux != NULL){
        free(aux);
        queue_pop(queue);
        aux = queue->front;
    }
    free(queue);
    return SUCCESS;
}

int queue_push(TQueue *queue, struct aluno al)
{
    if(queue == NULL)
        return INVALID_NULL_POINTER;

        queue_node *node = malloc(sizeof(queue_node));
        if(node == NULL)
            return OUT_OF_MEMORY;
    
            node->data = al;
            if(queue->size == 0){ //primeiro elemento
                queue->front = node;
                queue->end = node;
                node->next = NULL;
                queue->size++;
            } else {
            node->next = queue->end;
            queue->size++;
            queue->end = node;
            }
    return SUCCESS;
}

int queue_pop(TQueue *queue)
{
    if(queue == NULL)
        return INVALID_NULL_POINTER;
    
    queue_node *aux = queue->end;
    while(aux->next != queue->front){
        aux = aux->next;
        }
    free(queue->front);
    queue->front = aux;
    queue->size--;
}

int queue_size(TQueue *queue)
{
    if(queue == NULL)
        return INVALID_NULL_POINTER;
    
    return queue->size;
}

int queue_front(TQueue *queue, struct aluno *al)
{
    if(queue == NULL)
        return INVALID_NULL_POINTER;
 
    *al = queue->front->data;
    return SUCCESS;
}

int queue_print(TQueue *queue)
{
    if(queue == NULL)
        return INVALID_NULL_POINTER;
    
    queue_node *aux;
        aux = queue->end;
        int tam = queue_size(queue);
        if(tam == 0){
            printf("\nFila vazia!\n");
        }else{
        printf("\nImprimindo a fila (tamanho %d)\n", tam);

        while (aux != NULL)
        {
            printf("\n------------------\n");
            printf("Matricula: %d\n", aux->data.matricula);
            printf("Nome: %s\n", aux->data.nome);
            printf("Notas: %f; %f; %f;\n", aux->data.n1, aux->data.n2, aux->data.n3);

            aux = aux->next;
        }
        printf("\nFim da fila \n");
        }

    return SUCCESS;
}