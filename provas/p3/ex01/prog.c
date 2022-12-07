#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDLinkedList.h"

int main(){

    struct aluno a,b,c,d;
    strcpy(a.nome,"Joao");
    a.matricula = 1;
    a.n1 = 0;    a.n2 = 0;    a.n3 = 0;

    strcpy(b.nome,"Maria");
    b.matricula = 2;
    b.n1 = 2;    b.n2 = 1;    b.n3 = 1;

    strcpy(c.nome,"Jose");
    c.matricula = 3;
    c.n1 = 3;    c.n2 = 2;    c.n3 = 4;

    strcpy(d.nome,"Ana");
    d.matricula = 4;
    d.n1 = 7;    d.n2 = 4;    d.n3 = 2;

    TDLinkedList *list;
    list = list_create();

    list_insert(list, 1, a); // teste na lista vazia <a>
    list_insert(list,1,b); // teste com a lista com um elemento na primeira posição <b,a>
    list_insert(list,2,c); // insere no meio <b,c,a>
    list_insert(list,4,d); // insere no fim <b,c,a,d>

    list_print_forward(list);
    printf("\nRemovendo alunos com zero em todas as notas:\n");
    list_erase_zeros(list);
    list_print_forward(list);

    TDLinkedList *lista;
    lista = list_create();

    list_insert(lista, 1, a);
    list_insert(lista,1,b); 
    list_insert(lista,2,c); 
    list_insert(lista,4,d);

//    list_splice(list,lista,1); //splice no começo da lista
//    list_print_forward(list);
//    list_splice(list,lista,2); //splice no meio da lista
//    list_print_forward(list);
      list_splice(list,lista,4); //splice no fim da lista
      list_print_forward(list);

    list_free(list);
    list_free(lista);
    lista = NULL;
    list = NULL;
    return 0;
}