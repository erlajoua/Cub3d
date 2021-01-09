#include "headers/cub.h"

int main(int ac, char **av)
{
    char *line;
    int fd;
	int ret = 0;
    fd = open(av[1], O_RDONLY);
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        printf("[%d] : %s\n", ret, line);
        free(line);
    }
    printf("[%d] : %s\n", ret, line);
    free(line);
//    system("leaks a.out");
    return (0);
}

