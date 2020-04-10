#include "cub.h"

int check_two(t_cub cub, int i, int j)
{
	char *s;

	s = ft_strdup("012");
	if ((find_in(cub.parse.map[j][i - 1], s) == 1) && (find_in(cub.parse.map[j][i + 1], s) == 1) && (find_in(cub.parse.map[j - 1][i], s) == 1) && (find_in(cub.parse.map[j + 1][i], s) == 1))
	{
		return 1;
	}
	else
		return 0;
}

int check_zr(t_cub cub, int i, int j)
{
	char *s;

	s = ft_strdup("012");
	if (i == 0)
	{
		if ((find_in(cub.parse.map[j][i + 1], s) == 1) && (find_in(cub.parse.map[j - 1][i], s) == 1) && (find_in(cub.parse.map[j + 1][i], s) == 1))
		{
			return 1;
		}
		else
			return 0;
	}
	if (i == cub.parse.strlen - 1)
	{
		if ((find_in(cub.parse.map[j][i - 1], s) == 1) && (find_in(cub.parse.map[j - 1][i], s) == 1) && (find_in(cub.parse.map[j + 1][i], s) == 1))
		{
			return 1;
		}
		else
			return 0;
	}
	else
	{
		if ((find_in(cub.parse.map[j][i - 1], s) == 1) && (find_in(cub.parse.map[j][i + 1], s) == 1) && (find_in(cub.parse.map[j - 1][i], s) == 1) && (find_in(cub.parse.map[j + 1][i], s) == 1))
		{
			return 1;
		}
		else
			return 0;
	}
}

int check_sp(t_cub cub, int i, int j)
{
	char *s;

	//printf("\nCHECKSPACE : Values : i , j : %d , %d\n", i, j);
	s = ft_strdup("1 ");
	if (i == 0)
	{
		if ((find_in(cub.parse.map[j][i + 1], s) == 1) && (find_in(cub.parse.map[j - 1][i], s) == 1) && (find_in(cub.parse.map[j + 1][i], s) == 1))
		{
			return 1;
		}
		else
			return 0;
	}
	if (i == cub.parse.strlen - 1)
	{
		if ((find_in(cub.parse.map[j][i - 1], s) == 1) && (find_in(cub.parse.map[j - 1][i], s) == 1) && (find_in(cub.parse.map[j + 1][i], s) == 1))
		{
			return 1;
		}
		else
			return 0;
	}
	else
	{
		if ((find_in(cub.parse.map[j][i - 1], s) == 1) && (find_in(cub.parse.map[j][i + 1], s) == 1) && (find_in(cub.parse.map[j - 1][i], s) == 1) && (find_in(cub.parse.map[j + 1][i], s) == 1))
		{
			return 1;
		}
		else
			return 0;
	}
}

int check_one(t_cub cub, int i, int j)
{
	char *s;

	s = ft_strdup(" 012");
	if (i == 0)
	{
		if ((find_in(cub.parse.map[j][i + 1], s) == 1) && (find_in(cub.parse.map[j - 1][i], s) == 1) && (find_in(cub.parse.map[j + 1][i], s) == 1))
		{
			return 1;
		}
		else
			return 0;
	}
	if (i == cub.parse.strlen - 1)
	{
		if ((find_in(cub.parse.map[j][i - 1], s) == 1) && (find_in(cub.parse.map[j - 1][i], s) == 1) && (find_in(cub.parse.map[j + 1][i], s) == 1))
		{
			return 1;
		}
		else
			return 0;
	}
	else
	{
		if ((find_in(cub.parse.map[j][i - 1], s) == 1) && (find_in(cub.parse.map[j][i + 1], s) == 1) && (find_in(cub.parse.map[j - 1][i], s) == 1) && (find_in(cub.parse.map[j + 1][i], s) == 1))
		{
			return 1;
		}
		else
			return 0;
	}
}
