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

static int	fill_buffer(int fd, char **buff, size_t *mem_tmp)
{
	char	*new_buff;
	int		ret;

	while (ft_strlen(*buff) + BUFF_SIZE + 1 > *mem_tmp)
		*mem_tmp = *mem_tmp + 256;
	if (!(new_buff = (char *)malloc(*mem_tmp * sizeof(char))))
		return (-1);
	ft_memset(new_buff, '\0', *mem_tmp);
	ft_strcpy(new_buff, *buff);
	free(*buff);
	*buff = new_buff;
	ret = read(fd, *buff + ft_strlen(*buff), BUFF_SIZE);
	return (ret);
}

static int	gnl(char **line, const int fd, int ret)
{
	static char	*buff_end = "";
	char		*buff;
	char		*tmp;
	int			i;
	size_t 		mem_tmp;

	mem_tmp = 256;
	buff_end = (ft_strcmp(buff_end, "") == 0) ? ft_strnew(0) : buff_end;
	if ((i = check_nl(buff_end)) >= 0)
	{
		*line = ft_strsub(buff_end, 0, i);
		ft_strcpy(buff_end, buff_end + i + 1);
		return (1);
	}
	if (!(buff = (char *)malloc(mem_tmp * sizeof(char))))
		return (-1);
	ft_memset(buff, '\0', mem_tmp);
	while (ret > 0 && (i = check_nl(buff)) < 0)
		if ((ret = fill_buffer(fd, &buff, &mem_tmp)) == -1)
			return (-1);
	if ((i = check_nl(buff)) >= 0)
	{
		*line = ft_strjoin(buff_end, (tmp = ft_strsub(buff, 0, i)));
		ft_strdel(&buff_end);
		ft_strdel(&tmp);
		buff_end = ft_strsub(buff, i + 1, ft_strlen(buff));
		return (1);
	}
	*line = ft_strjoin(buff_end, buff);
	ft_strcpy(buff_end, buff_end + i + 1);
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
