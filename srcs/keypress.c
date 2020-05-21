#include "../headers/cub.h"

void	updown(t_mlx *mlx, t_info *infos, t_cub *cub, int key)
{
	char dirside;

	dirside = cub->parse.side;
	infos->mvspeed *= (key == 115) ? -1 : 1;
	if (cub->parse.map[(int)(infos->posx + infos->dirx *
	infos->mvspeed)][(int)(infos->posy)] == '0'
	|| cub->parse.map[(int)(infos->posx + infos->dirx *
	infos->mvspeed)][(int)(infos->posy)] == dirside)
		infos->posx += infos->dirx * infos->mvspeed;
	if (cub->parse.map[(int)(infos->posx)][(int)(infos->posy + infos->diry *
	infos->mvspeed)] == '0'
	|| cub->parse.map[(int)(infos->posx)][(int)(infos->posy + infos->diry *
	infos->mvspeed)] == dirside)
		infos->posy += infos->diry * infos->mvspeed;
}

void	mv_lr(t_mlx *mlx, t_info *infos, t_cub *cub, int key)
{
	char dirside;

	dirside = cub->parse.side;
	infos->mvspeed *= (key == 100) ? -1 : 1;
	if (cub->parse.map[(int)(infos->posx)][(int)(infos->posy - infos->dirx *
	infos->mvspeed)] == '0'
	|| cub->parse.map[(int)(infos->posx)][(int)(infos->posy - infos->dirx *
	infos->mvspeed)] == dirside)
		infos->posy -= infos->dirx * infos->mvspeed;
	if (cub->parse.map[(int)(infos->posx + infos->mvspeed *
	infos->diry)][(int)(infos->posy)] == '0'
	|| cub->parse.map[(int)(infos->posx + infos->mvspeed *
	infos->diry)][(int)(infos->posy)] == dirside)
		infos->posx += infos->diry * infos->mvspeed;
}

void	cam_lr(t_mlx *mlx, t_info *infos, t_cub *cub, int key)
{
	double olddirx;
	double oldplanex;
	double angle;

	angle = (D_PI / 30) * -1;
	angle *= (key == 65363) ? -1 : 1;
	olddirx = infos->dirx;
	oldplanex = infos->planex;
	infos->dirx = infos->dirx * cos(angle) - infos->diry * sin(angle);
	infos->diry = olddirx * sin(angle) + infos->diry * cos(angle);
	infos->planex = infos->planex * cos(angle) - infos->planey * sin(angle);
	infos->planey = oldplanex * sin(angle) + infos->planey * cos(angle);
}

int	keypressed(int key, void *p)
{
	void		**recup;
	t_info		*infos;
	t_mlx		*mlx;
	t_cub		*cub;

	recup = (void **)p;
	infos = recup[0];
	mlx = recup[1];
	cub = recup[2];
	if (key == 65307)
		exit(0);
	infos->mvspeed = 0.4;
	if (key == 122 || key == 115)
	{
		updown(mlx, infos, cub, key);
		all(((t_info *)recup[0]), ((t_mlx *)recup[1]), ((t_cub *)recup[2]));
	}
	else if (key == 113 || key == 100)
	{
		mv_lr(mlx, infos, cub, key);
		all(((t_info *)recup[0]), ((t_mlx *)recup[1]), ((t_cub *)recup[2]));
	}
	else if (key == 65361 || key == 65363)
	{
		cam_lr(mlx, infos, cub, key);
		all(((t_info *)recup[0]), ((t_mlx *)recup[1]), ((t_cub *)recup[2]));
	}
	return (1);
}
