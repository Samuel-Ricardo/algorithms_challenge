#include <math.h>
#include <stdio.h>

float jurosSimples(float C, float i, float t) { return C * i * t; }

float jurosCompostos(float C, float i, float t) { return C * pow((1 + i), t); }

float taxaDeJurosComposto(float t, float C, float M) {
  return pow((M / C), (1 / t)) - 1;
}

void preencher(float *C, float *i, float *t) {
  int isValido = 0;

  printf("Digite o capital investido:  \n");
  scanf("%f", C);
  while (!isValido) {
    printf("Digite a taxa de juros entre 1 e 0:  \n");
    scanf("%f", i);
    if (*i >= 0 && *i <= 1)
      isValido = 1;
  }
  printf("Digite o tempo decorrido: \n");
  scanf("%f", t);
}

int main() {

  char opt;
  int running = 1;
  float C, i, t, J, M, I = 0.0;
  preencher(&C, &i, &t);

  while (running) {

    printf("Escolha o que deseja fazer: \n [S] - Calcular Juros Simples \n");
    printf("[C] - Calcular Jusros Compostos \n [D] - Digitar novos valores \n");
    printf("[B] - Buscar Melhor Taxa \n [E] - Encerrar Programa \n");

    while (getchar() != '\n')
      ;
    opt = getchar();

    switch (opt) {

    case 'S':
    case 's':
      J = jurosSimples(C, i, t);
      printf("Os Juros foram: %.2f e o Montante Total e %.2f", J, J + C);
      break;

    case 'C':
    case 'c':
      M = jurosCompostos(C, i, t);
      printf("Os juros foram: %.2f e o Montante Total e: %.2f", M - C, C);
      break;

    case 'B':
    case 'b':
      J = jurosSimples(C, i, t);
      M = C + J;
      I = taxaDeJurosComposto(t, C, M);

      printf("Melhor taxa: %.2f", I);
      break;

    case 'D':
    case 'd':
      preencher(&C, &i, &t);
      break;

    case 'E':
    case 'e':
      running = 0;
      break;

    default:
      printf("Opcao invalida, digite novamente. \n");
    }
  }
  printf("programa esta encerrando \n");
  return 0;
}
