#include "../headers/cub.h"

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

void	fill_data(t_mlx *mlx, int fd)
{
	int i;

	i = mlx->img.width * mlx->img.height - 1;
	while (i >= 0)
	{
		write(fd, &mlx->img.data[i * mlx->img.bpp / 8], 4);
		i--;
	}
}

void	vertical_pix(t_mlx *mlx, int line, int *i, int j)
{
	char	save;
	int		k;

	k = 3;
	while (k >= 0)
	{
		save = mlx->img.data[*i + (line * mlx->img.size_l)];
		mlx->img.data[*i + (line * mlx->img.size_l)] =
			mlx->img.data[j - k + (line * mlx->img.size_l - 1)];
		mlx->img.data[j - k + (line * mlx->img.size_l - 1)] =
			save;
		k--;
		*i = *i + 1;
	}
}

void	vertical(int fd, t_mlx *mlx)
{
	int y;
	int x;
	int hex;

	y = mlx->img.height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < mlx->img.width)
		{
			hex = mlx->img.data[y * mlx->img.width + x];
			write(fd, &hex, sizeof(int));
			x++;
		}
		y--;
	}
}

void	header_bmp(t_mlx *mlx, int fd)
{
	int header_size;
	int nb_plane;
	int i;

	i = 0;
	nb_plane = 1;
	header_size = 40;
	write(fd, &header_size, 4);
	write(fd, &mlx->img.width, 4);
	write(fd, &mlx->img.height, 4);
	write(fd, &nb_plane, 2);
	write(fd, &mlx->img.bpp, 2);
	while (i < 28)
	{
		write(fd, "\0", 1);
		i++;
	}
}

void	bitmap(t_mlx *mlx)
{
	int		fd;
	int		file_size;
	int		begin_file;
	char	*filename;

	filename = ft_strdup("screen.bmp");
	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
	file_size = 58 + (mlx->img.width * mlx->img.height) * 4;
	begin_file = 58;
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &begin_file, 4);
	header_bmp(mlx, fd);
	vertical(fd, mlx);
	close(fd);
	free(filename);
}
