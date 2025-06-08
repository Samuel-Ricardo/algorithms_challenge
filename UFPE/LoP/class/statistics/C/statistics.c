#include <stdio.h>

float raizQuadrada(float valor) {
  if (valor <= 0.0f)
    return 0.0f;

  float chute = valor / 2.0f;
  float precisao = 0.00001f;

  while (1) {
    float novoChute = 0.5f * (chute + valor / chute);
    if (chute - novoChute < precisao && novoChute - chute < precisao)
      break;
    chute = novoChute;
  }
  return chute;
}

int main() {
  float notas[5];
  for (int i = 0; i < 5; i++) {
    scanf("%f", &notas[i]);
    if (notas[i] < 0.0f) {
      printf("As notas devem ser maiores ou iguais a zero.\n");
      return 0;
    }
  }

  float soma = 0.0f;
  for (int i = 0; i < 5; i++) {
    soma += notas[i];
  }
  float media = soma / 5.0f;

  float somaQuadrados = 0.0f;
  for (int i = 0; i < 5; i++) {
    float diferenca = notas[i] - media;
    somaQuadrados += diferenca * diferenca;
  }

  float variancia = somaQuadrados / 5.0f;
  float desvioPadrao = raizQuadrada(variancia);

  printf("Media: %.4f\n", media);
  printf("Variancia: %.4f\n", variancia);
  printf("Desvio Padrao: %.4f\n", desvioPadrao);

  return 0;
}
