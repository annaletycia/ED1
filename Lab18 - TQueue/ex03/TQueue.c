#include "TQueue.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct TQueue{
    int front;
    int rear;
    int size;
    int tam_max;
    int tam_inicial;
    struct aluno *data;
};

TQueue *queue_create(int tam)
{
    TQueue *qu = malloc(sizeof(TQueue));
        if(qu == NULL)
            return NULL;

       // qu->front = 0;
       // qu->rear = 0;
        qu->size = 0;
        qu->tam_inicial = tam;
        qu->tam_max = tam;
        qu->data = malloc(tam * sizeof(struct aluno));
            if(qu->data == NULL){
                free(qu);
                return NULL;
            }

        return qu; 
}

int queue_free(TQueue *qu)
{
    if(qu == NULL)
        return INVALID_NULL_POINTER;

    free(qu->data);
    free(qu);

    return SUCCESS;
}

int queue_push(TQueue *qu, struct aluno al)
{
    if(qu == NULL)
        return INVALID_NULL_POINTER;
    
    else if(qu->size == qu->tam_max){ //lista cheia
        qu->data = realloc(qu->data, (qu->size+qu->tam_inicial)*sizeof(struct aluno));
        qu->tam_max = qu->size + qu->tam_inicial;
    }
    else if(qu->size == 0){ //primeiro elemento da fila
        qu->data[qu->size];
        qu->size++;
        qu->front = 0;
        qu->rear = 1;
    } else {
        qu->data[qu->size];
        qu->size++;
        qu->rear = ((qu->rear)+1)%(qu->tam_max);
    }
    
    return SUCCESS;
}

int queue_pop(TQueue *qu)
{
    if(qu == NULL)
        return INVALID_NULL_POINTER;
    if(qu->size == 0) //lista vazia
        return OUT_OF_RANGE;
    
    qu->front = (qu->front+1)%qu->tam_max;
    qu->size--;

    return SUCCESS;
}

int queue_size(TQueue *qu)
{
    if(qu == NULL)
        return INVALID_NULL_POINTER;
    
    return qu->size;
}

int queue_front(TQueue *qu, struct aluno *al)
{
    if(qu == NULL)
        return INVALID_NULL_POINTER;
   
    *al = qu->data[0];

    return SUCCESS;
}

int compactar_fila(TQueue *qu)
{
    if(qu == NULL){
        return INVALID_NULL_POINTER;
    }else
    {
        float novo_tam = (ceil(qu->size/qu->tam_inicial)) * qu->tam_inicial;
        qu->data = realloc(qu->data, novo_tam * sizeof(struct aluno));
        qu->tam_max = novo_tam;
    }
    return SUCCESS;
}

int print_queue(TQueue *qu)
{
    if(qu == NULL){
        return INVALID_NULL_POINTER;
    }else{
        for(int i=0; i<qu->size; i++){
            printf("Matricula: %d\n", qu->data[i].matricula);
            printf("Nome: %s\n", qu->data[i].nome);
            printf("Notas: %f %f %f\n", qu->data[i].n1,
                                        qu->data[i].n2,
                                        qu->data[i].n3);
            printf("-----------------------------------\n");
        }
        return 0;
    }
}

int empty_queue(TQueue *qu)
{
    if(qu == NULL)
        return INVALID_NULL_POINTER;
    
    return qu->size == 0;
}

int full_queue(TQueue *qu)
{
    if(qu == NULL)
        return INVALID_NULL_POINTER;
    
    return qu->size == qu->tam_max;
}