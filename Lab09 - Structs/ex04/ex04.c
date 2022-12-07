#include <stdio.h>
#include <string.h>

typedef struct Data
{
    int dia, mes, ano;
};

typedef struct Endereco
{
    char rua[50], cidade[50], estado[50], complemento[50];
    int numero, cep;
};

typedef struct Telefone
{
    int DDD;
    int telefone;
};

typedef struct Cadastro
{
    char nome[50], sexo[50], estcivil[50], cpf[50],id[50];
    float salario;
    struct Data nascimento, ingresso;
    struct Endereco residencial, comercial;
    struct Telefone tel, telresidencial;

}Cadastro;

void mostraCadastro(Cadastro X)
{
    printf("\nInformacoes Pessoais:\nNome: %s, Sexo: %s, Estado civil: %s, CPF: %s, Identidade: %s,\nSalario: %.2f\nData de nascimento: %d/%d/%d\nData de ingresso: %d/%d/%d\nTelefone: %d %d\nTelefone residencial: %d %d\nEndereco residencial:\n%s, %s-%s, %s numero %d, cep: %d,\nEndereco comercial:\n%s, %s-%s, %s numero %d, cep: %d\n",
     X.nome, X.sexo, X.estcivil,X.cpf,X.id,X.salario,X.nascimento.dia,X.nascimento.mes,X.nascimento.ano,X.ingresso.dia,X.ingresso.mes,
     X.ingresso.ano,X.tel.DDD,X.tel.telefone,X.telresidencial.DDD,X.telresidencial.telefone,X.residencial.rua,X.residencial.cidade,X.residencial.estado,X.residencial.complemento,X.residencial.numero,X.residencial.cep,
     X.comercial.rua,X.comercial.cidade,X.comercial.estado,X.comercial.complemento,X.comercial.numero,X.comercial.cep);
    printf("\n");
}

 int menu()
{
    int opcao;
    
    printf("<< Cadastro de Usuarios >> \n\n");
    printf("1 - Listar todos os cadastros\n");
    printf("2 - Cadastrar/Sobescrever nova pessoa\n");
    printf("3 - Listar as pessoas que nasceram depois de 1990:\n");
    printf("4 - Copiar dados de um cadastro para outro:\n");
    printf("0 - Sair\n");

}

