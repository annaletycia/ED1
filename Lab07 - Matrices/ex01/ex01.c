#include <stdio.h>
#include <stdlib.h>

int rand(void);

int main() {     
     
    int mat[4][4], mat1[4][4]; 
    int i,j, k,l;
    int soma[4][4];
    
    /* initialize random seed: */     
     srand (time(NULL)); 
     
    for (i = 0; i < 4; i++) 
    { 
        for (j = 0; j < 4; j++) 
        {                
             mat[i][j] = (rand()/(double)RAND_MAX)*100;            
        }    
    }
    for (k = 0; k < 4; k++) 
    { 
        for (l = 0; l < 4; l++) 
        {                
             mat1[k][l] = (rand()/(double)RAND_MAX)*100;            
        }    
    }
    for (i = 0; i < 4; i++) 
    { 
        for (j = 0; j < 4; j++) 
        {                
             soma[k] = soma[k] + mat[i][j];
             k++          
        }    
    }
    for (k = 0; k < 4; k++) 
    { 
        for (l = 0; l < 4; l++) 
        {                
             soma = soma + mat[k][l];            
        }    
    }

    printf("%d\n", soma);

return 0; 
} 
/*
Faça um programa que realiza a soma de matrizes. 
O usuário deve entrar com duas matrizes 4x4. 
Mostre o resultado da soma.
*/