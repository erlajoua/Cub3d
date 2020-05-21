#include "../headers/cub.h"

void	ft_error(char *str)
{
	write(1, "Error\n", 6);
	write(1, str, ft_strlen(str));
	exit(0);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
