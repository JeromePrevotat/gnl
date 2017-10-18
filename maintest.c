#include "get_next_line.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char *line;
	int fd;
	int gnl;

	if (argc != 2)
		return (-1);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (-1);
	while ((gnl = get_next_line(fd, &line)))
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	close(fd);
	return (0);
}
