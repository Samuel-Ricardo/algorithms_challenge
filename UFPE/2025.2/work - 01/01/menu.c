#include <stdio.h>

#define N 5

#define lenMatricula 5
#define lenNome 30
#define lenCargo 25

typedef struct funcionario {
  char matricula[lenMatricula];
  char nome[lenNome];
  char cargo[lenCargo];
  float salario;
} tFuncionario;

void Menu(int *choice) {
  printf("\n Escolha uma Opcao: \n\n");

  printf("1. Inserir Dados \n");
  printf("2. Consultar Dados \n");
  printf("3. Encerrar o Programa \n\n");

  scanf("%d", choice);
}

int main() {

  int running = 1;
  int choice = 0;

  while (running) {

    Menu(&choice);

    switch (choice) {

    case 1:
      printf("Escolheu - %d", choice);
      running = 0;
      break;

    case 2:
      printf("Escolheu - %d", choice);
      running = 0;
      break;

    case 3:
      printf("Escolheu - %d", choice);
      running = 0;
      break;

    default:
      printf("Opcao Invalida");
      running = 1;
      break;
    }
  }

  return 0;
}
