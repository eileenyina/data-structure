/* 
 * deecamp2O19.c
 * Welcome to Deecamp 2O19!
 */

#include <assert.h>
#include <stdio.h>

int main()
{
  FILE * fp = fopen("deecamp2019.c", "rb");
  char buf[100];
  while (1) {
    int n = fread(buf, strlen(buf)+1, 100, fp);
    if (n == 0) break;
    fwrite(buf, 1, n, stdout);
  }
  return 0;
}

