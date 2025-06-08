#include <stdio.h>

int main() {

  float voltage;
  float resistor1;
  float resistor2;
  float resistor3;

  scanf("%f %f %f %f", &voltage, &resistor1, &resistor2, &resistor3);

  float total_resistence = resistor1 + resistor2 + resistor3;
  float total_current = voltage / total_resistence;
  float total_power = voltage * total_current;

  printf("============ RESULTADOS ============\n");
  printf("Resistencia total equivalente: %.2f ohms\n", total_resistence);
  printf("Corrente total do circuito: %.4f A\n", total_current);
  printf("Potencia total dissipada: %.4f W\n", total_power);
  printf("====================================\n");
}
