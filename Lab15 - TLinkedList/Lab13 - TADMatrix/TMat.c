// codificaçao do TAD

#include "TMat.h" //inclui os protótipos
#include <stdlib.h> //uso do malloc
#include <time.h> //biblioteca do srand

//Definição do tipo TMat
struct TMat 
{
    int nrows; //numero de linhas
    int ncolumns; //numero de colunas
    double *data; //ponteiro para os dados da matriz
};

// Descrição:
// Função que cria a matriz por meio do numero de linhas e colunas
// Retorno:
// Retorna o endereço de memória da matriz criada dinamicamente
TMat *mat_create(int nrow, int ncol){

    TMat *mat = malloc(sizeof(TMat));
    if(mat == NULL){
        return NULL;
    }

    mat->nrows = nrow;
    mat->ncolumns = ncol;
    mat->data = (double *)malloc(nrow*ncol*sizeof(double));
    if(mat->data == NULL){
        free(mat);
        return NULL;
    }
    
    return mat;
}

// Descrição:
// Função que libera o espaço ocupado pela matriz criada
// Retorno:
// retorno -1: codigo de erro
// retorno 0:  codigo de sucesso
int mat_free(TMat* mat){
    
    if(mat == NULL){
        return -1;
    }else{
    free(mat->data);
    free(mat);
    return 0;
    }
}

// Descrição:
// Função que atribui um valor em determinada linha e coluna da matriz
// Recebe a matriz, a posição (linha e coluna) e o valor a ser colocado em tal posiçao
// Retorno:
// retorno -1: codigo de erro
// retorno 0:  codigo de sucesso
int mat_set_value(TMat *mat, int i, int j, double val){

    if(mat == NULL){
        return -1;
    }
    int pos; //indice do elemento no vetor (posicao)
    if(i < 0 || i >= mat->nrows || j < 0 || j >= mat->ncolumns){
        return -1;
    }else{
        pos  = j * (mat->nrows) + i; //expressao que identifica a posicao da matriz no array data
        mat->data[pos] = val; //alocaçao do valor na posiçao indicada no array data
        return 0;
    }
}

// Descrição:
// Função que acessa o um valor em determinada linha e coluna da matriz e passa por referência para uma variavel na main
// Recebe a matriz, a posição (linha e coluna) e o endereço da variavel que receberá o valor
// Retorno:
// retorno -1: codigo de erro
// retorno 0:  codigo de sucesso
int mat_get_value(TMat *mat, int i, int j, double *val){

    if(mat == NULL || val == NULL){
        return -1;
    }

    if(i < 0 || i >= mat->nrows || j < 0 || j >= mat->ncolumns){

        return -1;
    }
    else{

        int pos = j * mat->nrows + i; //expressao que identifica a posicao da matriz no array data
        *val = mat->data[pos];

        return 0;
    }
}

// Descrição:
// Função que recebe uma matriz e a preenche com números aleatórios entre um valor mínimo(zero) e máximo(100)
// Retorno:
// retorno -1: codigo de erro
// retorno 0:  codigo de sucesso
int mat_preenche(TMat *mat){
    
    if(mat == NULL){
        return -1;
    }else{
        int k;
        int maxL = mat->nrows;
        int maxC = mat->ncolumns;
        srand(time(NULL)); 
            for (int j = 0; j < maxC; j++) {
                for (int i = 0; i < maxL; i++) {     
                    k = j * mat->nrows + i;
                    mat->data[k] = (rand()/(double)RAND_MAX)*100;             
                }   
            }
            if(mat->data == NULL){
                 free(mat);
                 return -1;
            }else{
                return 0;
            }
    }
}

// Descrição:
// Função que soma duas matrizes 
// Retorno:
// Retorna o endereço da nova matriz criada pela soma das duas indicadas na chamada da função
// Retorna NULL em caso de erro
TMat* mat_soma(TMat* mat, TMat* mat1){

    if(mat == NULL || mat1 == NULL){
        return NULL;
    }

    if(mat->nrows != mat1->nrows || mat->ncolumns != mat1->ncolumns)
    {
        return NULL;
    }else{
            TMat *soma;
            soma = mat_create(mat->nrows,mat->ncolumns);
                for (int j = 0; j < soma->ncolumns; j++) {
                    for (int i = 0; i < soma->nrows; i++) {                           
                        int k = j * soma->nrows + i;
                        soma->data[k] = mat->data[k] + mat1->data[k];            
                    }
                }
            return soma;
     }
}

