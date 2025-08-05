#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5
#define MAPA "mapa.dat"

struct Jogador {
  char nome[50];
  int linha, coluna;
} typedef Jogador;

void saveMapa(int mapa[SIZE][SIZE]) {

  FILE *file = fopen(MAPA, "wb");

  if (!file) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  fwrite(mapa, sizeof(int), SIZE * SIZE, file);

  fclose(file);
}

void lerMapa(int mapa[SIZE][SIZE]) {
  FILE *file = fopen(MAPA, "rb");
  if (!file) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  fread(mapa, sizeof(int), SIZE * SIZE, file);

  fclose(file);
}

void inicializaJogador(Jogador *jogador, const char *nome, int linha,
                       int coluna) {
  strcpy(jogador->nome, nome);
  jogador->linha = linha;
  jogador->coluna = coluna;
}

void imprimeJogador(Jogador *jogador) {
  printf("Nome: %s\n", jogador->nome);
  printf("Linha: %d\n", jogador->linha);
  printf("Coluna: %d\n", jogador->coluna);
}

void moveJogador(Jogador *jogador, int posicao[2], int mapa[SIZE][SIZE],
                 int linha, int coluna) {

  if (posicao[0] < 0 || posicao[0] > linha || posicao[1] < 0 ||
      posicao[1] > coluna) {

    printf("Posição fora do mapa.");
    return;
  }

  if (mapa[posicao[0]][posicao[1]] == 1) {
    printf("Posição inválida, e uma parede");
    return;
  }

  jogador->linha = posicao[0];
  jogador->coluna = posicao[1];
}

int main() {

  Jogador jogador;
  inicializaJogador(&jogador, "Sam", 0, 0);

  int mapa[SIZE][SIZE] = {
      {0, 1, 2, 0, 1}, {0, 2, 1, 0, 2}, {1, 2, 0, 1, 2},
      {0, 0, 0, 0, 0}, {0, 1, 0, 2, 0},
  };

  saveMapa(mapa);

  int choice, game_over = 0;

  while (!game_over) {

    printf("\n--- Menu ---\n");
    printf("1. Mover o jogador\n2. Exibir posição do jogador\n3. Sair\n");
    printf("Escolha uma opção: ");

    scanf("%d", &choice);

    switch (choice) {

    case 1:
      int posicao[2];

      printf("Digite a direcao (Linha & Coluna): ");
      scanf("%d %d", &posicao[0], &posicao[1]);

      moveJogador(&jogador, posicao, mapa, SIZE, SIZE);
      break;

    case 2:
      imprimeJogador(&jogador);
      break;

    case 3:
      game_over = 1;
      break;

    default:
      printf("Opção inválida.\n");
    }
  }
}
