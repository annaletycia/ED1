#include <stdio.h> 
#include <string.h> 

int main(void){ 
    
    char buff[5];     
    int pass = 0;     
    
    printf("\n Entre com a senha: \n"); 
    fgets(buff,4,stdin);     
    
buff[strcspn(buff, "\n")] = '\0';

    if (strcmp(buff, "1234\0")) { 
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

/*b)

 Entre com a senha: 
123

 Senha Errada

Acesso negado 


 Entre com a senha:
12345

 Senha Errada

 Acesso negado

  Entre com a senha:
123456

 Senha Errada

 Acesso negado
 */