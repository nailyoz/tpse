#include <stdio.h>
#define PI 3.14159
//define sendo uma constante que será obrigatoriamente global 
//constantes declaradas com 'const' são locais
int main (){

double r = 5.0;
double circle;
//variavel: tipo  nome = valor
circle = 2 * PI * r;
printf("%f\n", circle);
return 0;
}
