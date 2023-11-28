#include <stdio.h>

// Função recursiva para calcular um termo de Fibonacci
int fibonacci(int n) {
    if (n <= 0) {
        return 0; // Condição de parada.
    } else if (n == 1) {
        return 1; // Condição de parada.
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2); // Calcular Fibonacci(n-1) e Fibonacci(n-2)
    }
}

int main() {
    int n;
    
    printf("Qual termo de Fibonacci a ser calculado? ");
    scanf("%d", &n);
    
    if (n < 0) {
        printf("Termo deve ser positivo ou zero.\n");
    } else {
        int resultado = fibonacci(n);
        printf("O termo é: %d\n", resultado);
    }
    
    return 0;
}
