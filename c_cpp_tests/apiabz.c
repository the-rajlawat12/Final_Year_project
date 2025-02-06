#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
  char Buf[10] = {0};

  strcpy(Buf, argv[1]);

  return 0;
}