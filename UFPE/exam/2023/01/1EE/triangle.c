#include <stdio.h>

int isTriangulo(float a1, float a2, float a3) {
  if (a1 <= 0 || a2 <= 0 || a3 <= 0)
    return 0;
  if (a1 + a2 + a3 == 180)
    return 1;

  return 0;
}

int isTretangulo(float a1, float a2, float a3) {
  int c = 0;

  if (a1 == 90)
    c++;
  if (a2 == 90)
    c++;
  if (a3 == 90)
    c++;

  if (c == 1)
    return 1;

  return 0;
}

int isObtusangulo(float a1, float a2, float a3) {
  int c = 0;

  if (a1 > 90 && a1 < 180)
    c++;
  if (a2 > 90 && a2 < 180)
    c++;
  if (a3 > 90 && a3 < 180)
    c++;

  return c == 1 ? 1 : 0;
}

int isAcutangulo(float a1, float a2, float a3) {
  return (a1 < 90 && a2 < 90 && a3 < 90) ? 1 : 0;
}

int main() {

  float a1, a2, a3 = 0.0;

  printf("Digite os angulos: \n - a1:");
  scanf("%f", &a1);

  printf("\n - a2: ");
  scanf("%f", &a2);

  printf("\n - a3: ");
  scanf("%f", &a3);

  if (!isTriangulo(a1, a2, a3)) {
    printf("Nao forma triangulo");
    return 0;
  }

  if (isTretangulo(a1, a2, a3)) {
    printf("E um Triangulo Retangulo");
  }

  if (isObtusangulo(a1, a2, a3))
    printf("E um Triangulo Obtusangulo");

  if (isAcutangulo(a1, a2, a3))
    printf("E um Triangulo Acutangulo");

  return 0;
}
