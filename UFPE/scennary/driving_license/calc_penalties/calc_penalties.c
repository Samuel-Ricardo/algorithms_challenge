#include <stdbool.h>
#include <stdio.h>

#define PENALTY_SIGNAL 3
#define PENALTY_SHIFITING 1
#define PENALTY_ENGINE 3
#define PENALTY_BEACON 4
#define POINTS_LIMIT 3

int calculatePenalties(int signals, int shifting, int engine) {
  return (PENALTY_SIGNAL * signals) + (PENALTY_SHIFITING * shifting) +
         (PENALTY_ENGINE * engine);
}

bool isApproved(int points) { return points <= POINTS_LIMIT; }

int main() {

  char beatInBeacon;
  int signals = 0, shifting = 0, engine = 0, points = 0;

  printf("O Candidato bateu na baliza?\n");
  scanf("%c", &beatInBeacon);

  if (beatInBeacon == 'S' || beatInBeacon == 's') {
    printf("Candidato reprovado por bater na baliza.\n");
    return 0;
  }

  printf("Quantas vezes o candidato esqueceu de ligar a seta?\n");
  scanf("%d", &signals);

  printf("Quantas vezes o carro deu tranco?\n");
  scanf("%d", &shifting);

  printf("Quantas vezes o carro morreu?\n");
  scanf("%d", &engine);

  points = calculatePenalties(signals, shifting, engine);
  bool approved = isApproved(points);

  if (approved)
    printf("Candidato aprovado. Pontos de Penalidades: %d.\n", points);
  else
    printf("Candidato reprovado. Pontos de Penalidades: %d.\n", points);

  return 0;
}
