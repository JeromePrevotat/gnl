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

static int	check_nl(char *str)
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

static char	*str_memcat(char *mem1, char *mem2, size_t size, int reset)
{
	char	*tmp;

	if (!(tmp = (char *)malloc(ft_strlen(mem1) + size + 1)))
		return (NULL);
	ft_memset(tmp, '\0', (size_t)(ft_strlen(mem1) + size + 1));
	ft_memcpy(tmp, mem1, ft_strlen(mem1));
	ft_memcpy(tmp + ft_strlen(mem1), mem2, size);
	tmp[ft_strlen(mem1) + size] = '\0';
	if (reset == 1)
		ft_memset(mem2, '\0', BUFF_SIZE);
	if (mem1 != NULL)
		free(mem1);
	return (tmp);
}

static int	fill_buffer(int fd, char *buff)
{
	int		ret;

	if ((ret = read(fd, buff, BUFF_SIZE)) == -1)
		return (-1);
	buff[ret] = '\0';
	return (ret);
}

static int	gnl(char **line, const int fd, int ret)
{
	static char	buff_end[BUFF_SIZE];
	int			i;

	while (ret > 0)
	{
		if ((i = check_nl(buff_end)) >= 0)
		{
			*line = str_memcat(*line, buff_end, i, 0);
			ft_strcpy(buff_end, buff_end + i + 1);
			return (1);
		}
		*line = (ft_strlen(*line) + ft_strlen(buff_end) + 1 > 2048) ? str_memcat(*line, buff_end, ft_strlen(buff_end), 1) : ft_strncpy(*line, buff_end, ft_strlen(buff_end));
		//*line = str_memcat(*line, buff_end, ft_strlen(buff_end), 1);
		if ((ret = fill_buffer(fd, buff_end)) == -1)
			return (-1);
	}
	return (ft_strlen(*line) > 0 ? 1 : 0);
}

int			get_next_line(const int fd, char **line)
{
	int		ret;

	ret = 1;
	if (!line || !(*line = (char *)malloc(2048 * sizeof(char)))
		|| fd < 0)
		return (-1);
	ft_memset(*line, '\0', (size_t)(2048));
	return (gnl(line, fd, ret));
}
