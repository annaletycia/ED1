#include <stdio.h>
#include <time.h>

int main(){
    int mat[10][10];
    srand(time(NULL));

    for(int i=0;i<10;i++){
        for(int j=0; j<10; j++){
            mat[i][j]= rand() % 100;
        }
    }
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            printf("%d", mat[j][i]);
        }
    }
    return 0;
}