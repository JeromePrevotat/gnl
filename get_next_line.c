/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 14:59:53 by jprevota          #+#    #+#             */
/*   Updated: 2017/04/24 18:02:45 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#include "./libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		get_next_line(const int fd, char **line)
{
	static char	*buff_end;
	int			i;
	int			ret;
	int			eof;

	if (!(*line = (char *)malloc(BUFF_SIZE + 1 * sizeof(char))) ||
		fd < 0 || !line)
		return (-1);
	ft_memset(*line, '\0', (size_t)(BUFF_SIZE + 1));
	if (buff_end == NULL)
	{
		if (!(buff_end = (char *)malloc((BUFF_SIZE + 1) * sizeof(char))))
			return (-1);
		ft_memset(buff_end, '\0', (size_t)(BUFF_SIZE + 1));
	}
	i = 0;
	ret = 1;
	eof = 0;
	while (eof == 0)
	{
		if (ret == 0)
			eof = 1;
		if (buff_end != NULL && check_nl(buff_end) == 1)
		{
			while (buff_end[i] != '\n')
				i++;
			*line = str_memcat(*line, buff_end, i);
			buff_end = ft_strchr(buff_end, '\n') + 1;
			return (1);
		}
		*line = str_memcat(*line, buff_end, ft_strlen(buff_end));
		if (eof != 1)
			ret = fill_buffer(fd, buff_end);
		if (eof == 1 && ft_strlen(*line) != 0)
			return (1);
	}
	return (0);
}

int 	fill_buffer(int fd, char *buff_end)
{
	int ret;
	char *buff;
	int i;

	if (!(buff = (char *)malloc(BUFF_SIZE + 1 * sizeof(char))))
		return (-1);
	ft_memset(buff, '\0', (size_t)(BUFF_SIZE + 1));
	ret = read(fd, buff, BUFF_SIZE);
	buff[ret] = '\0';
	i = 0;
	while (buff[i] != '\0')
	{
		buff_end[i] = buff[i];
		i++;
	}
	free(buff);
	return (ret);
}

char 	*str_memcat(char *mem1, char *mem2, size_t size)
{
	char *tmp;

	if (!(tmp = (char *)malloc(ft_strlen(mem1) + size + 1)))
		return (NULL);
	ft_memset(tmp, '\0', (size_t)(ft_strlen(mem1) + size + 1));
	ft_memcpy(tmp, mem1, ft_strlen(mem1));
	ft_memcpy(tmp + ft_strlen(mem1), mem2, size);
	tmp[ft_strlen(mem1) + size] = '\0';
	free(mem1);
	return (tmp);
}

int		check_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int			fd;
	char		*line;
	int			gnl;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			return (-1);
		while ((gnl = get_next_line(fd, &line)) != 0)
		{
			ft_putnbr(gnl);
			ft_putendl(" // Line :");
			ft_putstr(line);
			ft_putchar('\n');
			ft_memset(line, '\0', (size_t)(ft_strlen(line)));
			free(line);
		}
	}
	else
		ft_putendl("File missing");
	return (0);
}
