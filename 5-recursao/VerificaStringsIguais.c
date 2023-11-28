/******************************************************************************
Função recursiva para verificar se duas strings a e b são iguais ou nãoo.
Retorna 1, caso a seja igual a b
Retronar 0,  caso a seja diferente de b 

*******************************************************************************/
#include <stdio.h>

#define Tam 100

// Função recursiva para verificar se duas strings são iguais
int EhIgual(char *sa, char *sb) {
    // Duas strings vazias são iguais
    if (*sa == '\0' && *sb == '\0') {
        return 1;
    }
    
    // Se há um caracter diferente sa e sb são diferentes
    if (*sa != *sb) {
        return 0;
    }
    
    //Se os caracteres de sa e sb atuais são iguais, continue verificando os 
    //próximos:
    return EhIgual(sa + 1, sb + 1);
}


int main() {
    char a[Tam]; 
    char b[Tam]; 
    int resposta;

    printf("Digite string a (até %d caracteres): ", Tam-1);
    scanf("%s", a); 

    printf("Digite string b (até %d caracteres): ", Tam-1);
    scanf("%s", b); 
    
    resposta = EhIgual(a,b);

    if (resposta)
        printf("As strings a e b são iguais.\n");
    else
        printf("As strings a e b são diferentes.\n");

    return 0;
}
