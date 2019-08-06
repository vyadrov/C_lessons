#include <stdio.h>

int main(void)
{
  int c;
  printf("Please enter any text:\n");
  c = getchar();
  while (c != EOF) {
    putchar(c);
    if (c == ' ')
      while ((c = getchar()) == ' ');
    else
      c = getchar();

  }
  return 0;
}