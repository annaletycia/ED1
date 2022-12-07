// programa principal

#include <stdio.h>
#include <stdlib.h>
#include "TMat.h"

int main(){

    TMat *p;
    TMat *p1;

    printf("Ola!\n");

// Criar TAD
    p = mat_create(4,4);
    p1 = mat_create(4,4);

    if(p==NULL){
        printf("Erro na alocacao da matriz!\n");
    }else{
        printf("Matriz criada com sucesso!\n");
    }
    if(p1==NULL){
        printf("Erro na alocacao da matriz!\n");
    }else{
        printf("Matriz criada com sucesso!\n");
    }


// Escrever elemento i, j
    if(mat_set_value(p, 1,1,3) == -1){
        printf("Erro! Posicao inexistente!\n");
    }else{
        printf("Atribuicao realizada com sucesso!\n");
    }
    if(mat_set_value(p1,1,1,5)==-1){
        printf("Erro! Posicao inexistente!\n");
    }else{
        printf("Atribuicao realizada com sucesso!\n");
    }


// Acessar elemento i, j
    double variavel;
    double variavel1;

    if(mat_get_value(p, 1, 1, &variavel) == -1){
        printf("Erro! Posicao invalida ou ponteiro nulo!\n");
    }else{
        printf("Elemento restaurado: %f\n", variavel);
    }
    if(mat_get_value(p1, 1, 1, &variavel1) == -1){
        printf("Erro! Posicao invalida ou ponteiro nulo!\n");
    }else{
        printf("Elemento restaurado: %f\n", variavel1);
    }


// Preencher matrizes
    if(mat_preenche(p)==-1){
        printf("Erro no preenchimento da matriz!\n");
    }else{
        printf("Preenchimento realizado com sucesso!\n");
    }
    if(mat_preenche(p1)==-1){
        printf("Erro no preenchimento da matriz!\n");
    }else{
        printf("Preenchimento realizado com sucesso!\n");
    }
    

// Somar matrizes
    TMat *soma = mat_soma(p,p1);

    if(soma == NULL){
        printf("Erro na alocacao da matriz, ou matrizes incompativeis!\n");
    }else{
        printf("Soma realizada com sucesso!\n");
    }


// Multiplicar matrizes
    TMat *multiplica = mat_multiplica(p, p1);

    if(multiplica == NULL){
        printf("Erro na alocacao da matriz, ou matrizes incompativeis!\n");
    }else{
        printf("Multiplicacao realizada com sucesso!\n");
    }


// Multiplicar matriz por um número escalar
    TMat *mult_esc = mat_mult_esc(p, 2);

    if(mult_esc == NULL){
        printf("Erro na alocacao da matriz, ou matrizes incompativeis!\n");
    }else{
        printf("Multiplicacao escalar realizada com sucesso!\n");
    }


//Calcular o Traço da matriz
    double traco = mat_traco(p1);

    if(traco == -1){
        printf("Erro! Matriz nula\n");
    }else{
        printf("Traco da matriz = %f\n", traco);
    }


//Retornar um vetor com a soma das linhas
    double *vetor = mat_somalinhas(p);

    if(vetor == NULL){
        printf("Erro! Matriz ou vetor nulo!\n");
    }else{
        printf("Soma das linhas realizada com sucesso!\n");
    }


//Retornar um vetor com a soma das colunas
    double *vetor1 = mat_somalinhas(p1);

    if(vetor1 == NULL){
        printf("Erro! Matriz ou vetor nulo!\n");
    }else{
        printf("Soma das colunas realizada com sucesso!\n");
    }


//Liberando os vetores   
    if(vet_free(vetor)==-1 || vet_free(vetor1) == -1){
        printf("Vetor nulo!\n");
    }else{
        printf("Vetores eliminados com sucesso!\n");
    }
    

// Destruir TAD
    if(mat_free(p)==-1|| mat_free(p1)==-1 || mat_free(soma)==-1 || mat_free(multiplica)==-1 || mat_free(mult_esc)==-1){
        printf("Erro! Matriz nula!\n");
    }else{
        printf("Matrizes eliminadas com sucesso!\n");
    }

return 0;
}