int main(){

    int opcao;
    //int i;
    int cad, cad1;
    int vet;
    //Cadastro c1, c2, c3, c4, c5;
    Cadastro c[5];

    Cadastro c1;
    strcpy(c1.nome,"Francisco Rocha");
    strcpy(c1.sexo, "masculino");
    strcpy(c1.estcivil,"casado");
    strcpy(c1.id,"123872009-21");
    strcpy(c1.cpf,"22.917.669-08");
    c1.salario = 2090.00;
    c1.nascimento.dia = 24;
    c1.nascimento.mes = 5;
    c1.nascimento.ano = 1990;
    c1.ingresso.dia = 16;
    c1.ingresso.mes = 8;
    c1.ingresso.ano = 2019;
    strcpy(c1.residencial.rua,"Oscar Freire");
    strcpy(c1.residencial.cidade,"Sao Paulo");
    strcpy(c1.residencial.estado,"SP");
    strcpy(c1.residencial.complemento,"apartamento 502");
    c1.residencial.numero = 771;
    c1.residencial.cep = 18285000;
    strcpy(c1.comercial.rua,"25 de Marco");
    strcpy(c1.comercial.cidade,"Sao Paulo");
    strcpy(c1.comercial.estado,"SP");
    strcpy(c1.comercial.complemento,"apartamento 502");
    c1.comercial.numero = 771;
    c1.comercial.cep = 18285000;
    c1.tel.DDD = 21;
    c1.tel.telefone = 999764577;
    c1.telresidencial.DDD = 21;
    c1.telresidencial.telefone = 32145678;
    c[0] = c1;
    

    Cadastro c2 = {"Camila Ferreira", "feminino", "solteira", "125456889-07", "25.589.123-5", 6500.00};
    c2.nascimento.dia = 12;
    c2.nascimento.mes = 1;
    c2.nascimento.ano = 1980;
    c2.ingresso.dia = 1;
    c2.ingresso.mes = 6;
    c2.ingresso.ano = 2000;
    strcpy(c2.residencial.rua,"Bernardo Cupertino");
    strcpy(c2.residencial.cidade,"Uberlandia");
    strcpy(c2.residencial.estado,"MG");
    strcpy(c2.residencial.complemento,"apartamento 421");
    c2.residencial.numero = 1721;
    c2.residencial.cep = 38400444;
    strcpy(c2.comercial.rua,"Professor Mario Porto");
    strcpy(c2.comercial.cidade,"Uberlandia");
    strcpy(c2.comercial.estado,"MG");
    strcpy(c2.comercial.complemento,"apartamento 100");
    c2.comercial.numero = 61;
    c2.comercial.cep = 38400138;
    c2.tel.DDD = 34;
    c2.tel.telefone = 998526598;
    c2.telresidencial.DDD = 34;
    c2.telresidencial.telefone = 32155585;
    c[1] = c2;


    Cadastro c3 = {"Laura Lange", "feminino", "casada", "123456885-98", "68.785.587-8", 4300.00};
    c3.nascimento.dia = 8;
    c3.nascimento.mes = 11;
    c3.nascimento.ano = 1991;
    c3.ingresso.dia = 25;
    c3.ingresso.mes = 4;
    c3.ingresso.ano = 2010;
    strcpy(c3.residencial.rua,"11 de Maio");
    strcpy(c3.residencial.cidade,"Uberlandia");
    strcpy(c3.residencial.estado,"MG");
    strcpy(c3.residencial.complemento,"apartamento 421");
    c3.residencial.numero = 1721;
    c3.residencial.cep = 15859658;
    strcpy(c3.comercial.rua,"Almirante Mauriti");
    strcpy(c3.comercial.cidade,"Uberlandia");
    strcpy(c3.comercial.estado,"MG");
    strcpy(c3.comercial.complemento,"apartamento 502");
    c3.comercial.numero = 61;
    c3.comercial.cep = 15140400;
    c3.tel.DDD = 21;
    c3.tel.telefone = 995489632;
    c3.telresidencial.DDD = 21;
    c3.telresidencial.telefone = 333659875;
    c[2]=c3;


    Cadastro c4 = {"Alexandre Marquez", "masculino", "solteiro", "145678994-09", "12.345.346-7", 1500.00};
    c4.nascimento.dia = 18;
    c4.nascimento.mes = 10;
    c4.nascimento.ano = 2000;
    c4.ingresso.dia = 1;
    c4.ingresso.mes = 2;
    c4.ingresso.ano = 2021;
    strcpy(c4.residencial.rua,"Professor Mario Porto");
    strcpy(c4.residencial.cidade,"Uberlandia");
    strcpy(c4.residencial.estado,"MG");
    strcpy(c4.residencial.complemento,"apartamento 421");
    c4.residencial.numero = 465;
    c4.residencial.cep = 15859658;
    strcpy(c4.comercial.rua,"Almirante Mauriti");
    strcpy(c4.comercial.cidade,"Uberlandia");
    strcpy(c4.comercial.estado,"MG");
    strcpy(c4.comercial.complemento,"apartamento 100");
    c4.comercial.numero = 61;
    c4.comercial.cep = 15140400;
    c4.tel.DDD = 21;
    c4.tel.telefone = 995489632;
    c4.telresidencial.DDD = 21;
    c4.telresidencial.telefone = 333659875;
    c[3] = c4;


    Cadastro c5 = {"Caio Silva", "masculino", "casada", "129458557-08", "56.861.889-1", 10000.00};
    c5.nascimento.dia = 5;
    c5.nascimento.mes = 4;
    c5.nascimento.ano = 1960;
    c5.ingresso.dia = 25;
    c5.ingresso.mes = 4;
    c5.ingresso.ano = 1990;
    strcpy(c5.residencial.rua,"Anchieta");
    strcpy(c5.residencial.cidade,"Belo Horizonte");
    strcpy(c5.residencial.estado,"MG");
    strcpy(c5.residencial.complemento,"apartamento 202");
    c5.residencial.numero = 168;
    c5.residencial.cep = 30720370;
    strcpy(c5.comercial.rua,"Almirante Mauriti");
    strcpy(c5.comercial.cidade,"Belo Horizonte");
    strcpy(c5.comercial.estado,"MG");
    strcpy(c5.comercial.complemento,"apartamento 1");
    c5.comercial.numero = 45;
    c5.comercial.cep = 15140400;
    c5.tel.DDD = 31;
    c5.tel.telefone = 994587005;
    c5.telresidencial.DDD = 31;
    c5.telresidencial.telefone = 32005849;
    c[4] = c5;
    
    int flag = 1;

    while(flag==1){
    menu();
    printf("Escolha uma opcao: ");
    scanf("%d",&opcao);
    printf("\n");

    if(opcao==1){
        printf("Lista de usuarios cadastrados:\n");

                for(int i=0; i<5;i++){
                printf("\nPosicao: %d",i);
                mostraCadastro(c[i]);
               }
    }
    if(opcao==2){
        printf("Escolha a posicao do vetor que deseja realizar o cadastro: ");
                  scanf("%d", &vet);
                  printf("Cadastro anterior:\n");
                  mostraCadastro(c[vet]);
                  printf("Nome:");
                  scanf("%s", c[vet].nome);
                  printf("Sexo:");
                  scanf("%s", c[vet].sexo);
                  printf("Estado civil:");
                  scanf("%s", c[vet].estcivil);
                  printf("CPF:");
                  scanf("%s", c[vet].cpf);
                  printf("Identidade:");
                  scanf("%s", c[vet].id);
                  printf("Salario:");
                  scanf("%d", &c[vet].salario);
                  printf("Data de nascimento:\n");
                  printf("Dia:");
                  scanf("%d", &c[vet].nascimento.dia);
                  printf("Mes:");
                  scanf("%d", &c[vet].nascimento.mes);
                  printf("Ano:");
                  scanf("%d", &c[vet].nascimento.ano);
                  printf("Data de ingresso:\n");
                  printf("Dia:");
                  scanf("%d", &c[vet].ingresso.dia);
                  printf("Mes:");
                  scanf("%d", &c[vet].ingresso.mes);
                  printf("Ano:");
                  scanf("%d", &c[vet].ingresso.ano);
                  printf("Endereco:\n");
                  printf("Rua:");
                  scanf("%s", c[vet].residencial.rua);
                  printf("Numero:");
                  scanf("%d", &c[vet].residencial.numero);
                  printf("Cidade:");
                  scanf("%s", c[vet].residencial.cidade);
                  printf("Estado:");
                  scanf("%s", c[vet].residencial.estado);
                  printf("Complemento:");
                  scanf("%s", c[vet].residencial.complemento);
                  printf("CEP:");
                  scanf("%d", &c[vet].residencial.cep);
                  printf("Telefone residencial(DDD e numero):");
                  scanf("%d %d", &c[vet].telresidencial.DDD,&c[vet].telresidencial.telefone);
                  printf("Endereco comercial:\n");
                  printf("Rua:");
                  scanf("%s", c[vet].comercial.rua);
                  printf("Numero:");
                  scanf("%d", &c[vet].comercial.numero);
                  printf("Cidade:");
                  scanf("%s", c[vet].comercial.cidade);
                  printf("Estado:");
                  scanf("%s", c[vet].comercial.estado);
                  printf("Complemento:");
                  scanf("%s", c[vet].comercial.complemento);
                  printf("CEP:");
                  scanf("%d", &c[vet].comercial.cep);
                  printf("Telefone(DDD e numero):");
                  scanf("%d %d", &c[vet].tel.DDD,&c[vet].tel.telefone);
                  printf("\nNovo cadastro:\n");
                  mostraCadastro(c[vet]);
        }
        
    if(opcao==3){
            for(int i; i<5; i++){
                if(c[i].nascimento.ano > 1990){
                mostraCadastro(c[i]);
                }
            }
        }

    if(opcao==4){ 
            printf("Qual a posicao do cadastro que sera copiado: ");
            scanf("%d", &cad);
            printf("Qual a posicao do cadastro que armazenara esses dados: ");
            scanf("%d", &cad1);
            c[cad1] = c[cad];
            printf("\nCadastro na posicao %d:\n\n", cad1);
            mostraCadastro(c[cad1]);
        }

    if(opcao==0){
        flag = 0;
    }
}

}

