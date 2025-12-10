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

  printf("1. Inserir dados \n");
  printf("2. Consultar dados \n");
  printf("3. Encerrar o programa \n\n");

  scanf("%d", choice);
}

int todo(int c) {
  printf("Voce escolheu - %d", c);
  return 0;
}

int inserir(const char *arquivo) { int total = contarRegistro() }

int main() {

  const char *arquivo = "empresa.txt";

  int runnig = 1;
  int choice = 1;

  while (running) {
    Menu(&choice);

    switch (choice) {

    case 1:
      inserir(arquivo);
      break;

    case 2:
      runnig = todo(choice);
      break;

    case 3:
      runnig = todo(choice);
      break;

    default:
      printf("Opcao invalida!");
      break;
    }
  }

  return 0;
}
