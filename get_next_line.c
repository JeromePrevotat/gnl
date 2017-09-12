/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 14:59:53 by jprevota          #+#    #+#             */
/*   Updated: 2017/04/24 18:02:45 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#include "./libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		get_next_line(const int fd, char **line)
{
	char	*buff;
	int		ret;

	ret = 1;
	if (!line || !(*line = (char *)malloc(BUFF_SIZE + 1 * sizeof(char)))
		|| fd < 0)
		return (-1);
	ft_memset(*line, '\0', (size_t)(BUFF_SIZE + 1));
	if (!(buff = (char *)malloc((BUFF_SIZE + 1) * sizeof(char))))
		return (-1);
	ft_memset(buff, '\0', (size_t)(BUFF_SIZE + 1));
	return (gnl(buff, line, fd, ret));
}

int		gnl(char *buff, char **line, const int fd, int ret)
{
	static char	buff_end[BUFF_SIZE + 1];
	int			i;

	buff = ft_memcpy(buff, buff_end, ft_strlen(buff_end));
	ft_memset(buff_end, '\0', BUFF_SIZE + 1);
	while (ret > 0)
	{
		if ((i = check_nl(buff)) >= 0)
		{
			*line = str_memcat(*line, buff, i);
			ft_memcpy(buff_end, buff + i + 1, ft_strlen(buff) - i - 1);
			free(buff);
			return (1);
		}
		*line = str_memcat(*line, buff, ft_strlen(buff));
		if ((ret = fill_buffer(fd, buff)) == -1)
			return (-1);
		if (ret == 0 && ft_strlen(*line) > 0)
			return (1);
	}
	free(buff);
	return (0);
}

int		fill_buffer(int fd, char *buff)
{
	int		ret;

	if ((ret = read(fd, buff, BUFF_SIZE)) == -1)
		return (-1);
	buff[ret] = '\0';
	return (ret);
}

char	*str_memcat(char *mem1, char *mem2, size_t size)
{
	char	*tmp;

	if (!(tmp = (char *)malloc(ft_strlen(mem1) + size + 1)))
		return (NULL);
	ft_memset(tmp, '\0', (size_t)(ft_strlen(mem1) + size + 1));
	ft_memcpy(tmp, mem1, ft_strlen(mem1));
	ft_memcpy(tmp + ft_strlen(mem1), mem2, size);
	tmp[ft_strlen(mem1) + size] = '\0';
	if (mem1 != NULL)
		free(mem1);
	return (tmp);
}

int		check_nl(char *str)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
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
		free(line);
	}
	else
		ft_putendl("File missing");
	return (0);
}
