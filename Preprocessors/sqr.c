#include <stdio.h>
#define SQR(x) (x * x)
//parenteses na definicao resolveria
int main(){
int counter; /* counter for loop */
for (counter = 0; counter < 5; ++counter) {
//mesmo problema do first 
// a substituicao de string segue (counter + 1 * counter + 1)
printf("x %d, x squared %d\n",counter+1, SQR(counter+1));
}
return (0);
}
