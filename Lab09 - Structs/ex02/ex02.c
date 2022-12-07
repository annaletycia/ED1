#include <stdio.h>

typedef struct
{
    int dia, ano;
    char mes[50];
}Data;


void mostraData(Data X)
{
    printf("Dia %d de %s de %d\n", X.dia, X.mes, X.ano);
}

int main(){

    int maior;

    Data d1,d2,d3;

    printf("Digite o dia: ");
    scanf("%d", &d1.dia);
    printf("Digite o mes: ");
    scanf("%s", d1.mes);
    printf("Digite o ano: ");
    scanf("%d", &d1.ano);
    printf("Digite o dia: ");
    scanf("%d", &d2.dia);
    printf("Digite o mes: ");
    scanf("%s", d2.mes);
    printf("Digite o ano: ");
    scanf("%d", &d2.ano);
    printf("Digite o dia: ");
    scanf("%d", &d3.dia);
    printf("Digite o mes: ");
    scanf("%s", d3.mes);
    printf("Digite o ano: ");
    scanf("%d", &d3.ano); 

    printf("\nDatas cadastradas:\n");
    mostraData(d1);
    mostraData(d2);
    mostraData(d3);

    maior = d1.ano;
    if(d2.ano > maior && d2.ano > d3.ano)
    {
        maior = d2.ano;
        printf("\n%d foi o maior ano cadastrado\n", maior);
    }
    if(d3.ano > maior && d3.ano > d2.ano)
    {
        maior = d3.ano;
        printf("\n%d foi o maior ano cadastrado\n", maior);
    }
    else
    {
        printf("\n%d foi o maior ano cadastrado\n", maior);
    }

    return 0;
    
}

/*
2) Crie uma estrutura chamada data, que armazena o dia, mês e o ano (ilustração abaixo).  
Cadastre 3 datas, mostre as datas e o maior ano cadastrado. 

Data***
+------------+------------+---------------+
| Dia        | Mês        |   Ano         |    
+------------+------------+---------------+

-------------------------------------------------------------------------------
Exemplo de saída:
Digite o dia: 2
Digite o mes: Janeiro
Digite o ano: 2015

Digite o dia: 15
Digite o mes: Maio
Digite o ano: 2018

Digite o dia: 21
Digite o mes: Dezembro
Digite o ano: 2020


Datas cadastradas: 
Dia 2 de Janeiro de 2015
Dia 15 de Maio de 2018
Dia 21 de Dezembro de 2020

2020 foi o maior ano cadastrado.
-------------------------------------------------------------------------------
*/