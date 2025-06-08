#include <stdio.h>

int main() {
  int contagemSapatos[46] = {0};
  int tamanho;

  while (1) {
    scanf("%d", &tamanho);
    if (tamanho == -1)
      break;
    if (tamanho >= 38 && tamanho <= 45) {
      contagemSapatos[tamanho]++;
    }
  }

  int tamanhoMaisComum = 38;
  int maiorQuantidade = contagemSapatos[38];

  for (int i = 39; i <= 45; i++) {
    if (contagemSapatos[i] > maiorQuantidade) {
      maiorQuantidade = contagemSapatos[i];
      tamanhoMaisComum = i;
    }
  }

  printf("O numero de sapato mais comum e: %d\n", tamanhoMaisComum);

  return 0;
}
