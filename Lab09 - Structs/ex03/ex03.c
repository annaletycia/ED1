#include <stdio.h>
#include <string.h>

typedef struct 
{
    char rua[50], cidade[50], estado[50], complemento[50];
    int numero, cep;
}Endereco;

void mostraEnd(Endereco X)
{
    printf("Rua: %s\nNumero: %d\nComplemento: %s\nCidade: %s\nEstado: %s\nCEP: %d\n\n", X.rua,X.numero,X.complemento,X.cidade,X.estado,X.cep);
}
void mostraEndMG(Endereco X)
{
    printf("Endereco: rua %s, numero %d, complemento: %s, %s - %s  CEP: %d\n", X.rua, X.numero, X.complemento, X.estado, X.cidade, X.cep);
}

int main()
{

    Endereco end1, end2, end3;

    strcpy(end1.rua,"25 de Marco");
    strcpy(end1.cidade,"Sao Paulo");
    strcpy(end1.estado,"SP");
    strcpy(end1.complemento,"casa A");
    end1.numero = 771;
    end1.cep = 18285000;

    strcpy(end2.rua,"Anchieta");
    strcpy(end2.cidade,"Belo Horizonte");
    strcpy(end2.estado,"MG");
    strcpy(end2.complemento,"apartamento 101");
    end2.numero = 168;
    end2.cep = 30720370;

    strcpy(end3.rua,"Alagoas");
    strcpy(end3.cidade,"Uberlandia");
    strcpy(end3.estado,"MG");
    strcpy(end3.complemento,"Sem");
    end3.numero = 582;
    end3.cep = 38400666;

    printf("Enderecos:\n");

    mostraEnd(end1);
    mostraEnd(end2);
    mostraEnd(end3);

    printf("Enderecos cadastrados que sao de MG:\n");
    if((strcmp(end1.estado,"MG"))==0)
    {
        mostraEndMG(end1);
    }
    if((strcmp(end2.estado,"MG"))==0)
    {
        mostraEndMG(end2);
    }
    if((strcmp(end3.estado,"MG"))==0)
    {
        mostraEndMG(end3);
    }

    return 0;
}
/*
3) Crie uma estrutura chamada endereco, que armazena Rua, Número, Complemento,
Cidade, Estado e CEP (ilustração abaixo).  
Cadastre 3 endereços. Mostre ao final, todos os dados dos endereços cadastrados que são do estado “MG”

Endereco*
+------------+------------+---------------+
| Rua        | Número     |  Complemento  |    
+------------+------------+---------------+
| Cidade     | Estado     |     CEP       | 
+------------+------------+---------------+


-------------------------------------------------------------------------------
Exemplo de saída:
Rua: Joao
Numero: 32
Complemento: casa A
Cidade: Uberlandia
Estado: MG
CEP: 38400034


Rua: Almeida
Numero: 43
Complemento: Sem
Cidade: Araguari
Estado: MG
CEP: 38400045


Rua: Coronel Pedro
Numero: 25
Complemento: apto 40
Cidade: Caldas Novas
Estado: GO
CEP: 75780023


Enderecos cadastrados que sao de "MG":
Joao, 32. casa A. Uberlandia-MG, 38400034.
Almeida, 43. Sem. Araguari-MG, 38400045.
-------------------------------------------------------------------------------
*/