#include <stdio.h>

int isParto(float peso, int semanas) {
  return (peso < 100 || semanas < 28) ? 0 : 1;
}

int isPartoNormal(float peso, int meses) {
  return (peso > 2500 && meses > 7) || (peso > 1500 && peso < 2000 && meses > 9)
             ? 1
             : 0;
}

int isCesariana(float peso, int meses) {
  return (peso > 2500 && meses < 7) ? 1 : 0;
}

int main() {
  float peso = 0.0;
  int semanas, meses = 0;

  printf("Digite o peso: \n");
  scanf("%f", &peso);

  printf("Digite o tempo em semanas: \n");
  scanf("%d", &semanas);

  if (!isParto(peso, semanas)) {
    printf("Parto nao devera ser realizado, reavaliar clinicamente");
    return 0;
  }

  meses = semanas / 4;

  if (isPartoNormal(peso, meses)) {
    printf("Parto normal");
    return 0;
  }

  if (isCesariana(peso, meses)) {
    printf("Parto Cesariana");
    return 0;
  }

  printf("Parto Cesariana");
  return 0;
}
