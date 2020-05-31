#include "../headers/cub.h"

void check_rgb_char(t_cub *cub, char *line)
{
    cub->rgb_i = 0;
    cub->sep = 0;
    cub->nb = 0;
    while (line[cub->rgb_i])
    {
        if (ft_isdigit(line[cub->rgb_i]) && line[cub->rgb_i])
        {
            cub->nb++;
            while (ft_isdigit(line[cub->rgb_i]) && line[cub->rgb_i])
                cub->rgb_i++;
        }
        if (line[cub->rgb_i] == ',' && line[cub->rgb_i])
            cub->sep++;
        if (!ft_isdigit(line[cub->rgb_i]) && line[cub->rgb_i] != ' '
            && line[cub->rgb_i] != ',' && line[cub->rgb_i])
            ft_error("Invalid character in rgb");
        cub->rgb_i++;
    }
    if (cub->sep != 2 || cub->nb != 3)
        ft_error("Invalid rgb format");
}

void    secure_rgb(t_cub *cub, char *line)
{
    int j;

    j = 0;
    check_rgb_char(cub, line);
    cub->rgb_i = 0;
    while (line[cub->rgb_i] && j < 3)
    {
        if (line[cub->rgb_i] && line[cub->rgb_i] == ' ' && j < 3)
            while (line[cub->rgb_i] && line[cub->rgb_i] == ' ')
                cub->rgb_i++;
        if (line[cub->rgb_i] && ft_isdigit(line[cub->rgb_i]) && j < 3)
            while (line[cub->rgb_i] && ft_isdigit(line[cub->rgb_i]))
                cub->rgb_i++;
        else
            ft_error("Format rgb invalid");
        if (line[cub->rgb_i] && line[cub->rgb_i] == ' ' && j < 2)
            while (line[cub->rgb_i] && line[cub->rgb_i] == ' ')
                cub->rgb_i++;
        if (line[cub->rgb_i] && line[cub->rgb_i] == ',' && j < 2)
            cub->rgb_i++;
        else if (line[cub->rgb_i] && line[cub->rgb_i] != ',' && j < 2)
            ft_error("Format rgb invalid");
        j++;
    }
}


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