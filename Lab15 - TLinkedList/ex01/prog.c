#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TLinkedList.h"

int main(){
    TLinkedList *list;
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


    list = list_create();
    if (list == NULL){
       printf("ERRO!");
       exit(1);
    } 

    int ret;
    ret = list_push_back(list, a);
    if (ret == INVALID_NULL_POINTER)
      printf("Erro de ponteiro");
    else if (ret == OUT_OF_MEMORY)
      printf("Memoria insuficiente");
    else if (ret == SUCCESS)
      printf("Aluno inserido");

    list_push_front(list, b);
    list_push_back(list, c);
    list_push_back(list, d);        
    
    list_push_back(list, b);
    list_push_back(list, c);
    list_push_back(list, d);        
 
// joao / maria / jose / ana

// maria -> joao ->jose ->ana

    printf("\nO nome do aluno na posicao 3 eh: ");
    struct aluno al;
    list_find_pos(list, 3, &al);
    printf("%s\n", al.nome);

    printf("\nO nome do aluno da matricula 1 eh: ");
    struct aluno alu;
    list_find_mat(list, 1, &alu);
    printf("%s\n", al.nome);

    //list_print(list);
    int tam = list_size(list);
    printf("\nTamanho da lista: %d\n\n", tam);
    list_free(list);
    list = NULL;
  
    TLinkedList *listord;
    listord = list_create();
    list_insert_sorted(listord,c); //teste na lista vazia
    list_insert_sorted(listord,a); //teste na cabeçã da lista
    list_insert_sorted(listord,b); //teste no meio da lista
    list_insert_sorted(listord,d); //teste no final da lista
    //list_print(listord);

    list_erase_pos(listord, 1);
    list_erase_data(listord, 2);
    list_erase_data(listord, 3);
    list_erase_data(listord,4);

    list_insert(listord,2, a);
     
    list_print(listord);

    list_free(listord);
    listord = NULL;

    return 0;
}