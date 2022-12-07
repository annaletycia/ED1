#include "TMatQuad.h"
#include <stdlib.h>

struct TMatQuad
{
    int *dados;
    int ordem; // ordem indica o tamanho da matriz. Por exemplo, ordem 3 indica uma matriz 3x3
};

TMatQuad* cria_matquad(int ordem){

}

void libera_matquad(TMatQuad *mat){

}

TMatQuad* cria_mat_identidade(int ordem){
    TMatQuad *mat = malloc(sizeof(TMatQuad));
    if(mat == NULL){
        return NULL;
    }else{
      mat->ordem = ordem;
      mat->dados = malloc(ordem*ordem*sizeof(int));
      if(mat->dados == NULL){
          free(mat);
          return NULL;
      }
      for(int i=0; i<mat->ordem*mat->ordem; i++){
        if(i==0 || i%(mat->ordem+1)==0)
            mat->dados[i] = 1;
    /*    if(i==0 || i%4==0)// check:<<<erro: pq %4?>>>>
            mat->dados[i] = 1;// check:<<<erro: faltou zerar posições fora da diagonal>>>>
        */
        else
            mat->dados[i] = 0;
      }}
    return mat;
}

int *copia_diagonal(TMatQuad *mat)
{
    if(mat == NULL)
        return NULL;
    
    int *vetor = malloc(mat->ordem * sizeof(int));
        if(vetor == NULL)
            return NULL;
    
    int k = 0;
    for(int i=0; i<(mat->ordem*mat->ordem); i++){
            if(i==0 || i%4==0){
                vetor[k] = mat->dados[i];
                k++;
        }
    }
    return vetor;

}