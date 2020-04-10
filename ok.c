#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
char    *ft_strdup(const char *s1)
{
    char    *s2;
    int        i;
 
    i = 0;
    while (s1[i])
        i++;
    s2 = malloc(sizeof(char) * i + 1);
    if (!s2)
        return (NULL);
    i = 0;
    while (s1[i])
    {
        s2[i] = s1[i];
        i++;
    }
    s2[i] = '\0';
    return (s2);
}
 
int   ft_strlen(char *str)
{
  int i;
 
  i = 0;
  while(str[i])
    i++;
  return (i);
}
 
void    fill_zero(char **map)
{
    int i;
    int j;
    char *s;
   
    int len = 0;
    int nbline = 4;
    int strlenmax = 16;
     
    i = 0;
    j = 0;
    while(j < nbline)
    {
      i = 0;
        len = ft_strlen(map[j]);
        s = ft_strdup(map[j]);
        map[j] = (char *)malloc(sizeof(char) * strlenmax + 1);
        while(i < strlenmax)
        {
            map[j][i] = 'x';
            i++;
        }
        map[j][i] = '\0';
        i = 0;
        while(i < len)
        {
            map[j][i] = s[i];
            i++;
        }
        j++;
    }
}
 
int main(void)
{
  char **map;
  int x = 0;
 
  map = (char **)malloc(sizeof(char *) * 4);
  map[0] = ft_strdup("11111");
  map[1] = ft_strdup("1000111111111");
  map[2] = ft_strdup("11111111");
  map[3] = ft_strdup("11111111111");
 
  fill_zero(map);
  while(x < 4)
  {
      printf("%s\n",map[x]);
      x++;
  }
  return (0);
}
