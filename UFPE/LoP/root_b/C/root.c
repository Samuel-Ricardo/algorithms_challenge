#include <stdio.h>

float raizBesima(float a, float b) {
  float baixo = 0;
  float alto = a > 1 ? a : 1;
  float meio;

  for (int i = 0; i < 100; i++) {
    meio = (baixo + alto) / 2;
    float potencia = 1;
    for (int j = 0; j < (int)b; j++) {
      potencia *= meio;
    }
    if (potencia > a)
      alto = meio;
    else
      baixo = meio;
  }
  return meio;
}

int main() {
  float a, b;
  scanf("%f %f", &a, &b);

  float resultado = raizBesima(a, b);
  printf("%.2f\n", resultado);

  return 0;
}
