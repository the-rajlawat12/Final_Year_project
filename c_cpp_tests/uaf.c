#include <stdint.h> // sized integer types
#include <stdio.h>  // printf
#include <stdlib.h> // allocators and co
#include <string.h> // str and mem helpers
#include <wchar.h>  // wmemset, wchar* helper functions

wchar_t *allocate_wide_string(uint64_t len) {
  wchar_t *wstr = (wchar_t *)malloc((len + 1) * sizeof(wchar_t));

  if (!wstr) {
    return NULL;
  }

  wmemset(wstr, L'\0', len + 1);

  return wstr;
}

char *allocate_string(uint64_t len) {
  char *str = (char *)malloc((len + 1) * sizeof(char));

  if (!str) {
    return NULL;
  }

  memset(str, 0x00, sizeof(char) * (len + 1));

  return str;
}

int main() {
  char *str = allocate_string(20);          // init , allocate  lt 0
  wchar_t *wstr = allocate_wide_string(20); // lt 1

  memset(str, 'A', 20);
  wmemset(wstr, L'A', 20); // use

  free(str);

  *str = 'B'; // UAF
  *wstr = L'C';

  free(wstr); // free
  wstr = allocate_wide_string(65);

  *wstr = L'E'; // again

  return 0;
}
