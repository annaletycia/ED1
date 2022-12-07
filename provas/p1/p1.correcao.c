#include <stdio.h>
#include <stdlib.h>
/*
--- Instruções da prova--- 
Qualquer exercício copiado de um colega ou da internet implicará nota zero em toda a prova,
 mesmo que a cópia seja feita somente de um trecho

A nota será zerada tanto para quem deixou copiar quanto para quem fez a cópia.

Não enviar o enunciado nem as respostas para os colegas

Não haverá checagem de exercício correto. 

Formate a saída de seu programa da melhor forma possível. Por exemplo, se o exercício
pede para informar o valor de um produto, escreva no printf um texto que seja adequado 
ao que for pedido:

Forma correta 
Digite o preço do produto 1: 20
Digite o preço do produto 2: 50.6

Forma errada
20
produto: 50.6

Fique atento também à saída gerada pelo programa. Escreva textos contextualizando os cálculos 
realizado e não somente mostre número Por exemplo:

Forma correta
O consumo de gasolina no mês 5 foi 50L – valor alto
O consumo de gasolina no mês 2 foi 20L – valor baixo

Forma errada
50L
50L – alto
*/



// Fazer um programa para cadastro de carros. As informações para cadastro são: 
// modelo (ex: gol, ka, c3), o ano (ex: 1999, 2015, 2021) e o consumo (ex: 10 Km/l, 7 km/l, 16 Km/l)
// Verificar no main() abaixo os exercícios da prova


// Definir as estruturas necessárias aqui:
typedef struct cadastro{

    char modelo[50];
    int ano;
    float consumo;

}Cadastro;

// Função: Busca Maior Consumo (ex02)
// Essa função retorna o carro de maior consumo
// Entrada: todos os carros cadastrados 
// Saída: índice do vetor indicando a posição de maior valor
// (se houver empate pode ser retornado qualquer um dos carros)
int busca_maior_consumo(Cadastro *x, int n){

    float maior = x[0].consumo;
    int maior_indice = 0;

    for(int i=n; i>0; i--)
    {
        if(x[i].consumo < maior)
        {
            maior = x[i].consumo;
            maior_indice = i;
        }
    }
    return maior_indice;
}

// Função: Índice de Eficiência (ex03)
// Essa calcula a eficiência energética de um carro
// o índice de eficiência é calculado usando a seguinte fórmula
//
//                                 ano_veiculo - 1991
//   ind = consumo (em km/l)  *  ---------------------            
//                                        30                   
//
// A função deve retornar um valor inteiro de acordo com a classificação listada na tabela abaixo.
// Valores inválidos correspondem a números negativos, zeros e ano menor que 1980 e maior que 2021
// Todos os comandos de entrada e saída devem estar no programa principal
// Todos os cálculos devem ser feitos na função.

/*
+-------------------+-----------------------------------------------+----------------+
| Retorno da Função | Valor do índice de eficiência                 | Classificação  |
+-------------------+-----------------------------------------------+----------------+
| -1                | -                                             | Valor invalido |
+-------------------+-----------------------------------------------+----------------+
| 1                 | acima ou igual 10                             | A              |
+-------------------+-----------------------------------------------+----------------+
| 2                 | acima ou igual a 8,8 e menor que 10           | B              |
+-------------------+-----------------------------------------------+----------------+
| 3                 | acima ou igual a 7,5 e menor que 8,8          | C              |
+-------------------+-----------------------------------------------+----------------+
| 4                 | abaixo de 7,5                                 | D              |
+-------------------+-----------------------------------------------+----------------+

*/
int eficiencia(Cadastro *p, int i){

    if(p[i].ano < 1980)
    {
        return -1;
    }

    float ind = p[i].consumo * ((p[i].ano - 1991)/30.0);

    if(ind >= 10)
    {
        return 1;
    }
    if(ind >= 8.8 && ind < 10.0)
    {
        return 2;
    }
    if(ind >= 7.5 && ind < 8.8)
    {
        return 3;
    }
    if(ind < 7.5)
    {
        return 4;
    }
    else
    {
        return -1;
    }
}

// Função: Busca Maior Consumo - retorno Ponteiro (ex05)
// Essa função retorna o carro de maior consumo
// Entrada: todos os carros cadastrados 
// Saída: ponteiro para posição de vetor de maior valor
// (se houver empate pode ser retornado qualquer um dos carros)
float *busca_maior_consumoP(Cadastro *x, int n){

    float *maior;
    float maior_consumo = x[0].consumo;

        for(int i=1; i<n; i++)
        {
            if(x[i].consumo > maior_consumo)
            {
                maior_consumo = x[i].consumo;
                maior = &x[i];
            }
        }

    return maior;
}

 typedef struct CRLV{
       
       char nome[50];
       char cpf[20];
       Cadastro info;

 }CRLV;


