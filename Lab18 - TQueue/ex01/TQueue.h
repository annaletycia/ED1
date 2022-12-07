#include "aluno.h"

typedef struct TQueue TQueue;

TQueue *queue_create();
int queue_free(TQueue *queue);

int queue_push(TQueue *queue, struct aluno al);
int queue_pop(TQueue *queue);

int queue_print(TQueue *queue);
int queue_size(TQueue *queue); 

int queue_front(TQueue *queue, struct aluno *al);