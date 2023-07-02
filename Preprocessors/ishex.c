// Write a second macro is_hex that returns true if its argument is a hex digit 
//(0-9, A-F, a-f). The second macro should reference the first.

#include <stdio.h>
#include <math.h>

#define is_digit(num) (num - floor(num) !=0 ? true : false)
#define true 1
#define false 0

int main(){
    float valor = 15;
    if(is_digit(valor)){
        printf("Deu True");
    }else{
        printf("Deu False");
    }
    
return(0);  
}