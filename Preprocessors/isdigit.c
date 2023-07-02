//Write a macro is_digit that returns TRUE
// if its argument is a decimal digit
#include <stdio.h>
#include <math.h>

#define is_digit(num) (num - floor(num) !=0 ? true : false)
#define true 1
#define false 0

int main(){
    float valor = 15.2;
    if(is_digit(valor)){
        printf("Deu True");
    }else{
        printf("Deu False");
    }
    
return(0);  
}