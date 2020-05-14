#include "cub.h"

// void    sort_spr(t_info *infos, t_cub *cub)
// {
//     int i;
//     double first;
//     double second;
//     double tmp;

//     i = 0;
//     tmp = 0;
//     while (i < infos->spr_nb)
//     {
//         infos->sprite[i].first = infos->spr_dist[i];
//         infos->sprite[i].second = infos->spr_order[i];
//         // printf("infos->sprite[i].first : %lf || infos->spr_order[i] : %d\n", infos->sprite[i].first, infos->spr_order[i]);
//         i++;
//     }
//     i = 0;
//     while (i+1 <= infos->spr_nb)
//     {
//         if (infos->sprite[i].first > infos->sprite[i+1].first && i+1 < infos->spr_nb)
//         {
//             tmp = infos->sprite[i+1].first;
//             infos->sprite[i+1].first = infos->sprite[i].first;
//             infos->sprite[i].first = tmp;
//             //  printf("infos->sprite[i+1].first  ->> %lf\n", infos->sprite[i].first);
//         }
//         i++;
//     }
    
//     i = 0;
//     while (i < infos->spr_nb)
//     {
//         infos->spr_dist[i] = infos->sprite[infos->spr_nb - i - 1].first;
//         infos->spr_order[i] = infos->sprite[infos->spr_nb - i - 1].second;
//         i++;
//     }
//     for(int j = 0; j < infos->spr_nb; j++)
//      {
//          printf("->> first : %lf \n", infos->spr_dist[j]);
//         //  printf("--> test : %lf\n",infos->sprite[infos->spr_nb - i - 1].first);
// //     //     //  printf("sec : %d \n", infos->spr_order[j]);
//     }
//     printf("\n\n");
// }

void    start_spr(t_info *infos, t_cub *cub)
{
    int i;
    double first;
    double second;
    t_sprite tmp;

    i = 0;
    // printf("posx : %lf || posy : %lf || sprite[i].x : %lf || sprite[i].y : %lf\n", infos->posx, infos->posy,  infos->sprite[i+1].x,  infos->sprite[i+1].y);
    while (i < infos->spr_nb && i+1 != infos->spr_nb)
    {
        first = ((infos->posx - infos->sprite[i].x) * (infos->posx - infos->sprite[i].x)
                + (infos->posy - infos->sprite[i].y) * (infos->posy - infos->sprite[i].y));
        second = ((infos->posx - infos->sprite[i+1].x) * (infos->posx - infos->sprite[i+1].x)
                + (infos->posy - infos->sprite[i+1].y) * (infos->posy - infos->sprite[i+1].y));
        if (first < second)
        {
            tmp = infos->sprite[i];
            infos->sprite[i] = infos->sprite[i + 1];
            infos->sprite[i + 1] = tmp;
            i = -1;
        }
        i++;
    }
}

void    init_spr(t_info *infos, t_cub *cub)
{
    int x;
    int y;
    int nb;

    y = 0;
    nb = 0;
    if (!(infos->sprite = (t_sprite *)malloc(sizeof(t_sprite) * infos->spr_nb)))
        ft_error("error malloc number sprite");
    while (cub->parse.map[y] && y <= cub->parse.nbline - 1)
    {
        x = 0;
        while (cub->parse.map[y][x])
        {
            if (cub->parse.map[y][x] == '2')
            {
                infos->sprite[nb].x = (double)y + 0.5;
                infos->sprite[nb].y = (double)x + 0.5;
                infos->sprite[nb].txt = infos->txtr[4].img;
                // printf("x : %d || y : %d || infos->sprite[nb].x : %lf || infos->sprite[nb].y : %lf \n",x, y, infos->sprite[nb].x, infos->sprite[nb].y);
                nb++;
            }
            x++;
        }
        y++;
    }    
}

