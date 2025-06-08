#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    if (N < 0) {
        printf("Numero invalido. Deve ser positivo.\n");
        return 0;
    }

    int soma = 0;
    for (int i = 2; i <= N; i += 2) {
        soma += i;
    }

    printf("A soma dos numeros pares de 1 ate %d e %d.\n", N, soma);

    return 0;
}

