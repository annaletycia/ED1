#include <stdio.h>

int main(){

    char opcao;
    float v, vKm, vMs;

    printf("<<Conversor de velocidade>>\n");
    while (opcao != EOF) {
    printf("Digite uma opcao: \n");
    printf("1 - para converter de km/h para m/s\n2 - para converter de m/s para km/h\nq - para sair\n");
    scanf(" %c", &opcao);
 
        if(opcao == '1'){
            printf("Digite a velocidade (km/h): ");
            scanf(" %f", &v);
            vMs = v / 3.6;
            printf("A velocidade em m/s eh %f\n",vMs);
        }
        else if(opcao == '2'){
            printf("Digite a velocidade (m/s): ");
            scanf(" %f", &v);
            vKm = v * 3.6;
            printf("A velocidade em km/h eh %f\n",vKm);
        }
        else if(opcao == 'q'){
            break;
        }
        else{
          printf("Opcao nao disponivel\n");
        }
        }
return 0;
}