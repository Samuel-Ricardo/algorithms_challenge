#include <stdio.h>

#define lenMatricula 5
#define lenNome 30
#define lenCargo 25

typedef struct funcionario {
  char matricula[lenMatricula];
  char nome[lenNome];
  char cargo[lenCargo];
  float salario;
} tFuncionario;

int contarFuncionarios() {
  FILE *arquivo = fopen("funcionarios.txt", "r");

  if (arquivo == NULL) {
    return 0;
  }

  int total;
  fscanf(arquivo, "%d", &total);
  fclose(arquivo);

  return total;
}

void lerFuncionario(tFuncionario *func) {
  printf("Matricula: ");
  scanf("%s", func->matricula);

  printf("Nome:  ");
  scanf(" %[^\n]", func->nome);

  printf("Cargo: ");
  scanf(" %[^\n]", func->cargo);

  printf("Salario: ");
  scanf("%f", &func->salario);
}

void salvarFuncionarios(tFuncionario funcionarios[], int total) {
  FILE *arquivo = fopen("funcionarios.txt", "w");

  fprintf(arquivo, "%d\n", total);

  for (int i = 0; i < total; i++) {
    fprintf(arquivo, "%s\n", funcionarios[i].matricula);
    fprintf(arquivo, "%s\n", funcionarios[i].nome);
    fprintf(arquivo, "%s\n", funcionarios[i].cargo);
    fprintf(arquivo, "%.2f\n", funcionarios[i].salario);
  }

  fclose(arquivo);
}

int consultarFuncionarios(tFuncionario funcionarios[]) {
  FILE *arquivo = fopen("funcionarios.txt", "r");

  if (arquivo == NULL) {
    return 0;
  }

  int total;
  fscanf(arquivo, "%d\n", &total);

  for (int i = 0; i < total; i++) {
    fscanf(arquivo, "%s\n", funcionarios[i].matricula);
    fscanf(arquivo, " %[^\n]\n", funcionarios[i].nome);
    fscanf(arquivo, " %[^\n]\n", funcionarios[i].cargo);
    fscanf(arquivo, "%f\n", &funcionarios[i].salario);
  }

  fclose(arquivo);
  return total;
}

void exibirFuncionarios(tFuncionario funcionarios[], int total) {
  printf("\n=== FUNCIONARIOS CADASTRADOS ===\n");
  for (int i = 0; i < total; i++) {
    printf("\nFuncionario %d:\n", i + 1);
    printf("Matricula: %s\n", funcionarios[i].matricula);
    printf("Nome: %s\n", funcionarios[i].nome);
    printf("Cargo:  %s\n", funcionarios[i].cargo);
    printf("Salario: %.2f\n", funcionarios[i].salario);
  }
  printf("\n================================\n");
}

int main() {
  tFuncionario funcionarios[100]; // Array com tamanho suficiente
  int opcao, total = 0;

  printf("1-Cadastrar 2-Consultar:  ");
  scanf("%d", &opcao);

  if (opcao == 1) {
    printf("Quantos funcionarios deseja cadastrar?  ");
    scanf("%d", &total);

    for (int i = 0; i < total; i++) {
      printf("\n--- Funcionario %d ---\n", i + 1);
      lerFuncionario(&funcionarios[i]);
    }

    salvarFuncionarios(funcionarios, total);
    exibirFuncionarios(funcionarios, total);

  } else {
    total = contarFuncionarios();

    if (total > 0) {
      printf("Total de funcionarios: %d\n", total);
      consultarFuncionarios(funcionarios);
      exibirFuncionarios(funcionarios, total);
    } else {
      printf("Nenhum funcionario encontrado!\n");
    }
  }

  return 0;
}
