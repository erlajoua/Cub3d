#include "../headers/cub.h"

void     delete_sp(char *str)
{
    int i;
    int j;

    i = 0;
    while (str[i] != ' ' && str[i])
        i++;
    if (str[i] != '\0')
    {
        j = i;
        while (str[j] == ' ')
            j++;
        if (j > 0)
            str[i] = '\0';
    }
}