#include <stdio.h>

int main() {
    int i;
    printf("Contagem ascendente:\n");
    for (i = 1; i <= 5; i++) { //imprimir números de 1 a 5
        printf("%d ", i);
    }
    printf("Contagem descendente:\n");
    for (i = 10; i >= 1; i--) { //imprimir números de 10 a 1
        printf("%d ", i);
    }
    printf("Números pares:\n");
    for (i = 2; i <= 10; i += 2) { //imprimir números pares de 2
        printf("%d ", i);
    }
    return 0;
}