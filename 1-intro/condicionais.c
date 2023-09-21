#include <stdio.h>

int main() {
    int idade;
    // Exemplo de uso do if-else if-else
    if (idade < 13) {
        printf("Você é uma criança.\n");
    } else if (idade < 18) {
        printf("Você é um adolescente.\n");
    } else {
        printf("Você é um adulto.\n");
    }
    return 0;
}