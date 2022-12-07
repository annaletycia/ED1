// .h
#define MAX 100
#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4
#include "aluno.h"

typedef struct TSeqList TSeqList;

TSeqList *list_create();
int free_list(TSeqList *li);

int insere_lista_ordenada(TSeqList *li, struct aluno a);
int list_push_front(TSeqList *li, struct aluno a);
int list_push_back(TSeqList *li, struct aluno a);

int print_list(TSeqList *li);

int list_size(TSeqList *li);
int list_empty(TSeqList *li);
int list_full(TSeqList *li);

int remove_lista_inicio(TSeqList *li);
int remove_lista(TSeqList *li, int mat);
int remove_lista_otimizado(TSeqList *li, int mat);
int pop_back(TSeqList *li);

int consulta_lista_pos(TSeqList *li, int pos, struct aluno *a);
int consulta_lista_mat(TSeqList *li, int mat, struct aluno *a);
