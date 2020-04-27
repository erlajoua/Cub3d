#include  "cub.h"

int main(void)
{
    /*

    ***
    ***
    ***

    */
    void *mlx;
    void *win1;

    mlx = mlx_init();
    win1 = mlx_new_window(mlx, 560, 420, "Thomas fenetre");

    mlx_loop(mlx);
    return (0);
}
