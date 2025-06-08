#include <stdio.h>

int main() {
  float notaFinal;
  scanf("%f", &notaFinal);

  int aprovado = notaFinal >= 7.0f;
  int exame = notaFinal >= 3.0f && notaFinal < 7.0f;
  int reprovado = notaFinal < 3.0f;

  if (aprovado) {
    printf("Aprovado\n");
  }

  if (exame) {
    printf("Exame\n");
  }

  if (reprovado) {
    printf("Reprovado\n");
  }

  return 0;
}