/*
4) Define a estrutura necessária para armazenar os dados a seguir. 
Use as subestruturas dos   exercícios   anteriores para definir os tipos
dos campos com asterisco. Dê suporte para o cadastro de 5 pessoas:  

Cadastro
+------------+---------------------+--------------------------+------------------------+
| Nome       | Endereço comercial* |         Salário          |       Idade            | 
+------------+---------------------+--------------------------+--------+---------------+
| CPF        | Estado civil        |        Telefone**        | Data de nascimento *** |   
+------------+---------------------+--------------------------+--------+---------------+
| Sexo       |Endereço residencial*|  Telefone residencial ** | Data de ingresso ***   | 
+------------+---------------------+--------------------------+--------+---------------+

(a)Cadastre 5 usuários no seu código (não pedir para digitar – cadastre no próprio código
fonte, utilizando comandos de atribuição). A ideia disso é evitar digitação excessiva
durante o teste do programa.

(b)Crie um menu com as seguintes opções:
    a.Listar todos os cadastros
    b.Cadastrar/Sobrescrever nova pessoa (pedir em qual posição do vetor ela será cadastrada 0,1,2,3, ou 4)
    c.Listar as pessoas que nasceram depois de 1990.
    d.Copiar dados de um cadastro para outro


-------------------------------------------------------------------------------
Exemplo de saída:

=======Exemplo do menu=======

<< Cadastro de Usuários >> 

1 - Listar todos os cadastros  
2 - Cadastrar/Sobrescrever nova pessoa  
3 - Listar as pessoas que nasceram depois de 1990  
4 - Copiar dados de um cadastro para outro   
0 - Sair 
Escolha uma opção: 1

Lista de usuários cadastrados: 

Posição: 0 
Informacoes Pessoais: 
Nome: Cersei Lannister, CPF: 111111111-11, Sexo: F, Estado Civil: Viuva 
Salario: 111111, Identidade:  WE-11.111.111 
Telefone residencial: (11) 11111-1111 
Telefone: (11) 91111-1111 
Data de Nascimento:  1 de janeiro de 262 
Data de Ingresso: 1 de janeiro de 276 

Endereço comercial: 
Rua:  Colina de Aegon, Nº: 1, Complemento: Red Keep, Cidade: Porto Real  
Estado: WE, CEP: 11111-111 

Endereço residencial: 
Rua:  Colina de Aegon, Nº: 1, Complemento: Red Keep, Cidade: Porto Real  
Estado: WE, CEP: 11111-111 

Posição: 1 
Informacoes Pessoais: 
Nome:  John Snow, CPF: 222222222-22, Sexo: M, Estado Civil: Solteiro 
Salario: 111111, Identidade:  WE-22.222.222 
Telefone residencial: (11) 22222-2222 
Telefone: (11) 92222-2222 
Data de Nascimento:  2 de fevereiro de 281 
Data de Ingresso: 2 de fevereiro de 295 

Endereço comercial: 
Rua:  Norte dos 7 Reinos, Nº: 1, Complemento: Castelo Negro, Cidade: A Muralha  
Estado: WE, CEP: 11111-111 

Endereço residencial: 
Rua:  Norte dos 7 Reinos, Nº: 1, Complemento: Castelo Negro, Cidade: A Muralha  
Estado: WE, CEP: 11111-111 

Posição: 2 
Informacoes Pessoais: 
Nome: Jaime Lannister, CPF: 333333333-33, Sexo: M, Estado Civil: Solteiro 
Salario: 111111, Identidade:  WE-33.333.333 
Telefone residencial: (11) 11111-1111 
Telefone: (11) 91111-1111 
Data de Nascimento:  1 de janeiro de 262 
Data de Ingresso: 1 de janeiro de 276 

Endereço comercial: 
Rua:  Colina de Aegon, Nº: 1, Complemento: Red Keep, Cidade: Porto Real  
Estado: WE, CEP: 11111-111 

Endereço residencial: 
Rua:  Colina de Aegon, Nº: 1, Complemento: Red Keep, Cidade: Porto Real  
Estado: WE, CEP: 11111-111 

Posição: 3 
Informacoes Pessoais: 
Nome: Samwell Tarly, CPF: 444444444-44, Sexo: M, Estado Civil: Solteiro 
Salario: 111111, Identidade:  WE-44.444.444 
Telefone residencial: (11) 22222-2222 
Telefone: (11) 92222-2222 
Data de Nascimento:  2 de fevereiro de 283 
Data de Ingresso: 2 de fevereiro de 295 

Endereço comercial: 
Rua:  Norte dos 7 Reinos, Nº: 1, Complemento: Castelo Negro, Cidade: A Muralha  
Estado: WE, CEP: 11111-111 

Endereço residencial: 
Rua:  Norte dos 7 Reinos, Nº: 1, Complemento: Castelo Negro, Cidade: A Muralha  
Estado: WE, CEP: 11111-111 

-------------------------------------------------------------------------------
*/