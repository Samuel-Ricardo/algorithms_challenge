#include <stdio.h>

int main() {
  float salarioBruto;
  scanf("%f", &salarioBruto);

  float aliquota = 0.0;

  if (salarioBruto > 4664.68f) {
    aliquota = 0.275f;
  } else if (salarioBruto > 3751.05f) {
    aliquota = 0.225f;
  } else if (salarioBruto > 2826.65f) {
    aliquota = 0.15f;
  } else if (salarioBruto > 1903.98f) {
    aliquota = 0.075f;
  }

  if (aliquota == 0.0f) {
    printf("Isento de IRRF.\n");
    return 0;
  }

  float valorImposto = salarioBruto * aliquota;

  printf("Salario bruto: R$ %.2f\n", salarioBruto);
  printf("Aliquota aplicada: %.1f%%\n", aliquota * 100);
  printf("Imposto devido: R$ %.2f\n", valorImposto);

  return 0;
}
