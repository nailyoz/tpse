#include <stdio.h>
#define SQR(x) ((x) * (x))

int main(){
int counter; /* counter for loop */
counter = 0; //fixed the captalization 
while (counter < 5)
printf("x %d square %d\n", counter, SQR(++counter));/*aqui 
é adicionado 2 toda vez que passado pelo loop 
vai ate o 6 ao inves do 5 pois só ha adicao dno contador 
apos passar pela condicao
counter++ vai adicionar 1 em 1*/ 

return (0);
}