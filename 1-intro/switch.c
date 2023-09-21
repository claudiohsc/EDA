#include <stdio.h>

int main() {
    char opcao;
    printf("Escolha uma opção (a, b ou c): ");
    scanf(" %c", &opcao);
    switch (opcao) {
        case 'a':
            printf("Você escolheu a opção a.\n"); break;
        case 'b':
            printf("Você escolheu a opção b.\n"); break;
        case 'c':
            printf("Você escolheu a opção c.\n"); break;
        default:
            printf("Opção inválida.\n"); break;
        }
    return 0;
}