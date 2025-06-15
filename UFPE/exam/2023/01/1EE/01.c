#include "stdio.h"

int triangulo_e_possivel(int angulos[3]) {
  if (angulos[0] <= 0 || angulos[1] <= 0 || angulos[2] <= 0) {
    return 0;
  }

  int soma_dos_angulos = angulos[0] + angulos[1] + angulos[2];

  return soma_dos_angulos == 180 ? 1 : 0;
}

int e_triangulo_retangulo(int angulos[3]) {
  int possui_um_angulo_de_90 =
      (angulos[0] == 90 && angulos[1] != 90 && angulos[2] != 90) ||
      (angulos[1] == 90 && angulos[0] != 90 && angulos[2] != 90) ||
      (angulos[2] == 90 && angulos[0] != 90 && angulos[1] != 90);
  return triangulo_e_possivel(angulos) && possui_um_angulo_de_90;
}

int angulo_e_obtuso(int angulo) { return angulo > 90 && angulo < 180; }

int e_triangulo_obtusangulo(int angulos[3]) {
  int possui_um_angulo_obtuso =
      (angulo_e_obtuso(angulos[0]) && !angulo_e_obtuso(angulos[1]) &&
       !angulo_e_obtuso(angulos[2])) ||
      (angulo_e_obtuso(angulos[1]) && !angulo_e_obtuso(angulos[0]) &&
       !angulo_e_obtuso(angulos[2])) ||
      (angulo_e_obtuso(angulos[2]) && !angulo_e_obtuso(angulos[0]) &&
       !angulo_e_obtuso(angulos[1]));
  return triangulo_e_possivel(angulos) && possui_um_angulo_obtuso;
}

int e_actuangulo(int angulos[3]) {
  int possui_angulos_agudos =
      angulos[0] < 90 && angulos[1] < 90 && angulos[2] < 90;

  return triangulo_e_possivel(angulos) && possui_angulos_agudos;
}

int main() {

  int angulos[3];

  for (int i = 0; i < 3; i++) {
    printf("Escreva o valor do Angulo n: %d Do Triangulo: \n", i + 1);
    scanf("%d", &angulos[i]);
  }

  if (e_triangulo_retangulo(angulos)) {
    printf("E um Triangulo Retangulo\n");
    return 0;
  }

  if (e_triangulo_obtusangulo(angulos)) {
    printf("E um Triangulo Obtusangulo\n");
    return 0;
  }
  if (e_actuangulo(angulos)) {
    printf("E um Triangulo Acutangulo\n");
    return 0;
  }

  printf("Triangulo invalido\n");
  return 0;
}
