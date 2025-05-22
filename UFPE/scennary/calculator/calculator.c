#include <stdio.h>

double sum(double a, double b) { return a + b; }

double sub(double a, double b) { return a - b; }

double mul(double a, double b) { return a * b; }

double div(double a, double b) { return a / b; }

double powNumber(double base, double exponent) {
  double result = 1.0;
  for (int i = 0; i < exponent; i++) {
    result *= base;
  }
  return result;
}

double root(double radicand, double root) {
  double x = radicand / 2.0;
  double tolerance = 0.00001;

  /*
  while (fabs(x * x - radicand) > tolerance) {
    x = ((root - 1) * x + radicand / powNumber(x, root - 1)) / root;
  }
  */

  for (int i = 0; i < 100; i++) {
    double previus_x = x;

    x = ((root - 1) * x + radicand / powNumber(x, root - 1)) / root;

    if (previus_x - x < tolerance && x - previus_x < tolerance) {
      break;
    }
  }

  return x;
}

int main() {

  double num1, num2, result;
  char operation;

  printf("Digite o primeiro numero: ");
  scanf("%lf", &num1);

  printf("Digite o segundo numero: ");
  scanf("%lf", &num2);

  printf("Escolha a operacao (A - Adicao, S - Subtracao, M - Multiplicacao, D "
         "- Divisao, P - Potenciacao, R - Raiz): ");
  scanf(" %c", &operation);

  switch (operation) {
  case 'A':
  case 'a':
    result = sum(num1, num2);
    break;
  case 'S':
  case 's':
    result = sub(num1, num2);
    break;
  case 'M':
  case 'm':
    result = mul(num1, num2);
    break;
  case 'D':
  case 'd':
    if (num2 == 0) {
      printf("Nao e possicel efetuar divisao por zero.\n");
      return 1;
    }
    result = div(num1, num2);
    break;
  case 'P':
  case 'p':
    if (num2 < 0 || (int)num2 != num2) {
      printf("Potenciacao so aceita expoentes inteiros nao negativos.\n");
      return 1;
    }
    result = powNumber(num1, num2);
    break;
  case 'R':
  case 'r':
    if (num1 < 0) {
      printf("Nao e possivel calcular raiz real de um numero negativo.\n");
      return 1;
    }
    if (num2 <= 0 || (int)num2 != num2) {
      printf("Indice da raiz deve ser inteiro positivo.\n");
      return 1;
    }
    result = root(num1, num2);
    break;
  default:
    printf("Operacao invalida.\n");
    return 0;
  }

  printf("O resultado eh: %.2lf\n", result);
}
