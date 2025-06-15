#include <math.h>
#include <stdio.h>

#define TAM 50

float calcula(float x) {

  float soma = powf(x, 2) + powf(x, 3) + powf(x, 4);
  float raiz = sqrtf(soma);
  float divisao = raiz / (x - 1);

  return divisao;
}

void read_all(float matriz[TAM][TAM]) {
  for (int i = 0; i < TAM; i++) {
    for (int j = 0; j < TAM; j++) {
      // printf("Digite a posicao [%d][%d] da Matriz \n", i, j);
      // scanf("%f", &matriz[i][j]);

      matriz[i][j] = i + j;
    }
  }
}

void inverter_diagonais(float matriz[TAM][TAM]) {
  for (int i = 0; i < TAM; i++) {

    int d_main = i;
    int d_sec = TAM - 1 - i;

    float temp = matriz[i][d_main];

    matriz[i][d_main] = matriz[i][d_sec];
    matriz[i][d_sec] = temp;
  }
}

void calcule_todos(float matriz[TAM][TAM]) {
  for (int i = 0; i < TAM; i++) {
    for (int j = 0; j < TAM; j++) {
      matriz[i][j] = calcula(matriz[i][j]);
    }
  }
}

void imprimir(float matriz[TAM][TAM]) {
  for (int i = 0; i < TAM; i++) {
    printf("[");
    for (int j = 0; j < TAM; j++) {
      printf(" %.2f, ", matriz[i][j]);
    }
    printf("]\n");
  }
}

int main() {
  float matriz[TAM][TAM];

  read_all(matriz);
  inverter_diagonais(matriz);
  calcule_todos(matriz);
  imprimir(matriz);
  return 0;
}
