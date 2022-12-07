#include <stdio.h>
#include <stdlib.h>
#include "TGrafico.h"

struct TGrafico
{
    int qtd;
    struct ponto ptos[MAX];
    char nome_eixo_x[100];
    char nome_eixo_y[100];
    char titulo[100];
};


TGrafico* cria_grafico(){

}

void apaga_grafico(TGrafico* li){
}

int definir_nomes_eixos(TGrafico* li, char *eixo_x, char *eixo_y){
}

int definir_titulo(TGrafico* li, char *titulo){
}

int insere_ponto_inicio(TGrafico* li, struct ponto pto){
}

int insere_ponto_fim(TGrafico* li, struct ponto pto){
}

int mostrar_grafico(TGrafico* li){

}

int maior_valor_y(TGrafico *li, float *valY, float *valX){
    if(li == NULL || li->qtd == 0){
        return -1;
    }// check:<<<erro: e2.2 faltou testar se a lista está vazia E/OU faltou testar se a lista é null>>>>

    float maiorY = li->ptos[0].y;
    float X = li->ptos[0].x;

    for(int i=1; i < MAX; i++){
        if(li->ptos[i].y > maiorY){
            maiorY = li->ptos[i].y;
            X = li->ptos[i].x;
        }
    }
    *valY = maiorY;
    *valX = X;

    return 0;
// check:<<<erro: e2.4a falta retorno da função>>>>
}

int insere_pos(TGrafico *li, int pos, float x, float y){
    if( li == NULL || li->qtd == MAX|| pos < 0 || pos > MAX){
        return -1;
    }
    if(pos <= li->qtd){
        for(int k = li->qtd-1; k > pos-1; k--){
            li->ptos[k+1].x = li->ptos[k].x;
            li->ptos[k+1].y = li->ptos[k].y;
        }
        li->ptos[pos - 1].x = x;
        li->ptos[pos - 1].y = y;
        li->qtd++;
        return 0;
    }else{
        li->ptos[pos - 1].x = x;
        li->ptos[pos - 1].y = y;
        int cont = 0;
        for(int j = pos-2; j>li->qtd-1; j--){
            li->ptos[j].x = 0;
            li->ptos[j].y = 0;
            cont++;
        }
        li->qtd += 1 + cont;
        return 0;
    }
}
