//Write a macro that returns TRUE if its parameter is
// divisible by 10 and FALSE otherwise.
#include <stdio.h>
#define DIV(num) ((num%10)==0 ? true : false)
#define true 1
#define false 0
int main(){
    int valor = 15;
    if (DIV(valor)){
        printf("true");
    }else{
        printf("false");
    }
    

return(0);  
}