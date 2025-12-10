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

  printf("Escolha uma Opcao do Menu \n\n");

  printf("1. Inserir Dados \n");
  printf("2. Consultar Dados \n");
  printf("3. Encerrar Programa \n");

  scanf("%d", choice);
}

int main() {

  int choice = 0;

  Menu(&choice);

  return 0;
}
