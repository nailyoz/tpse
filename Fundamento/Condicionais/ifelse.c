#include <stdio.h>

int main(){
    int n = 10;

    if(n==50) {
        printf( "o valor %d é igual a 50.", n);
    }else if(n>50) {
        printf( "o valor %d é maior que 50.", n);
    }else{
        printf("o valor %d é menor que 50.", n);
    }
    return 0;
}