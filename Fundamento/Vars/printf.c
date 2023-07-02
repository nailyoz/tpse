#include <stdio.h>

int main() {
float piMinor = 3.14;
double piMajor = 3.14159265359;
//apenas %f no float retornará 3.140000
printf("Pi pode ser %.2f mas, de forma mais exata, é %.11f.", piMinor, piMajor);

return 0;
}