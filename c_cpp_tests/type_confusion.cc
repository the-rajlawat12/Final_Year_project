// write your C code here
// or drop of your file in the editor
#include <stdio.h>

class A {
public:
  int a, b, c;
};

class B : A {
public:
  int c, d, e;
};

int main() {
  A *a = new A();
  B *b = (B *)b;
  printf("Hello, World!");
  return 0;
}