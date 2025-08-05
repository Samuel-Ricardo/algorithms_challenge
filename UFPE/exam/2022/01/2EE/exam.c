#include <stdio.h>

#define MAX_PESSOAS 100
#define MAX_NOME 50

struct Pessoa {
  int id;
  char nome[50];
  float salario;
  int idade;
  int menbros;
  int comodos;
  int raca;
} typedef Pessoa;

void menu() {

  int run = 1;
  int opcao;

  do {
    printf("Escolha uma opcao: \n \n 1 - cadastrar \n 2 - ");

    switch (opcao) {

    case 4:
      run = 0;
      break;

    default:
      printf("Opcao invalida");
      break;
    }
  } while (run);
}