int main(){

    // Ex 01: permitir que o usuário cadastre quantos carros desejar
    //  - ler do teclado a quantidade de carros que o usuário escolheu
    //  - ler do teclado as informações dos carros 
    int n;
    Cadastro *p;

    printf("Informe quantos carros deseja cadastrar: ");
    scanf("%d", &n);

    p = (Cadastro *)malloc(n*sizeof(Cadastro));
    if(p==NULL)
    {
        printf("Memoria insuficiente!\n");
        system("pause");
    }

       for(int i=0; i<n; i++)
       {
        printf("\nQual o modelo do carro (%d): ", i+1);
        scanf("%s", p[i].modelo);
        printf("Qual o ano do carro (%d): ",i+1);
        scanf("%d", &p[i].ano);
        printf("Qual o consumo do carro (%d): ", i+1);
        scanf("%f", &p[i].consumo);
        }
        
        // Ex02: utilizando a função de buscar o maior consumo, mostre
        // todas as informações do carro que possui o maior consumo.
        // Todas as funções de entrada e saída devem estar no programa
        // principal
        printf("\nO carro com maior consumo eh o: \n");        
        int ma = busca_maior_consumo(p, n);
        printf("%s do ano %d e que consome %.2fkm/l\n", p[ma].modelo, p[ma].ano, p[ma].consumo);


        // Ex03: utilizando a função de cálculo de eficiência de um carro
        // mostre para todos os carros o seu índice de eficiência e 
        // a sua classificação de eficiência
        printf("\nEficiencia dos veiculos cadastrados:\n");
        // exemplo de saída:
        // Ford Ka - 2020 - 10 km/l; Indice: 9.7; Classificação: B


   int op;

   for(int i = 0; i<n; i++){
    
        op = eficiencia(p,i);
   
            if(op == -1){
                printf("\nValor invalido!\n");
            }

            else if(op == 1){
                printf("%s - %d - %.1f km/l; Indice: %.1f; Classificacao: A\n", p[i].modelo, p[i].ano, p[i].consumo, p[i].consumo * ((p[i].ano - 1991)/30.0));
            }
            else if(op == 2){
                printf("%s - %d - %.1f km/l; Indice: %.1f; Classificacao: B\n", p[i].modelo, p[i].ano, p[i].consumo, p[i].consumo * ((p[i].ano - 1991)/30.0));
            }
            else if(op == 3){
                printf("%s - %d - %.1f km/l; Indice: %.1f; Classificacao: C\n", p[i].modelo, p[i].ano, p[i].consumo, p[i].consumo * ((p[i].ano - 1991)/30.0));
            }
            else if(op == 4){
                printf("%s - %d - %.1f km/l; Indice: %.1f; Classificacao: D\n", p[i].modelo, p[i].ano, p[i].consumo, p[i].consumo * ((p[i].ano - 1991)/30.0));
            }
   }

        // Ex04: Crie uma estrutura para guardar informações sobre o
        // documento de um carro CRLV (Certificado de Registro e
        //  Licenciamento de Veículo)
        // Nesse documento deverá ter o Nome, CPF, e as informações
        // do carro (deve-se utilizar a estrutura dos exercícios anteriores)
        // Crie uma variável dessa estrutura e inicialize ela com valores 
        // constantes (não precisa ler do teclado) e depois mostre esses valores

        CRLV carro = {"Ford Ka", "12345678", "Ford", 2002, 16};

        printf("\nO documento do carro %s indica seu cpf: %s, seu modelo: %s, seu ano: %d e quanto consome: %.2fkm/l\n", carro.nome, carro.cpf, carro.info.modelo, carro.info.ano, carro.info.consumo);



        // Ex05: Duplique o exercício 2 e modifique ele para que ao invés de 
        // retornar o índice da posição do vetor que retorne um ponteiro
        // para a posição do vetor. Mostre no programa principal os dados
        // do carro utilizando o ponteiro retornado.
        printf("\nO carro com maior consumo eh o: \n");
        Cadastro *m = busca_maior_consumoP(p, n);
        printf("%s do ano %d e que consome %.2fkm/l\n", m->modelo, m->ano, m->consumo);
   
   free(p);

return 0;

}