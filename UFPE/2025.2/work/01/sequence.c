#include <stdio.h>

#define SEQUENCE_LENGTH 10

int main() {
  int number;
  int positive = 0;  
  int negative = 0; 
  int zeros = 0;  
  int i;

  printf("Digite %d numeros inteiros: \n", SEQUENCE_LENGTH);

  for (i = 0; i < SEQUENCE_LENGTH; i++) {
    printf("\n Numero %d: ", i + 1);
    scanf("%d", &number);

    if (number > 0) {
      positive++;
    } else if (number < 0) {
      negative++;
    } else {
      zeros++;
    }
  }

  printf("\nResultados:\n");
  printf("Numeros Positivos: %d\n", positive);
  printf("Numeros Negativos: %d\n", negative);
  printf("Zeros: %d\n", zeros);

  return 0;
}
