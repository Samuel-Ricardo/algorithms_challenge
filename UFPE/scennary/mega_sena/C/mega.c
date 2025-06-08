******************************************************************************

    Online C Compiler.Code,
    Compile,
    Run and Debug C program online
            .Write your code in this editor and press
        "Run" button to compile and execute it.

            ********************************************************************
                *********** /

#include <stdio.h>
#include <stdlib.h>

#define TOTAL_NUMBERS 6
#define MIN_NUMBER 1
#define MAX_NUMBER 60

        void cleanBuffer() {
  while (getchar() != "\n")
    ;
}

int compareNumbers(int user[], int sorted[]) {
  int checks = 0;

  for (int attemps = 0; attemps < TOTAL_NUMBERS; attemps++) {
    for (int compare = 0; compare < TOTAL_NUMBERS; compare++) {
      if (user[attemps] == sorted[compare]) {
        checks++;
        break;
      }
    }
  }

  return checks;
}

int out_of_range(int number) {
  return number < MIN_NUMBER || number > MAX_NUMBER;
}

int main() {

  int PLAY_AGAIN = 1;
  int NUMBERS[TOTAL_NUMBERS] = {1, 12, 23, 34, 45, 60};

  while (PLAY_AGAIN) {
    int userNumbers[TOTAL_NUMBERS];

    printf("\n--- Mega Sena ---\n");
    printf("Digite 6 numeros de 1 a 60:\n");

    for (int i = 0; i < TOTAL_NUMBERS; i++) {
      int number;

      do {
        printf("Numero %d: ", i + 1);
        if (scanf("%d", &number) != 1) {
          printf("Entrada invalida. Tente novamente.\n");
          cleanBuffer();
          number = 0;
        } else if (out_of_range(number)) {
          printf("Numero fora do intervalo, por favor tente de novo \n");
        } else {
          userNumbers[i] = number;
        }
      } while (out_of_range(number));
    }

    int asserts = compareNumbers(userNumbers, NUMBERS);

    if (asserts == TOTAL_NUMBERS) {
      printf("Parabens! Voce esta milionario!\n");
    } else {
      printf("Que pena! Voce perdeu :( \n");
    }

    printf("Deseja jogar novamente? (1 = sim / 0 = nao): ");
    scanf("%d", &PLAY_AGAIN);
  }
}

