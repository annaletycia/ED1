#include <stdio.h>

typedef struct
{
    int DDD;
    int telefone;
} Telefone;

void mostraTelefone(Telefone X)
{
printf("%d %d\n", X.DDD, X.telefone);
}

int main()
{

    Telefone tel1, tel2, tel3;

    printf("Digite o DDD: ");
    scanf("%d", &tel1.DDD);
    printf("Digite o telefone: ");
    scanf("%d", &tel1.telefone);
    printf("Digite o DDD: ");
    scanf("%d",&tel2.DDD);
    printf("Digite o telefone: ");
    scanf("%d",&tel2.telefone);
    printf("Digite o DDD: ");
    scanf("%d", &tel3.DDD);
    printf("Digite o telefone: ");
    scanf("%d", &tel3.telefone);

    printf("\n\nTelefones cadastrados:\n");
    mostraTelefone(tel1);
    mostraTelefone(tel2);
    mostraTelefone(tel3);

    return 0;

}

/*
1) Crie uma estrutura chamada telefone, que armazena o DDD e o telefone (ilustração abaixo).  
Cadastre 3 telefones e mostre na tela os telefones cadastrados. 

Telefone**
+------------+------------+
| DDD        | Telefone   |  
+------------+------------+

-------------------------------------------------------------------------------
Exemplo de saída:
Digite o DDD: 34
Digite o telefone: 991501111
Digite o DDD: 31
Digite o telefone: 991502222
Digite o DDD: 64
Digite o telefone: 991503333

Telefones cadastrados: 
34 991501111
31 991502222
64 991503333
-------------------------------------------------------------------------------
*/