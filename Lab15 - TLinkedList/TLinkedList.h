#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4
#define UNAVAILABLE_FUNCTION -5

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct TLinkedList TLinkedList;

TLinkedList *list_create(int bl);
int list_free(TLinkedList *li);

int list_push_back(TLinkedList *list, struct aluno al);
int list_push_front(TLinkedList *list, struct aluno al);
int list_insert(TLinkedList *list, int pos, struct aluno al);
int list_insert_sorted(TLinkedList *list, struct aluno al);

int list_print(TLinkedList *list);
int list_size(TLinkedList *list);