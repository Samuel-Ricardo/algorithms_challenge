#include <stdio.h>

float MediaSono(float horas[7]) {
  float soma = 0;
  for (int i = 0; i < 7; i++) {
    soma += horas[i];
  }
  return soma / 7;
}

void AlertaSono(float horas[7], float media) {
  const char *dias[7] = {"Domingo", "Segunda", "Terca", "Quarta",
                         "Quinta",  "Sexta",   "Sabado"};
  printf("Atencao! Judite dormiu abaixo da media semanal nos dias:\n");
  for (int i = 0; i < 7; i++) {
    if (horas[i] < media) {
      printf("%s\n", dias[i]);
    }
  }
}

int main() {
  float horas[7];
  for (int i = 0; i < 7; i++) {
    scanf("%f", &horas[i]);
  }

  float media = MediaSono(horas);
  printf("Media semanal de sono: %.2f horas\n", media);

  if (media < 8.0) {
    printf("A media esta fora do esperado de pelo menos 8 horas!\n");
    AlertaSono(horas, media);
  } else {
    printf("A media esta dentro do esperado de pelo menos 8 horas!\n");
  }

  return 0;
}
