#include <stdio.h>

int main() {
  float celsius, fahrenheit;
  scanf("%f", &celsius);
  fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
  printf("%.2f\n", fahrenheit);
  return 0;
}

