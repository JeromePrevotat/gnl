/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 14:59:53 by jprevota          #+#    #+#             */
/*   Updated: 2017/04/13 20:02:30 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#include "./libft/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		get_next_line(const int fd, char **line)
{
	static char	*buff_end;
	char		*tmp;
	int			i;

	i = 0;
	if (fd < 0)
		return (-1);
	if (buff_end == NULL && !(buff_end = (char *)malloc(BUFF_SIZE + 1 * sizeof(char))))
			return (-1);
	ft_strclr(*line);
	if (check_nl(buff_end) == 1)
	{
		while (buff_end[i] != '\n')
			i++;
		*line = ft_strncpy(*line, buff_end, i);
	}
	else
		*line = read_till_nl(fd, buff_end, line);
	buff_end = ft_strchr(buff_end, '\n') + 1;
	if ((tmp = check_eof(fd, buff_end)) == NULL)
		return (0);
	else
	{
		if (&buff_end != &tmp)
			buff_end = ft_strjoin(buff_end, tmp);
		free(tmp);
		return (1);
	}
	return (1);
}

char	*check_eof(int fd, char *buff_end)
{
	int		i;
	int		ret;
	char	*tmp;

	i = 0;
	while (i < (int)ft_strlen(buff_end))
	{
		if (buff_end[i] > 0)
			return (buff_end);
		i++;
	}
	tmp = ft_strnew((size_t)(BUFF_SIZE + 1));
	ret = read(fd, tmp, BUFF_SIZE);
	tmp[ret] = '\0';
	if (ret == 0)
		return (NULL);
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

char	*read_till_nl(int fd, char *buff, char **line)
{
	int		i;
	int		ret;
	char	*tmp;

	tmp = ft_strnew((size_t)(BUFF_SIZE + 1));
	while (check_nl(buff) != 1 && ret > 0)
	{
		*line = ft_strjoin(*line, buff);
		ret = read(fd, buff, BUFF_SIZE);
		buff[ret] = '\0';
	}
	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
	{
		tmp[i] = buff[i];
		i++;
	}
	tmp[i] = '\0';
	*line = ft_strjoin(*line, tmp);
	free(tmp);
	return (*line);
}

int		main(int argc, char **argv)
{
	int			fd;
	char		**line;
	int			gnl;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			return (-1);
		if (!(line = (char **)malloc(1 * sizeof(char *))))
			return (-1);
		*line = ft_strnew((size_t)(BUFF_SIZE + 1));
		while ((gnl = get_next_line(fd, line)) != 0)
		{
			ft_putnbr(gnl);
			ft_putendl("Line :");
			ft_putstr(*line);
			ft_putchar('\n');
		}
		ft_putnbr(gnl);
		ft_putstr(*line);
	}
	else
		ft_putendl("File missing");
	return (0);
}
