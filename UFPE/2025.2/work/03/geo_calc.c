#include <stdio.h>

#define PI 3.14

float circle(float radius) { return PI * radius * radius; }

float square(float side) { return side * side; }

float rectangle(float height, float width) { return height * width; }

float triangle(float base, float height) { return (base * height) / 2; }

float rhombus(float diagonal1, float diagonal2) {
  return (diagonal1 * diagonal2) / 2;
}

float trapezium(float base1, float base2, float height) {
  return ((base1 + base2) * height) / 2;
}

int main() {
  int running = 1;

  while (running) {
    printf("Calculadora Geometrica: \n");

    printf("Escolha uma opcao: \n");

    printf("1 - Circulo \n");
    printf("2 - Quadrado \n");
    printf("3 - Retangulo \n");
    printf("4 - Triangulo \n");
    printf("5 - Losango \n");
    printf("6 - Trapezio \n");
    printf("7 - Sair \n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {

    case 1:
      float radius;
      printf("Digite o raio: ");
      scanf("%f", &radius);
      printf("Area: %.2f\n", circle(radius));
      break;

    case 2:
      float side;
      printf("Digite o lado: ");
      scanf("%f", &side);
      printf("Area: %.2f\n", square(side));
      break;

    case 3:
      float side1, side2;
      printf("Digite a altura: ");
      scanf("%f", &side1);
      printf("Digite a largura: ");
      scanf("%f", &side2);

      printf("Area: %.2f\n", rectangle(side1, side2));
      break;

    case 4:
      float base, height;
      printf("Digite a base: ");
      scanf("%f", &base);
      printf("Digite a altura: ");
      scanf("%f", &height);

      printf("Area: %.2f\n", triangle(base, height));
      break;

    case 5:
      float diagonal1, diagonal2;
      printf("Digite a diagonal 1: ");
      scanf("%f", &diagonal1);
      printf("Digite a diagonal 2: ");
      scanf("%f", &diagonal2);
      printf("Area: %.2f\n", rhombus(diagonal1, diagonal2));
      break;

    case 6:

      float base1, base2, heightTrapezium;

      printf("Digite a base 1: ");
      scanf("%f", &base1);
      printf("Digite a base 2: ");
      scanf("%f", &base2);
      printf("Digite a altura: ");
      scanf("%f", &heightTrapezium);

      printf("Area: %.2f\n", trapezium(base1, base2, heightTrapezium));
      break;

    case 7:
      running = 0;
      break;

    default:
      printf("Opcao invalida \n");
      break;
    }
  }

  return 0;
}
