#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4

#ifndef _tstackh_
#define _tstackh_

typedef struct TStack TStack;

TStack *stack_create(int tamanho);
int stack_free(TStack *st);

int stack_push(TStack *st, char elem);
int stack_pop(TStack *st);
int stack_top(TStack *st,char *top);

int stack_size(TStack *st);
int stack_empty(TStack *st);
int stack_full(TStack *st);
int stack_print(TStack *st);

#endif