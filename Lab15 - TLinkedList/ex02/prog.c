#include <stdio.h>
#include "TSULinkedList.h"
#include <string.h>

int main(){

    TLinkedList *list = list_create(0);
    if(list == NULL){
        printf("Erro na criacao da lista!\n");
    }
    printf("\nLista nao ordenada criada!\n");
    struct aluno a,b,c,d;
    a.matricula = 1;
    strcpy(a.nome,"Joao");
    a.n1 = 4;       a.n2 = 0;       a.n3 = 0;

    b.matricula = 2;
    strcpy(b.nome,"Caio");
    b.n1 = 2;       b.n2 = 0;       b.n3 = 0;

    c.matricula = 3;
    strcpy(c.nome,"Laura");
    c.n1 = 3;       c.n2 = 0;       c.n3 = 0;

    d.matricula = 4;
    strcpy(d.nome,"Jose");
    d.n1 = 5;       d.n2 = 0;       d.n3 = 0;

    list_insert(list, 1, d);
    list_insert(list, 2, c);
    list_insert(list, 3, b);
    list_insert(list, 4, a);

    list_print(list);
    list_free(list);
    list = NULL;
    
    TLinkedList *listord = list_create(1);
    if(listord == NULL){
        printf("Erro na criacao da lista!\n");
    }
    printf("\nLista ordenada criada!\n");

    list_insert_sorted(listord, b);
    list_insert_sorted(listord, a);
    list_insert_sorted(listord, c);
    list_insert_sorted(listord, d);

    list_print(listord);
    list_erase_pos(listord, 4);
    list_erase_data(listord, 1);
    list_print(listord);
    
    struct aluno al;
    list_find_pos(listord, 1, &al);
    printf("Aluno da posicao 1: %s\n", al.nome);
    struct aluno alu;
    list_find_mat(listord, 3, &alu);
    printf("\nAluno da matricula 3: %s\n", alu.nome);
    struct aluno alun;
    list_front(listord, &alun);
    printf("\nPrimeiro elemento da lista: %s\n", alun.nome);
    struct aluno aluno;
    list_back(listord, &aluno);
    printf("\nUltimo elemento da lista %s\n", aluno.nome);
    int pos;
    list_get_pos(listord, 3, &pos);
    printf("\nO aluno da matricula 3 esta na posicao: %d\n", pos);

    list_free(listord);
    listord = NULL;

    return 0;
}