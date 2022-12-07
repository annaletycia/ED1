#include "aluno.h"
#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4

typedef struct TQueue TQueue;

TQueue *queue_create(int tam);
int queue_free(TQueue *qu);

int queue_push(TQueue *qu, struct aluno al);
int queue_pop(TQueue *qu);

int queue_size(TQueue *qu);
int empty_queue(TQueue *qu);
int full_queue(TQueue *qu);

int queue_front(TQueue *qu, struct aluno *al);
int compactar_fila(TQueue *qu);
int print_queue(TQueue *qu);