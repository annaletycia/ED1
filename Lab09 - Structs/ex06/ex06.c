#include <stdio.h>

typedef struct eletrodomestico{

  char nome[15];
  float potencia, tempo;
  float consR;
}Eletrodomestico;

int main(){

  int i, dias;
  Eletrodomestico e[5];

  for(i=0; i<5; i++){
    printf("Informe os dados do eletrodomestico (%d):\n", i+1);
    printf("Nome: ");
    scanf("%s", e[i].nome);
    printf("Potencia: ");
    scanf("%f", &e[i].potencia);
    printf("Tempo ativo por dia: ");
    scanf("%f", &e[i].tempo);
    printf("\n");
  }

  printf("Informe um valor de tempo (em dias): ");
  scanf("%d", &dias);

  float consumoT = 0;

  for(i=0; i<5; i++){

    consumoT = consumoT + (e[i].potencia * e[i].tempo * dias);
  }

  printf("Consumo total: %.0f KW\n", consumoT);
  printf("Consumo relativo:\n");

  for(i=0; i<5; i++){

    e[i].consR = ((e[i].potencia * e[i].tempo * dias)/consumoT) * 100;
  }

  for(i=0; i<5; i++){

    printf("%s: %.1f%%\n", e[i].nome, e[i].consR);
  }
    return 0;
}

/*
6.Faça um programa que controla o consumo de energia dos eletrodomésticos de uma casa.

    • Crie e leia as informações de 5 eletrodomésticos: o nome (máximo 15 letras), 
      potencia (real,  em kW) e tempo ativo por dia (real, em horas).

    • Leia um valor de tempo t (em dias), calcule e mostre o consumo total na casa e
      o consumo relativo de cada eletrodoméstico  (consumo/consumo total) nesse período
      de tempo. Apresente este ultimo dado em porcentagem.

-------------------------------------------------------------------------------
Exemplo de saída:
Informe os dados do 1º eletrodomestico: 
Nome: Geladeira
Potencia: 800
Tempo ativo por dia: 24

Informe os dados do 2º eletrodomestico: 
Nome: Ar Condicionado
Potencia: 1500
Tempo ativo por dia: 8

Informe os dados do 3º eletrodomestico: 
Nome: Chuveiro
Potencia: 4500
Tempo ativo por dia: 1

Informe os dados do 4º eletrodomestico: 
Nome: Radio
Potencia: 100
Tempo ativo por dia: 6

Informe os dados do 5º eletrodomestico: 
Nome: Computador
Potencia: 750
Tempo ativo por dia: 18

Informe um valor de tempo (em dia): 30
Consumo total: 1494000 KW
Consumo relativo: 
Geladeira 38.6%
Ar Condicionado 24.1%
Chuveiro 9.0%
Radio 1.2%
Computador 27.1%
-------------------------------------------------------------------------------
*/