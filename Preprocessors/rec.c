#include <stdio.h>
#define RECIPROCAL(number) (1.0/(number))
/*The only difference between a parameterized macro and one without parameters 
is the parenthesis immediately following the macro name. In this case, a space follows 
the definition of RECIPROCAL, so the macro is not parameterized. Instead, it is a simple
 text-replacement macro that will replace RECIPROCAL */

int main() {
    float counter; /* Counter for our table */
    
    for (counter = 1.0; counter < 10.0;counter += 1.0) {
    printf("1/%f = %f\n", counter, RECIPROCAL(counter));
}
return (0);
}
