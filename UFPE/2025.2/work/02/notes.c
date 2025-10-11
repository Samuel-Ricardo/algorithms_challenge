#include <stdio.h>

int main() {

  float note1, note2, media = 0.0;

  printf("Digite a primeira nota: ");
  scanf("%f", &note1);
  printf("Digite a segunda nota: ");
  scanf("%f", &note2);

  media = (note1 + note2) / 2;
  printf("Media: %.2f\n", media);

  if (media >= 7.0) {
    printf("Aprovado por media");
    return 0;
  }
  if (media < 3.0) {
    printf("Reprovado por media");
    return 0;
  }

  printf("Esta na final \n");
  printf("Digite a nota da prova final \n");

  float final;
  scanf("%f", &final);

  media = (media + final) / 2;
  printf("Media final: %.2f\n", media);

  if (media >= 5.0) {
    printf("Aprovado na final");
  } else {
    printf("Reprovado na final");
  }

  return 0;
}