// Descrição:
// Função que multiplica duas matrizes 
// Retorno:
// Endereço da nova matriz criada pela multiplicação das duas indicadas na chamada da função
// Retorna NULL em caso de erro
TMat *mat_multiplica(TMat *mat, TMat *mat1){

    if(mat == NULL || mat1 == NULL){
        return NULL;
    }

    if(mat->ncolumns != mat1->nrows){
        return NULL;
    }
    else{
        TMat *mult = mat_create(mat->nrows, mat1->ncolumns);
        double val = 0;
            for(int i = 0; i < mult->nrows; i++){
                for(int j = 0; j < mult->ncolumns; j++){
                    for(int k = 0; k < mat->ncolumns; k++){
                        int pos = k * mat->nrows + i;
                        int pos1 = j * mat1->nrows + k;
                        val = val + mat->data[pos] * mat1->data[pos1];
                    }
                    int posMult = j * mult->nrows + i;
                    mult->data[posMult] = val;
                    val = 0;
                }
            }
    return mult;
    }
}

// Descrição:
// Função que multiplica uma matriz por um valor escalar
// Retorno:
// Retorna o endereço da matriz que resulta da multiplicação dela por um valor escalar
// Retorna NULL em caso de erro
TMat *mat_mult_esc(TMat *mat, double num){
    if(mat == NULL){
        return NULL;
    }else{
        TMat *mult_esc = mat_create(mat->nrows,mat->ncolumns);
        if (mult_esc == NULL){
            return NULL;
        }
        for(int j=0; j < mult_esc->ncolumns; j++){
            for(int i=0; i < mult_esc->nrows; i++){
                int pos = j * mult_esc->nrows + i;
                mult_esc->data[pos] = mat->data[pos] * num;
            }
        }
        return mult_esc;
    }
}

// Descrição:
// Função que recebe uma matriz e calcula seu Traço
// Retorno:
// Retorna o valor do Traço da matriz
// Retorna -1 em caso de erro
double mat_traco(TMat *mat){
    if(mat == NULL){
        return -1;
    }else{
        double traco = 0;
        for(int j=0; j < mat->ncolumns; j++){
            for(int i=0; i < mat-> nrows; i++){
                        if(i == j){
                        int pos = j * mat->nrows + i;                    
                        traco = traco + mat->data[pos];
                    }
            }
        }
    return traco;
    } 
}

// Descrição:
// Função que recebe uma matriz e realiza a soma das linhas dela
// Retorno:
// Retorna o vetor contendo a soma de cada linha da matriz
// Retorna NULL em caso de erro
double *mat_somalinhas(TMat *mat){
    if(mat == NULL){
        return NULL;
    }else{
        double *vetor = malloc(mat->nrows * sizeof(double));
        if(vetor == NULL){
            return NULL;
        }else{
            int soma = 0;
            for(int i=0; i < mat->nrows; i++){
                for(int j=0; j < mat->ncolumns; j++){
                    int pos = j * mat->nrows + i;
                    soma = soma + mat->data[pos];
                    vetor[i] = soma;
                }           
            }
        }
        return vetor;
    }
}

// Descrição:
// Função que libera os vetores alocados
// Retorno:
// retorna 0 - codigo de sucesso
// retorna -1 - codigo de erro
int vet_free(double *vet){
    if(vet == NULL){
        return -1;
    }else{
        free(vet);
        return 0;
    }
}

// Descrição:
// Função que recebe uma matriz e realiza a soma das colunas dela
// Retorno:
// Retorna o vetor contendo a soma de cada coluna da matriz
// Retorna NULL em caso de erro
double *mat_somacolunas(TMat *mat){
    if(mat == NULL){
        return NULL;
    }else{
        double *vetor = malloc(mat->ncolumns * sizeof(double));
        if(vetor == NULL){
            return NULL;
        }else{
            int soma = 0;
            for(int i=0; i < mat->ncolumns; i++){
                for(int j=0; j < mat->nrows; j++){
                    int pos = j * mat->nrows + i;
                    soma = soma + mat->data[pos];
                    vetor[i] = soma;
                }           
            }
        }
        return vetor;
    }
}