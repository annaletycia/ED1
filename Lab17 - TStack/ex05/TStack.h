#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4

typedef struct TStack TStack;
typedef struct TStackNum TStackNum;

TStack *stack_create();
TStackNum *stack_num_create();
int stack_push(TStack *st, char s);
int stack_num_push(TStackNum *st, int s);
int stack_pop(TStack *st);
int stack_num_pop(TStackNum *st);
int stack_top(TStack *st,char *top);
int stack_num_top(TStackNum *st,int *top);
int stack_empty(TStack *st);
int stack_size(TStack *st);
int stack_print(TStack *st);
char *InfixToPostfix(TStack *st, char *infix);