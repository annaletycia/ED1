#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "CTMat2D.h"

struct TMat2D
{
  int nrows; // nÃºmero de linhas
  int ncolumns; // nÃºmero de colunas
  double *data; // ponteiro para os dados da matriz
};

// mat = mat2D_create(4,3);

TMat2D *mat2D_create(int nrows, int ncolumns){
    TMat2D *mat;
    mat = malloc(sizeof(TMat2D));
    if (mat != NULL){
        mat->data = malloc(nrows*ncolumns*sizeof(double));
        if (mat->data != NULL){
            mat->ncolumns = ncolumns;
            mat->nrows = nrows;
        } else {
            free(mat);
            return NULL;
        }
    }
    return mat;
}

//Destruir matriz
int mat2D_free(TMat2D *mat){
    if(mat==NULL)
    return -1;
    free(mat->data);
    free(mat);
    return 0;
}

// Escrever elemento i, j
int mat2D_set_value(TMat2D *mat, int i, int j, double val){
    int pos;
    pos = j*mat->ncolumns+i;
    mat->data[pos] = val;
    return 0;
}

// Acessar elemento i, j
int mat2D_get_value(TMat2D *mat, int i, int j, double *val){
    int pos;
    pos = j*mat->ncolumns+i;
    *val = mat->data[pos];
    return 0;
}

// Preencher com numeros aleatorios
int matriz_aleatoria(TMat2D *mat, int min, int max){
    for(int cont = 0; cont < mat->nrows*mat->ncolumns; cont++){
        mat->data[cont] = min + (rand() % max);
    }
    return 0;
}
// Somar duas matrizes
int matriz_sum(TMat2D *mat1, TMat2D *mat2, TMat2D *sum, int i, int j){
    if(mat1->ncolumns!=mat2->ncolumns||mat1->nrows!=mat2->nrows){
        return -1;
    }
    for(int cont = 0; cont < i*j; cont++){
        sum->data[cont] = mat1->data[cont] + mat2->data[cont];
    }
    return 0;
}

// Multiplicar duas matrizes
int matriz_multiplication(TMat2D *mat1, TMat2D *mat2, TMat2D *mult, int i, int j){
    if(mat1->ncolumns!=mat2->ncolumns||mat1->nrows!=mat2->nrows){
        return -1;
    }
    for(int cont = 0; cont < i*j; cont++){
        mult->data[cont] = mat1->data[cont] * mat2->data[cont];
    }
    return 0;
}

// Multiplicar por um valor escalar
int matriz_multiplication_escalar(TMat2D *mat, TMat2D *mult, double val){
    if(mat == NULL){
        return -1;
    }else{
        for(int cont = 0; cont < mat->ncolumns*mat->nrows; cont++){
            mult->data[cont] = mat->data[cont] * val;
        }
    return 0;
    }
}

// TraÃ§o da Matriz
int matriz_traco(TMat2D *mat, double *sum){
    for(int cont = 0; cont < mat->nrows; cont++){
        *sum += mat->data[cont * mat->ncolumns+cont];
    }
    return 0;
}

// Soma das linhas
int matriz_soma_linhas(TMat2D *mat, double *sum){
    if(mat==NULL)
    return -1;

    for(int i = 0; i<mat->nrows; i++){
        sum[i] = 0;
        for(int j = 0; j<mat->ncolumns; j++){
            sum[i] = sum[i] + mat->data[j*mat->nrows+i];
        }
    }
    return 0;
}

// Soma das colunas
int matriz_soma_colunas(TMat2D *mat, double *sum){
    if(mat==NULL)
    return -1;

    for(int j = 0; j<mat->ncolumns; j++){
        sum[j] = 0;
        for(int i = 0; i<mat->nrows; i++){
            sum[i] = sum[i] + mat->data[j*mat->nrows+i];
        }
    }
    return 0;
}

// Retornar numero de linhas
int return_nrows(TMat2D *mat, int i){
    if(mat == NULL)
    return -1;

    i = mat->nrows;
    return i;
}

// Retornar numero de colunas
int return_ncolumns(TMat2D *mat, int j){
    if(mat == NULL)
    return -1;

    j = mat->ncolumns;
    return j;
}

void print_matriz(TMat2D *mat){
    printf("Imprimindo matriz...\n");
    for(int i = 0; i < mat->nrows; i++){
        for(int j = 0; j < mat->ncolumns; j++){
            printf("%.lf ", mat->data[j*mat->ncolumns+i]);
        }
        printf("\n");
    }
}