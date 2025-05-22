#include <stdio.h>

int main() {

  float real, dollar;
  float tax = 5.61;

  printf("Digite um valor em reais: R$");
  scanf("%f", &real);

  dollar = real * tax; // NOTE: 1 Real === 5.61 Dollar

  printf("O valor em Dolares e: US$ %.2f\n", dollar);

  return 0;
}