void    get_nb_spr(t_info *infos, t_cub *cub)
{
    int x;
    int y;

    x = 0;
    infos->spr_nb = 0;
    while (cub->parse.map[x] && x <= cub->parse.nbline - 1)
    {
        y = 0;
        while (cub->parse.map[x][y])
        {
            if (cub->parse.map[x][y] == '2')
                infos->spr_nb++;
            y++;
        }
        x++;
    }    
}

void    disp_spr(t_info *infos, t_cub *cub, t_mlx *mlx)
{

    int i;
    int j;
    int txt;
    int txtr_y;
    int *datatest;
    int res;

    i = 0;
    j = 0;
    txt = 0;
    txtr_y = 0;
    i = infos->drawstart_x;

    while (i < infos->drawend_x)
    {
        txt = (int)(256 * (i - (-infos->spr_w / 2 + infos->sprscreen_x)) * infos->txtr[4].width / infos->spr_w) / 256;
        if (infos->transy > 0 && i > 0 && i < infos->RESX && infos->transy < infos->zbuffer[i])
        {
            j = infos->drawstart_y;
            while (j < infos->drawend_y)
            {
                infos->drawstart = j * 256 - infos->RESY * 128 + infos->spr_h * 128;
                txtr_y = ((infos->drawstart * infos->txtr[4].height) / infos->spr_h) / 256;

                if (!(datatest = (int *)mlx_get_data_addr(infos->sprite[0].txt, &mlx->img.bpp, &mlx->img.size_l, &mlx->img.endian)))
                    printf("ERROROROOOOOOORR\n");
                res = datatest[txtr_y * 64 + txt];
                if (res && 0x00FFFFFF != 0)
                    mlx->img.data[j * infos->RESX + i] = res;
                j++;
            }
        }
        i++;
    }
}

void        calc_spr(t_info *infos, t_cub *cub, t_mlx *mlx)
{
    int i;

    i = 0;
    while (i < infos->spr_nb)
    {
        // infos->spr_x = infos->sprite[infos->spr_order[i]].x - infos->posx;
        // infos->spr_y = infos->sprite[infos->spr_order[i]].y - infos->posy;
        infos->spr_x = infos->sprite[i].x - infos->posx;
        infos->spr_y = infos->sprite[i].y - infos->posy;

        infos->invdet = 1.0 / (infos->planex * infos->diry - infos->dirx * infos->planey);
        infos->transx = infos->invdet * (infos->diry * infos->spr_x - infos->dirx * infos->spr_y);
        infos->transy = infos->invdet * (-infos->planey * infos->spr_x + infos->planex * infos->spr_y);
        infos->sprscreen_x = (int)((infos->RESX / 2) * (1 + infos->transx / infos->transy));
        infos->spr_h = abs((int)(infos->RESY / infos->transy));

        infos->drawstart_y = -infos->spr_h / 2 + infos->RESY / 2;
        if(infos->drawstart_y < 0)
            infos->drawstart_y = 0;

        infos->drawend_y = infos->spr_h / 2 + infos->RESY / 2;        
        if(infos->drawend_y >= infos->RESY)
            infos->drawend_y = infos->RESY - 1;

        infos->spr_w = abs((int)(infos->RESX / infos->transy));
       
        infos->drawstart_x = -infos->spr_w / 2 + infos->sprscreen_x;
        if(infos->drawstart_x < 0)
            infos->drawstart_x = 0;

        infos->drawend_x = infos->spr_w / 2 + infos->sprscreen_x;
        if(infos->drawend_x >= infos->RESX)
            infos->drawend_x = infos->RESX - 1;
        
        infos->sprite[0].txt = infos->txtr[4].img;
        disp_spr(infos, cub, mlx);
        i++;
    }
}




void    draw_sprite(t_info *infos, t_cub *cub, t_mlx *mlx)
{
    get_nb_spr(infos, cub);
    init_spr(infos, cub);
    start_spr(infos, cub);
    calc_spr(infos, cub, mlx);
}
