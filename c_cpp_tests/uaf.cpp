#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <exception>
#include <stdexcept>

char *allocate_string(uint64_t len) {

  // %2
  char *buf = (char *)malloc((len + 1) * sizeof(char));

  if (buf == nullptr) { // %3: icmp eq ptr %2 , null
                        // Label 4: highly unlikely
    throw std::runtime_error("Failed to allocate string");
  }
  // Label 6
  memset(buf, '\0', (len + 1) * sizeof(char) /* 33 */);
  //
  return buf; // returns %2 filled with 0's
}

int main() {                       // %1: program ko lifetime
  char *str = allocate_string(32); // <--
  memset(str, 'A', 32);
  printf("%s\n", str);
  free(str);
  str = allocate_string(12);
  printf("%c", *str);
  return 0;
}