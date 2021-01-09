#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
# define BUFFER_SIZE 2048

int ft_strlen(char *str)
{
    int i;
    i = 0;
    while (str[i])
        i++;
    return (i);
}
char *ft_strjoin(char *s1, char *s2)
{
    char *res;
    int both;
    int i;
    int y;
    both = ft_strlen(s1) + ft_strlen(s2);
    if (!(res = malloc(both + 1)))
        return (NULL);
    i = 0;
    while (s1[i])
    {
        res[i] = s1[i];
        i++;
    }
    y = 0;
    while (s2[y])
    {
        res[i] = s2[y];
        i++;
        y++;
    }
    res[i] = '\0';
    free(s1);
    return (res);
}
char *ft_substr(char *str, int start, int len)
{
    int i;
    char *res;
    if (!(res = malloc(len + 1)))
        return (NULL);
    i = 0;
    while (i < len)
    {
        res[i] = str[start];
        start++;
        i++;
    }
    res[i] = '\0';
    return (res);
}
int front(char **line, char **str)
{
    if (!line)
        return (0);
    if (!*str)
    {
        *str = malloc(BUFFER_SIZE + 1);
        *str[0] = '\0';
    }
    return (1);
}
int ft_free(char **line, char **str, int pos)
{
    if (line && *line)
    {
        free(line);
        *line = NULL;
    }
    if (str && *str)
    {
        free(*str);
        *str = NULL;
    }
    return (pos);
}
int spot(char *str)
{
    int i;
    i = 0;
    if (str[i] == '\n')
        return (i);
    while (str[i])
    {
        if (str[i] == '\n')
            return (i);
        i++;
    }
    return (-1);
}
int track_line(char **line, char **pt_str)
{
    int len;
    char *temp;
    if ((len = spot(*pt_str)) >= 0)
    {
        if (!(*line = ft_substr(*pt_str, 0, len)))
            return (ft_free(line, pt_str, -1));
        if (!(temp = ft_substr(*pt_str, len + 1, (ft_strlen(*pt_str) - len))))
            return (ft_free(line, pt_str, -1));
        free(*pt_str);
        *pt_str = temp;
        return (1);
    }
    return (0);
}
int gnl(char **line, int fd)
{
    char buf[BUFFER_SIZE + 1];
    int rdbytes;
    static char *str;
    if (!front(line, &str))
        return (-1);
    if (track_line(line, &str))
        return (1);
    while ((rdbytes = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[rdbytes] = 0;
        if (!(str = ft_strjoin(str, buf)))
            return (ft_free(line, &str, -1));
        if (track_line(line, &str))
            return (1);
    }
    if (track_line(line, &str))
        return (1);
    if (!(*line = ft_substr(str, 0, ft_strlen(str))))
        return (ft_free(line, &str, -1));
    return (ft_free(NULL, &str, 0));
}
int main(int ac, char **av)
{
    char *line;
    int fd;
	int ret = 0;
    fd = open(av[1], O_RDONLY);
    while ((ret = gnl(&line, fd)) > 0)
    {
        printf("[%d] : %s\n", ret, line);
        free(line);
    }
    printf("[%d] : %s\n", ret, line);
    free(line);
//    system("leaks a.out");
    return (0);
}
