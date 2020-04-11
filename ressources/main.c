#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mlx.h"
#include <unistd.h>

typedef struct    data_s
{
    void          *mlx_ptr;
    void          *mlx_win;
	void			*img_ptr;
}                 data_t;

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int deal_key(int key, void *param)
{
	printf("%d\n", key);
	return 0;
}

int main(void)
{
    data_t        data;

    if ((data.mlx_ptr = mlx_init()) == NULL)
        return (EXIT_FAILURE);
    if ((data.mlx_win = mlx_new_window(data.mlx_ptr, 640, 480, "mlx42")) == NULL)
        return (EXIT_FAILURE);
	mlx_pixel_put(data.mlx_ptr, data.mlx_win, 250, 250, 0xFFFFFF);
	mlx_key_hook(data.mlx_win, deal_key, (void *)0);

	data.img_ptr = mlx_xpm_file_to_image (data.mlx_ptr, "orange.png", 100, 100);

	mlx_new_image (data.mlx_ptr, 100, 100);
	mlx_put_image_to_window (data.mlx_ptr, data.mlx_win, data.img_ptr, 250, 250 );
    mlx_loop(data.mlx_ptr);
    return (EXIT_SUCCESS);
}
