#include "TLinkedList.h"
#include "TQueue.h"
#include <stdlib.h> 

struct TQueue{
    TLinkedList *list;
};

TQueue *queue_create()
{
    TQueue *queue = malloc(sizeof(TQueue));
        if(queue == NULL)
            return NULL;
        queue->list = list_create();
        if(queue->list == NULL){
            free(queue);
            return NULL;
        }
        return queue;
}

int queue_free(TQueue *queue)
{
    if(queue == NULL)
        return INVALID_NULL_POINTER;
    list_free(queue->list);
    free(queue);
    return SUCCESS;
}

int queue_push(TQueue *queue, struct aluno al)
{
    if(queue == NULL)
        return INVALID_NULL_POINTER;

    return list_push_back(queue->list, al);
}

int queue_pop(TQueue *queue)
{
    if(queue == NULL)
        return INVALID_NULL_POINTER;
    
    return list_pop_front(queue->list);
}

int queue_print(TQueue *queue)
{
    if(queue == NULL)
        return INVALID_NULL_POINTER;
    
    return list_print(queue->list);
}

int queue_size(TQueue *queue)
{
    if(queue == NULL)
        return INVALID_NULL_POINTER;
    
    return list_size(queue->list);
}

int queue_front(TQueue *queue, struct aluno *al)
{
    if(queue == NULL)
        return INVALID_NULL_POINTER;
    
    return list_front(queue->list, al);
}