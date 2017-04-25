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

	if (fd < 0 || !line)
		return (-1);
	if (!(*line = (char *)malloc(BUFF_SIZE + 1 * sizeof(char))))
		return (-1);
	ft_memset(*line, '\0', BUFF_SIZE + 1);
	if (buff_end == NULL)
	{
		if (!(buff_end = (char *)malloc(BUFF_SIZE + 1 * sizeof(char))))
			return (-1);
		ft_memset(buff_end, '\0', BUFF_SIZE + 1);
	}
	i = 0;
	if (check_nl(buff_end) == 1)
	{
		while (buff_end[i] != '\n')
			i++;
		*line = ft_strncpy(*line, buff_end, i);
	}
	else
		read_till_nl(fd, buff_end, line);
	if (ft_strlen(buff_end) > 0 && check_nl(buff_end) == 1)
		buff_end = ft_strchr(buff_end, '\n') + 1;
	if (ft_strlen(buff_end) == 0)
		if ((ret = fill_buffer(fd, buff_end) == 0) && check_nl(buff_end) == 0)
			return (0);
	return (1);
}

int		fill_buffer(int fd, char *buff_end)
{
	int		ret;
	char	*tmp;

	tmp = ft_strnew((size_t)(BUFF_SIZE + 1));
	ret = read(fd, tmp, BUFF_SIZE);
	tmp[ret] = '\0';
	buff_end = ft_strcat(buff_end, tmp);
	return (ret);
}

int		read_till_nl(int fd, char *buff_end, char **line)
{
	int	i;
	int	ret;
	char	*tmp;
	char *tmp2;

	tmp = ft_strnew((size_t)(BUFF_SIZE + 1));
	while (check_nl(buff_end) == 0)
	{
		*line = ft_strjoin(*line, buff_end);		
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
	//Proper concat == ft_strjoin(*line, tmp)
	tmp2 = (char *)malloc(ft_strlen(*line) + ft_strlen(tmp) + 1);
	ft_memset(tmp2, '\0', ft_strlen(*line) + ft_strlen(tmp) + 1);
	ft_memcpy(tmp2, *line, ft_strlen(*line));
	ft_memcpy(tmp2 + ft_strlen(*line), tmp, ft_strlen(tmp));
	tmp2[ft_strlen(*line) + ft_strlen(tmp)] = '\0';
	*line = tmp2;
	//End concat // free ?
	return (ret);
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
		}
		ft_putnbr(gnl);
		ft_putendl(" // Line :");
		ft_putstr(line);
	}
	else
		ft_putendl("File missing");
	return (0);
}
