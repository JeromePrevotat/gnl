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
#include <stdio.h>

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

static char	*str_catfree(char *line, char *buff, int reset)
{
	char	*tmp;
	size_t	size;

	size = ft_strlen(line) + ft_strlen(buff) + 1;
	if (!(tmp = (char *)malloc(size * sizeof(char))))
		return (NULL);
	ft_memset(tmp, '\0', size);
	ft_memcpy(tmp, line, ft_strlen(line));
	ft_memcpy(tmp + ft_strlen(tmp), buff, ft_strlen(buff));
	free(line);
	if (reset == 1)
		ft_memset(buff, '\0', ft_strlen(buff));
	return (tmp);
}

static int	gnl(char **line, const int fd, int ret)
{
	static char	*buff_end = "";
	char		*buff;
	char		*tmp;
	int			i;

	buff_end = (ft_strcmp(buff_end, "") == 0) ? ft_strnew(0) : buff_end;
	if ((i = check_nl(buff_end)) >= 0)
	{
		*line = ft_strsub(buff_end, 0, i);
		ft_strcpy(buff_end, buff_end + i + 1);
		return (1);
	}
	*line = ft_strdup(buff_end);
	free(buff_end);
	if (!(buff = (char *)malloc(BUFF_SIZE + 1 * sizeof(char))))
		return (-1);
	ft_memset(buff, '\0', BUFF_SIZE + 1);
	while (ret > 0)
	{
		if ((ret = read(fd, buff, BUFF_SIZE)) == -1)
			return (-1);
		if ((i = check_nl(buff)) >= 0)
		{
			tmp = ft_strsub(buff, 0, i);
			*line = str_catfree(*line, tmp, 0);
			free(tmp);
			buff_end = ft_strsub(buff, i + 1, ft_strlen(buff));
			return (1);
		}
		*line = str_catfree(*line, buff, 1);
	}
	*line = str_catfree(buff_end, buff, 1);
	ft_memset(buff_end, '\0', ft_strlen(buff_end));
	return (ft_strlen(*line) == 0 ? 0 : 1);
}

int			get_next_line(const int fd, char **line)
{
	int		ret;

	ret = 1;
	if (!line || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	return (gnl(line, fd, ret));
}
