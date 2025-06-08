#include <stdio.h>

int main() {
  const float pi = 3.14f;

  int formaSelecionada;
  scanf("%d", &formaSelecionada);

  if (formaSelecionada == 1) {
    float base, altura;
    scanf("%f %f", &base, &altura);
    float areaTriangulo = (base * altura) / 2.0f;
    printf("a area do triangulo e %.2f\n", areaTriangulo);
  }

  if (formaSelecionada == 2) {
    float raio;
    scanf("%f", &raio);
    float areaCirculo = pi * raio * raio;
    printf("a area do circulo e %.2f\n", areaCirculo);
  }

  if (formaSelecionada == 3) {
    float comprimentoLado;
    scanf("%f", &comprimentoLado);
    float areaHexagono =
        ((3.0f * 1.73205f) / 2.0f) * comprimentoLado * comprimentoLado;
    printf("a area do hexagono e %.2f\n", areaHexagono);
  }

  if (formaSelecionada == 4) {
    float baseMaior, baseMenor, altura;
    scanf("%f %f %f", &baseMaior, &baseMenor, &altura);
    float areaTrapezio = ((baseMaior + baseMenor) * altura) / 2.0f;
    printf("a area do trapezio e %.2f\n", areaTrapezio);
  }

  if (formaSelecionada < 1 || formaSelecionada > 4) {
    printf("opcao invalida\n");
  }

  return 0;
}
