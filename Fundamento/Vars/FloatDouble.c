#include <stdio.h>

int main() {
    printf("float : %d bytes\n", sizeof(float) );
    printf("double: %d bytes\n", sizeof(double) );

    return 0;
}

/*No meu sistema:
float : 4 bytes
double : 8 bytes
Para quem precise de fazer cálculos mais precisos, o tipo de dados double é o mais aconselhado
pois é o que permite uma maior extensão do valor.
*/