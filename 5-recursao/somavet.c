#include <stdio.h>

int somavet(int *a, int qtde){

    int i, soma;
    soma = 0;
    if (qtde == 0){
        return 0;
    }else{
    
        return a[0] + somavet(a+1, qtde-1);
    }

}

int main(){

    int vetor[5] = {2,9,7,6,5};
    int soma;
    soma = somavet(vetor, 5);

    printf("A soma dos itens do vetor é: %i\n", soma);

}

