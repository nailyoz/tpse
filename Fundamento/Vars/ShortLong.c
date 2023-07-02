#include <stdio.h>

int main() {
    printf("int : %d bytes\n", sizeof(int) );
    printf("short int: %d bytes\n", sizeof(short) );
    printf("long int: %d bytes\n", sizeof(long) );
    return 0;
}

/*No meu sistema:
int : 4 bytes
short int: 2 bytes
long int: 4 bytes

ou seja: o valor de long se mantém o mesmo do padrão
*/