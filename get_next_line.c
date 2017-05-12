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
	char			*tmp;

	if (fd < 0 || !line)
		return (-1);
	if (!(*line = (char *)malloc(BUFF_SIZE + 1 * sizeof(char))))
		return (-1);
	ft_memset(*line, '\0', (size_t)(BUFF_SIZE + 1));
	if (buff_end == NULL)
	{
		if (!(buff_end = (char *)malloc(BUFF_SIZE + 1 * sizeof(char))))
			return (-1);
		ft_memset(buff_end, '\0', (size_t)(BUFF_SIZE + 1));
	}
	i = 0;
	ret = 0;
	if (check_nl(buff_end) == 1 || check_nl(buff_end) == -1)
	{
		while (buff_end[i] != '\n' && buff_end[i] != -1)
			i++;
		*line = ft_strncpy(*line, buff_end, i);
	}
	else
		ret = read_till_nl(fd, buff_end, line);
	if (ft_strlen(buff_end) > 0 && check_nl(buff_end) == 1)
		buff_end = ft_strchr(buff_end, '\n') + 1;
	if (ret < BUFF_SIZE)
	{
		if (!(tmp = (char *)malloc(2 * sizeof(char))))
			return (-1);
		ft_memset(tmp, '\0', 2);
		tmp[0] = -1;
		tmp[1] = '\0';
		buff_end = str_memcat(buff_end, tmp);
	}
	if (buff_end[0] == -1 && ret == 0)
		return (0);
	return (1);
}

int		read_till_nl(int fd, char *buff_end, char **line)
{
	int	i;
	int	ret;
	char	*tmp;

	tmp = ft_strnew((size_t)(BUFF_SIZE + 1));
	ret = -1;
	while (check_nl(buff_end) == 0 && ret != 0)
	{
		*line = str_memcat(*line, buff_end);
		ret = read(fd, buff_end, BUFF_SIZE);
		buff_end[ret] = '\0';
	}
	i = 0;
	while (buff_end[i] != '\n' && buff_end[i] != '\0')
	{
		tmp[i] = buff_end[i];
		i++;
	}
	tmp[i] = '\0';
	*line = str_memcat(*line, tmp);
	return (ret);
}

char		*str_memcat(char *mem1, char *mem2)
{
	char *tmp;

	if (!(tmp = (char *)malloc(ft_strlen(mem1) + ft_strlen(mem2) + 1)))
		return (NULL);
	ft_memset(tmp, '\0', (size_t)(ft_strlen(mem1) + ft_strlen(mem2) + 1));
	ft_memcpy(tmp, mem1, ft_strlen(mem1));
	ft_memcpy(tmp + ft_strlen(mem1), mem2, ft_strlen(mem2));
	tmp[ft_strlen(mem1) + ft_strlen(mem2)] = '\0';
	//ft_strdel(&mem1);
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
		if (str[i] == -1)
			return (-1);
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
		}
	}
	else
		ft_putendl("File missing");
	return (0);
}
