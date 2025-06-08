#include <stdio.h>

char to_lower_case(char c) {
  if (c >= 'A' && c <= 'Z') {
    return c + ('a' - 'A');
  }

  return c;
}

int is_vowel(char c) {
  switch (c) {
  case 'a':
  case 'A':
  case 'e':
  case 'E':
  case 'i':
  case 'I':
  case 'o':
  case 'O':
  case 'u':
  case 'U':
    return 1;
  default:
    return 0;
  }
}

int main(int argc, char *argv[]) {

  char input_char;

  scanf(" %c", &input_char);

  // input_char = to_lower_case(input_char);

  if (is_vowel(input_char)) {
    printf("%c eh uma vogal.\n", input_char);
  } else {
    printf("%c nao eh uma vogal.\n", input_char);
  }
}
