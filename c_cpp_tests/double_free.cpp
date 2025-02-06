#include <cstdint>
#include <cstdlib>
#include <iostream>

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

int main() {
  char *str = allocate_string(32); // <--
  char *str2 = allocate_string(40);

  memset(str, 'A', 32);
  memset(str2, 'B', 40);

  std::cout << str << std::endl;

  free(str);

  std::cout << str2 << std::endl;

  free(str);

  return 0;
}