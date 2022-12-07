#include <stdio.h>
#include "TGrafico.h"
#include "TMatQuad.h"
#include <stdlib.h>

int main(){

//(1)
    int n;
    char nome_x[30], nome_y[30], titulo[30];
    TGrafico *graf = cria_grafico();
    struct ponto *p; // = malloc(sizeof(struct ponto));// check:<<<erro: e1.5 Não precisa alocar um vetor só para ler todos os pontos. A própria lista da estrutura é quem armazena os pontos>>>>

    printf("Digite o nome do eixo x: ");
    scanf("%s", nome_x);
    printf("Digite o nome do eixo y: ");
    scanf("%s", nome_y);
    definir_nomes_eixos(graf, nome_x, nome_y);
    printf("Digite o nome do Titulo: ");
    scanf("%s", titulo);
    definir_titulo(graf, titulo);
    printf("Digite quantos pontos deseja inserir na lista: ");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        printf("Digite a coordenada (x) do ponto %d: ", i+1);
        scanf("%f", &p[i].x);
        printf("Digite a coordenada (y) do ponto %d: ", i+1);
        scanf("%f", &p[i].y);
        insere_ponto_fim(graf, p[i]);
    }

    mostrar_grafico(graf);

// (2)
    float maiorY, X;
    if(maior_valor_y(graf, &maiorY, &X) == -1){
        printf("Erro! Lista invalida!\n");
    }else{
        printf("Maior valor de y: %d (coordenadas: (%f,%f)\n", maiorY, X, maiorY);
    }


// (3)
    int pos;
    float x, y;

    printf("Digite a posição em que o ponto será inserido: ");
    scanf("%d", &pos);
    printf("Digite a coordenada (x) do ponto %d: ", pos);
    scanf("%f", &x);
    printf("Digite a coordenada (y) do ponto %d: ", pos);
    scanf("%f", &y);

    if(insere_pos(graf,pos,x,y) == -1){
        printf("Erro! Lista ou posicao invalida!\n");
    }else{
        printf("Posicao inserida!\n");
    }

//(4)
    int ordem;
    printf("Qual a ordem de sua matriz?");
    scanf("%d", ordem);

    TMatQuad *mat = cria_mat_identidade(ordem);


//(5)
    int *vetor = copia_diagonal(mat);
    if(vetor == NULL){
        printf("Erro! Vetor ou matriz invalido(s)!\n");
    }

    apaga_grafico(graf);
    libera_matquad(mat);
    free(p);
    
    return 0;
}