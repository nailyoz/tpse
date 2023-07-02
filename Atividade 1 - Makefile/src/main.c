#include <stdio.h>
#include <stdlib.h>

// prototipos
int add(int num1, int num2);
int sub(int num1, int num2);
int mul(int num1, int num2);
int div(int num1, int num2);


int main() {
    int num1, num2;
    char op;

    printf("Selecione 2 numeros ");
    scanf("%f %f", &num1, &num2);

    printf("Selecione um operador (+, -, *, /): ");
    scanf(" %c", &op);

    switch (op) {
        case '+':
            printf("%.2f + %.2f = %.2f", num1, num2, add(num1, num2));
            break;
        case '-':
            printf("%.2f - %.2f = %.2f", num1, num2, sub(num1, num2));
            break;
        case '*':
            printf("%.2f * %.2f = %.2f", num1, num2, mul(num1, num2));
            break;
        case '/':
            printf("%.2f / %.2f = %.2f", num1, num2, div(num1, num2));
            break;
        default:
            printf("Erro: Sinal invalido.");
    }

    return 0;
}