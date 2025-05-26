#include <stdio.h>
#include <stdlib.h>

#define SECRET_NUMBER 42
#define MIN_LIMIT 0
#define MAX_LIMIT 99

int calculate_difference(int diference) {
  if (diference > 30 || diference < -30)
    return 3;
  else if (diference > 20 || diference < -20)
    return 2;
  else if (diference > 10 || diference < -10)
    return 1;
  else
    return 0;
}

void show_distance_message(int diference) {
  switch (calculate_difference(diference)) {
  case 3:
    printf("Voce esta muito longe! Tente outra vez!\n");
    break;
  case 2:
    printf("Voce esta esquentando! Tente outra vez!\n");
    break;
  case 1:
    printf("Voce esta quente! Tente outra vez!\n");
    break;
  case 0:
    printf("Voce esta muito quente! Tente outra vez!\n");
  }
}

int verify_response(int guess) {
  if (guess == SECRET_NUMBER)
    return 1;
  else if (guess < MIN_LIMIT)
    return -1;
  else if (guess > MAX_LIMIT)
    return 0;

  return -2;
}

int verify_result(int guess) {
  int result = 0;
  int response = verify_response(guess);

  switch (response) {
  case 1:
    printf("Parabens! Voce acertou :)\n");
    result = 1;
    break;
  case -1:
    printf("Valor negativo! Qual eh o seu problema?\n");
    result = 0;
    break;
  case 0:
    printf("Nao passou nem perto! Valor fora do intervalo!\n");
    result = 0;
    break;
  default:
    int diference = abs(guess - SECRET_NUMBER);
    show_distance_message(diference);
    result = 0;
    break;
  }

  return result;
}

int main(void) {
  int guess;
  int game_over = 0;

  printf("=== Jogo: Adivinhe o numero entre %d e %d ===\n", MIN_LIMIT,
         MAX_LIMIT);

  while (game_over == 0) {
    printf("Digite um numero entre %d e %d: ", MIN_LIMIT, MAX_LIMIT);
    if (scanf("%d", &guess) != 1) {
      printf("Entrada invalida! Encerrando o Programa.\n");
      game_over = 1;
    } else
      game_over = verify_result(guess);
  }
}
