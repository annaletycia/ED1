#include <stdio.h>
#include <stdlib.h>

int main(){

double *produtos; 
int n, i;

printf("Informe o numero de produtos: "); 
scanf("%d", &n);

// é necessário usar o comando malloc para alocar a memória
produtos = (double *)malloc(n*sizeof(double));   

for   (i = 0; i < n; i++)
{
    printf("Informe o valor do produto %d R$:",i+1);
    scanf("%lf", &produtos[i]);
} 

printf("\nProdutos cadastrados\n" );  

for   (i = 0; i < n; i++)
{
    printf("Produto %d  - R$: %f\n" ,i+1, produtos[i]); 
} 

// ao terminar de usar o vetor, devemos liberar a memória

free(produtos);

return 0;
}

//O valor de n indica a quantidade de elementos que serao inicializados e o sizeof calcula o espaço necessario para alocar esses elementos variando de acordo com o tipo da variavel, nesse caso o tipo é double, ou seja, ele multipllica a quantidade de elementos pelo tamanho de espaço ocupado pelo double (n*8bytes).

/*
1) Alocação dinâmica: outra utilidade dos ponteiros é que eles permitem 
fazermos o que é chamado de alocação dinâmica. Isso significa que podemos 
reservar espaços de memória enquanto estamos executando o programa. Seria
como criar variáveis com o programa executando. Por exemplo, considere um
vetor que armazenará o preço de produtos. Não sabemos quantos produtos serão
cadastradas enquanto estamos programando. Podemos fazer alocação dinâmica 
para resolver este problema. Implemente o programa abaixo, teste para diferentes
valores de n e discuta o que significa o valor de n e de sizeof(double) no 
commando malloc(n*sizeof(double)).


---------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>


int main(void){
 double *produtos;
 int n,i;

 printf("Informe o número de produtos: ");
  scanf("%d",&n);
  // é necessário usar o comando malloc para alocar a memória
  produtos = (double *)malloc(n*sizeof(double));

  for   (i = 0; i < n; i++){
    printf("Informe o valor do produto %d R$: ",i+1);
    scanf("%lf", &produtos[i]);
  } 

  printf("\nProdutos cadastrados\n" );
  for   (i = 0; i < n; i++){
    printf("Produto %d  - R$: %.2f\n" ,i+1, produtos[i]);
  }
  
  // ao terminar de usar o vetor, devemos liberar a memória
  free(produtos);

  return 0;
}
---------------------------------------------------------------

Suas considerações:

Quais foram os valores de n testados?
> 3, 5 e 10

O que significa o valor de n?
> O valor de n indica a quantidade de elementos que serao inicializados e armazenados pelo malloc.

o que significa o valor de sizeof(double) no commando malloc(n*sizeof(double)).
> O sizeof(double) retorna o número de bytes ocupados pelo double, esse valor na função malloc indica o espaço que será alocado em um bloco de
bytes consecutivos na memória RAM do computador, isso é realizado pela multipllicação da quantidade de elementos pelo tamanho de espaço ocupado 
pelo double (n*8bytes).

*/