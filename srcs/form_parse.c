#include "../headers/cub.h"

int		form_parse(char *av1)
{
	int fd;
	char *str;
	int ret;
	int len;

	len = 0;
	fd = open(av1,O_RDWR);
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		printf("%s\n", str);
		free(str);
		len++;
	}
	write(fd, "\n\n\n", 3);
	close(fd);
	// printf("%s\n", str);
	// free(str);	/
}