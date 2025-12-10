#include <stdio.h>

#define N 5

#define lenMatricula 5
#define lenNome 30
#define lenCargo 25

#define ARQUIVO "empresa.txt"

typedef struct funcionario {
  char matricula[lenMatricula];
  char nome[lenNome];
  char cargo[lenCargo];
  float salario;
} tFuncionario;

void jump() { printf("\n"); }

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

int contarFuncionarios() {
  FILE *arquivo = fopen(ARQUIVO, "r");

  if (arquivo == NULL)
    return 0;

  int total = 0;
  char linha[20];

  while (fgets(linha, 20, arquivo))
    total++;

  total = total / 4;
  printf("Total de Funcionarios: %d \n\n", total);

  fclose(arquivo);
  return total;
}

tFuncionario lerFuncionario() {
  tFuncionario func;

  jump();

  printf("Matricula: ");
  scanf("%s", func.matricula);

  jump();

  printf("Nome:  ");
  scanf(" %[^\n]", func.nome);

  jump();

  printf("Cargo: ");
  scanf(" %[^\n]", func.cargo);

  jump();

  printf("Salario: ");
  scanf("%f", &func.salario);

  jump();

  return func;
}

void inserir() {

  FILE *arquivo = fopen(ARQUIVO, "a");
  if (arquivo == NULL)
    printf("Erro ao abrir o arquivo \n");

  tFuncionario funcionario = lerFuncionario();

  fprintf(arquivo, "%s\n", funcionario.matricula);
  fprintf(arquivo, "%s\n", funcionario.nome);
  fprintf(arquivo, "%s\n", funcionario.cargo);
  fprintf(arquivo, "%.2f\n", funcionario.salario);

  fclose(arquivo);
  contarFuncionarios();
}

int main() {

  int running = 1;
  int choice = 0;

  while (running) {
    Menu(&choice);

    switch (choice) {

    case 1:
      contarFuncionarios() >= N ? printf("Arquivo cheio! \n\n") : inserir();
      break;

    case 2:
      running = todo(choice);
      break;

    case 3:
      running = todo(choice);
      break;

    default:
      printf("Opcao invalida!");
      break;
    }
  }

  return 0;
}
