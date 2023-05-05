#include <stdio.h>

int main() {
    int opcao;

    printf("Insira a opção:\n");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            printf("Escolheu a opção 1");
            break;
        case 2:
            printf("Escolheu a opção 2");
            break;
        case 3:
            printf("Escolheu a opção 3");
            break;
        case 4:
            printf("Escolheu a opção 4");
            break;
        case 5:
            printf("Escolheu a opção 5");
            break;
        default:
            printf("Opção inexistente.");
            break;
    }

    return 0;
}
