#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4
#include "aluno.h"

typedef struct CircList CircList;

CircList *circlist_create();
int circlist_free(CircList *clist);

int push_front_circlist(CircList *clist, struct aluno al);
int push_back_circlist(CircList *clist, struct aluno al);
int insert_circlist(CircList *clist, int pos, struct aluno a);
int pop_front_circlist(CircList *clist);
int pop_back_circlist(CircList *clist);

int circlist_front(CircList *clist, struct aluno *al);

int print_circlist(CircList *clist);
int circlist_size(CircList *clist);