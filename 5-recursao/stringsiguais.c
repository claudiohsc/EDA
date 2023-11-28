#include <stdio.h>


int igualString(char *a, char *b){
    if (*a == '\0' && *b == '\0') {
        return 1;
    }

     // Caso base 2: Se um dos caracteres for diferente, as strings não são iguais.
    if (*a != *b) {
        return 0;
    }

    // Chamada recursiva: Verifica os caracteres restantes nas duas strings.
    return saoIguais(a + 1, b + 1);
}


void main (){
    char str1[] = "hello";
    char str2[] = "world";
    int resultado = saoIguais(str1, str2);

    if (resultado) {
        printf("As strings são iguais.\n");
    } else {
        printf("As strings não são iguais.\n");
    }
}