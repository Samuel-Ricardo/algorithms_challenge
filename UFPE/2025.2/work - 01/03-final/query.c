#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  printf("\n\n Escolha uma Opcao: \n\n");

  printf("1. Inserir dados \n");
  printf("2. Consultar dados \n");
  printf("3. Encerrar o programa \n\n");

  scanf("%d", choice);
}

int contarFuncionarios() {
  FILE *arquivo = fopen(ARQUIVO, "r");

  if (arquivo == NULL)
    return 0;

  int total = 0;
  char linha[100];

  while (fgets(linha, 100, arquivo))
    total++;

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

int inserir() {

  FILE *arquivo = fopen(ARQUIVO, "a");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo \n");
    return 0;
  }

  tFuncionario f = lerFuncionario();
  fprintf(arquivo, "%s|%s|%s|%.2f\n", f.matricula, f.nome, f.cargo, f.salario);

  fclose(arquivo);
  return contarFuncionarios();
}

char *consultar(char matricula[lenMatricula]) {

  tFuncionario f;
  char *not_find = "Funcionario nao encontrado";

  FILE *arquivo = fopen(ARQUIVO, "r");

  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo \n");
    return not_find;
  }

  int find = 0;

  while (fscanf(arquivo, "%[^|]|%[^|]|%[^|]|%f\n", f.matricula, f.nome, f.cargo,
                &f.salario) != EOF) {
    if (strcmp(f.matricula, matricula) == 0) {
      find = 1;
      break;
    }
  };

  fclose(arquivo);

  jump();

  char *result = (char *)malloc(sizeof(char) * 200);
  sprintf(result, "Matricula: %s \nNome: %s \nCargo: %s \nSalario: %.2f \n",
          f.matricula, f.nome, f.cargo, f.salario);

  return find ? result : not_find;
}

int main() {

  int choice = 0;

  while (choice != 3) {
    Menu(&choice);

    switch (choice) {

    case 1:
      contarFuncionarios() >= N ? printf("Arquivo cheio! \n\n") : inserir();
      break;

    case 2:
      printf("Digite a matricula: ");

      char matricula[lenMatricula];
      scanf("%s", matricula);

      printf("%s", consultar(matricula));
      break;

    case 3:
      printf("Encerrando o Programa... \n\n");
      break;

    default:
      printf("Opcao invalida!");
      break;
    }
  }

  return 0;
}
