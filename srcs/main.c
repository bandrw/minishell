#include "libft.h"
#include "fcntl.h"

int main(void)
{
	char *line;

	int fd = open("../srcs/main.c", O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putendl_fd(line, 1);
		free(line);
	}
	ft_putendl_fd(line, 1);
	free(line);
	return (0);
}
