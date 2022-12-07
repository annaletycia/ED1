#include <stdio.h> 
#include <string.h> 

int main(void){ 
    
    char buff[5];     
    int pass = 0;     
    
    printf("\n Entre com a senha: \n"); 
    gets(buff);     
    
    if (strcmp(buff, "1234")) { 
        printf ("\n Senha Errada \n");     
    }else{        
        printf ("\n Senha Correta \n");         
        pass = 1;     
        }    
    if(pass){ /* O usuário acertou a senha, poderá continuar*/ 
        printf ("\n Acesso liberado \n");
    } else {         
        printf ("\n Acesso negado \n");
    }    
    
    return 0; 
    
    }

//a) a funcao do programa eh controlar o acesso por meio de uma senha, liberando ou negando a entrada do usuario.

//b)a saida quando a senha correta eh digitada eh:
// Senha Correta Acesso liberado

 //c) 
 //a. Senha Errada, Acesso negado
 //b. Senha Errada, Acesso negado
 //c. Senha Errada, Acesso liberado

 /*d) no caso c. o programa imprimiu a mensagem de senha errada, porem liberou o acesso. Esse erro ocorre pois a quantidade
 de digitos ultrapassou a quantidade limite do array, e a funcao gets nao limita o buffer de leitura*/