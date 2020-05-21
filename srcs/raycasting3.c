#include "../headers/cub.h"

void	raydirxy(t_info *infos)
{
	infos->mapx = (int)infos->posx;
	infos->mapy = (int)infos->posy;
	infos->camerax = 2 * infos->x / (double)infos->RESX - 1;
	infos->raydirx = infos->dirx + infos->planex * infos->camerax;
	infos->raydiry = infos->diry + infos->planey * infos->camerax;
	infos->deltadistx = (infos->raydiry == 0) ? 0 :
	((infos->raydirx == 0) ? 1 : fabs(1 / infos->raydirx));
	infos->deltadisty = (infos->raydirx == 0) ? 0 :
	((infos->raydiry == 0) ? 1 : fabs(1 / infos->raydiry));
}


