#include <stdio.h>

void preencherMatriz(int linhas, int colunas, int matriz[linhas][colunas]) {
  for (int l = 0; l < linhas; l++) {
    for (int c = 0; c < colunas; c++) {
      printf("Preencha o valor da Matriz na posicao [%d][%d]: ", l, c);
      scanf("%d", &matriz[l][c]);
    }
  }
}

void imprimirMatriz(int linhas, int colunas, int matrix[linhas][colunas]) {
  for (int l = 0; l < linhas; l++) {
    printf("{");
    for (int c = 0; c < colunas; c++) {
      printf("[%d] ", matrix[l][c]);
    }
    printf("} \n");
  }
}

void multiplicaMatrizes(int linhas1, int colunas1,
                        int matriz1[linhas1][colunas1], int linhas2,
                        int colunas2, int matriz2[linhas2][colunas2],
                        int resultado[linhas1][colunas2]) {

  for (int l = 0; l < linhas1; l++) {
    for (int c = 0; c < colunas2; c++) {
      resultado[l][c] = 0;

      for (int k = 0; k < colunas1; k++) {
        resultado[l][c] += matriz1[l][k] * matriz2[k][c];
      }
    }
  }
}

int main() {

  int linhas1, linhas2, colunas1, colunas2;

  printf("Digite a quantidade de Linhas da Primeira Matriz: ");
  scanf("%d", &linhas1);

  printf("Digite a quantidade de Colunas da Primeira Matriz: ");
  scanf("%d", &colunas1);

  printf("Digite a quantidade de Linhas da Segunda Matriz: ");
  scanf("%d", &linhas2);

  printf("Digite a quantidade de Colunas da Segunda Matriz: ");
  scanf("%d", &colunas2);

  if (colunas1 != linhas2) {
    printf("Matriz 1 tem mais colunas do que Matriz 2 tem de Linhas, "
           "multiplicacao nao pode ser feita");
    return 0;
  }

  int matriz1[linhas1][colunas1];
  int matriz2[linhas2][colunas2];
  int resultado[linhas1][colunas2];

  preencherMatriz(linhas1, colunas1, matriz1);
  preencherMatriz(linhas2, colunas2, matriz2);

  printf("Matriz 1: \n");
  imprimirMatriz(linhas1, colunas1, matriz1);
  printf("Matriz 2: \n");
  imprimirMatriz(linhas2, colunas2, matriz2);

  multiplicaMatrizes(linhas1, colunas1, matriz1, linhas2, colunas2, matriz2,
                     resultado);

  printf("Resultado: \n");
  imprimirMatriz(linhas1, colunas2, resultado);
}
