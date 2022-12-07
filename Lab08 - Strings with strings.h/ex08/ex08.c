#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    char nome[50],cpf[50],rg[50],endereco[50],cep[50],cidade[50],estado[50];

    printf("Digite seu nome: ");
    gets(nome);
    printf("Digite seu CPF: ");
    gets(cpf);
    printf("Digite seu RG: ");
    gets(rg);
    printf("Digite seu endereco: ");
    gets(endereco);
    printf("Digite sua cidade: ");
    gets(cidade);
    printf("Digite seu estado: ");
    gets(estado);
    printf("Digite seu CEP: ");
    gets(cep);

    printf("\n\t\tD E C L A R A C A O\t\n\n");
    printf("Eu, %s, RG %s, CPF %s,\n residente a %s, %s-%s,\n CEP %s venho por meio desta declarar que vou estudar para a prova\n", nome,rg,cpf,endereco,cidade,estado,cep);

    return 0;

}