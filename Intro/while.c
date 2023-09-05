#include <stdio.h>
int main() {
    int i = 1;
    printf("Contagem ascendente:\n");
    while (i <= 5) printf("%d ", i++);
    printf("\n");

    i = 10;
    printf("Contagem descendente:\n");
    while (i >= 1) printf("%d ", i--);
    printf("\n");

    i = 2;
    printf("Números pares:\n");
    while (i <= 10) printf("%d ", i += 2);
    return 0;
}