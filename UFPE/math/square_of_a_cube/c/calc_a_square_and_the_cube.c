#include <stdio.h>
int main() {

  int N;
  long long int result;

  printf("Digite um numero inteiro: ");
  scanf("%d", &N);

  result = (long long)N * N * N; // NOTE: CUBE
  result = result * result;      // NOTE: SQUARE

  printf("O quadrado do cubo de %d e: %lld\n", N, result);

  return 0;
}
