#include <stdio.h>

int main() {
int calcular;

do{
    char operacao;
    float num1, num2;

    // limpeza do buffer. ou __fpurge(stdin); em linux
    printf("Escolha a operação [+ - * / ]: ");
    scanf("%c", &operacao);

    printf("Insira o primeiro número: ");
    scanf("%f", &num1);

    printf("Insira o segundo número: ");
    scanf("%f", &num2);

    switch(operacao) {
        case '+':
            printf("%.2f + %.2f = %.2f\n", num1, num2, num1 + num2);
            break;
        case '-':
            printf("%.2f - %.2f = %.2f\n", num1, num2, num1 - num2);
            break;
        case '*':
            printf("%.2f * %.2f = %.2f\n", num1, num2, num1 * num2);
            break;
        case '/':
            printf("%.2f / %.2f = %.2f\n", num1, num2, num1 / num2);
            break;
        default:
            printf("Digitou uma operação inválida.\n");
            break;
    }

    printf("Insira 0 para sair ou 1 para continuar: ");
    scanf("%d", &calcular);
 /* Verifica-se o valor da variável calcular. Se for 0 é considerado falso
46 e o código não é executado mais vez nenhuma. Caso seja um número diferente
47 de 0, a condição retornará um valor que representa true (todos os números
48 exceto 0) e continuar-se-à a executar o código. */
    }while (calcular);

    return 0;
}

