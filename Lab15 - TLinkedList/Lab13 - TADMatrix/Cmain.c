#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "CTMat2D.h"

int main(){
    TMat2D *mat;
    TMat2D *alt;
    TMat2D *mat2;
    TMat2D *sum;
    TMat2D *mult;
    TMat2D *esc;
    int i, j;
    int min = 1, max = 10;
    double val = 1;
    double val2 = 1;
    double val3 = 2;

    printf("--------- CRIANDO MATRIZ 1 E COLOCANDO VALORES DE 1 A 100 ---------\n");
    mat = mat2D_create(10, 10);
    if (mat==NULL){
        printf("Erro na alocacao da matriz\n");
    } else{  
        printf("Matriz alocada\n");
        for(i = 0; i < 10; i++){
            for(j = 0; j < 10; j++){
                mat2D_set_value(mat, i, j, val);
                val++;
            }
        }
        print_matriz(mat);
    }


    printf("--------- CRIANDO MATRIZ 2 E COLOCANDO VALORES DE 1 A 100 ---------\n");
    mat2 = mat2D_create(10, 10);
    if (mat2==NULL){
        printf("Erro na alocacao da matriz\n");
    } else{  
        printf("Matriz alocada\n");
        for(i = 0; i < 10; i++){
            for(j = 0; j < 10; j++){
                mat2D_set_value(mat2, i, j, val2);
                val2++;
            }
        }
        print_matriz(mat2);
    }

    printf("--------- SOMANDO MATRIZ 1 E 2 ---------\n");
    sum = mat2D_create(10, 10);
    if (sum==NULL){
        printf("Erro na alocacao da matriz\n");
    } else{  
        printf("Matriz alocada\n");
        matriz_sum(mat, mat2, sum, i, j);
        print_matriz(sum);
    }

    printf("--------- MULTIPLICANDO MATRIZ 1 E 2 ---------\n");
    mult = mat2D_create(10, 10);
    if (mult==NULL){
        printf("Erro na alocacao da matriz\n");
    } else{  
        printf("Matriz alocada\n");
        matriz_multiplication(mat, mat2, mult, i, j);
        print_matriz(mult);
    }

    printf("--------- MULTIPLICANDO MATRIZ 1 POR VALOR ESCALAR ---------\n");
    esc = mat2D_create(10, 10);
    if (esc==NULL){
        printf("Erro na alocacao da matriz\n");
    } else{  
        printf("Matriz alocada\n");
        matriz_multiplication_escalar(mat, esc, val3); //val3 = 2
        print_matriz(esc);
    }

    printf("--------- CRIANDO MATRIZ ALEATORIA E COLOCANDO VALORES DE 1 A 10 ---------\n");
    alt = mat2D_create(10, 10);
    if (alt==NULL){
        printf("Erro na alocacao da matriz\n");
    } else{  
        printf("Matriz aleatoria alocada\n");
        for(i = 0; i < 10; i++){
            for(j = 0; j < 10; j++){
                matriz_aleatoria(alt, min, max);
            }
        }
        print_matriz(alt);
    }

    mat2D_free(mat);
    mat2D_free(mat2);
    mat2D_free(sum);
    mat2D_free(mult);
    mat2D_free(esc);
    mat2D_free(alt);

    return 0;
}