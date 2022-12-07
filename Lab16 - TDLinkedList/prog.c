#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDLinkedList.h"

int main(){

    struct aluno a,b,c,d;
    strcpy(a.nome,"Joao");
    a.matricula = 1;
    a.n1 = 0;    a.n2 = 2;    a.n3 = 0;

    strcpy(b.nome,"Maria");
    b.matricula = 2;
    b.n1 = 2;    b.n2 = 0;    b.n3 = 0;

    strcpy(c.nome,"Jose");
    c.matricula = 3;
    c.n1 = 0;    c.n2 = 0;    c.n3 = 4;

    strcpy(d.nome,"Ana");
    d.matricula = 4;
    d.n1 = 0;    d.n2 = 0;    d.n3 = 2;

    TDLinkedList *list;
    list = list_create();
    printf("Lista criada\n");
    list_push_front(list,a);
    list_push_front(list,b);
    list_push_front(list,c);
    list_push_back(list,d);
    //list_insert(list,1,a);
    printf("Elementos inseridos!\n");

    //list_print_forward(list);
   //list_print_reverse(list);
    TDLinkedList *lista;
    lista = list_create();

    list_insert(lista, 1, a); // teste na lista vazia <a>
    list_insert(lista,1,b); // teste com a lista com um elemento na primeira posição <b,a>
    list_insert(lista,2,c); // insere no meio <b,c,a>
    list_insert(lista,4,d); // insere no fim <b,c,a,d>
   // list_pop_back(lista);
   // list_pop_front(lista);
   // list_erase(lista, 1);

    list_print_forward(lista);

    struct aluno aluno_pos, aluno_mat, aluno_front, aluno_back;
    int pos_aluno;

    list_find_pos(lista, 1, &aluno_pos);
    printf("\nO aluno da posicao 1 eh: %s\n", aluno_pos.nome);
    list_find_mat(lista, 2, &aluno_mat);
    printf("\nO aluno da matricula 2 eh: %s\n", aluno_mat.nome);
    list_front(lista, &aluno_front);
    printf("\nO aluno 'front' eh: %s\n", aluno_front.nome);
    list_back(lista, &aluno_back);
    printf("\nO aluno 'back' eh: %s\n", aluno_back.nome);
    list_get_pos(lista, 3, &pos_aluno);
    printf("\nA posicao do aluno de nmat 3 eh: %d\n", pos_aluno);

   
    return 0;
}