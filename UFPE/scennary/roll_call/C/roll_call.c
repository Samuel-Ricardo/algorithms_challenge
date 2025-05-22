
#include <stdio.h>
#include <string.h>
#define MAX_NAME_LENGTH 51
#define TOTAL_STUDENTS 5

typedef enum { PRESENCE, ABSENCE } PresenceStatus;

typedef struct {
  char name[MAX_NAME_LENGTH];
  PresenceStatus status;
} Student;

void readStudent(char *name, int index) {
  printf("Digite o nome do %d- estudante: ", index + 1);
  fgets(name, MAX_NAME_LENGTH, stdin);
  name[strcspn(name, "\n")] = '\0'; // NOTE: REMOVE NEW LINE
}

PresenceStatus readStatus(int index) {
  char input;

  printf("Digite P se o aluno esta presente ou F se ele foi ausente: ");
  scanf("%c", &input);
  getchar(); // NOTE: CLEAR KEYBOARD BUFFER

  if (input == 'P' || input == 'p')
    return PRESENCE;

  return ABSENCE;
}

void renderRollCall(Student students[], int total) {
  printf("\n--- Lista de Chamada ---\n\n");
  for (int i = 0; i < total; i++) {
    const char *status_str =
        (students[i].status == PRESENCE) ? "Presente" : "Faltou";
    printf("%s - %s\n", students[i].name, status_str);
  }
}

int main() {

  Student students[TOTAL_STUDENTS];

  for (int i = 0; i < TOTAL_STUDENTS; i++) {
    readStudent(students[i].name, i);
    students[i].status = readStatus(i);
  }

  renderRollCall(students, TOTAL_STUDENTS);
}
