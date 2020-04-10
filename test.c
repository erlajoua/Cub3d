#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main() {

  char **map;

  map = (char **)malloc(sizeof(char *) * 2);
  *map = strdup("coucou");
  map++;
  *map = strdup("salut");

	printf("%s\n", *(--map));
  return 0;
}
