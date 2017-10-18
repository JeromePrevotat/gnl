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

static int	find_nl(char *str)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

static char	*set_buff_end(char *buff_end)
{
	if (ft_strchr(buff_end, '\n'))
	{
		ft_strcpy(buff_end, buff_end + find_nl(buff_end) + 1);
		return (buff_end);
	}
	if (ft_strlen(buff_end) > 0)
	{
		ft_memset(buff_end, '\0', ft_strlen(buff_end));
		return (buff_end);
	}
	return (NULL);
}

int			get_next_line(const int fd, char **line)
{
	static char	*buff_end = "";
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || BUFF_SIZE < 1 || !line || read(fd, buff, 0) < 0)
		return (-1);
	buff_end = (ft_strcmp("", buff_end) == 0) ? ft_strnew(0) : buff_end;
	while (ft_strchr(buff_end, '\n') == NULL
		&& (ret = read(fd, buff, BUFF_SIZE) > 0))
	{
		buff[ret] = '\0';
		printf("BUFFEND : >%s<\nRET : %d\n", buff, ret);
		tmp = buff_end;
		buff_end = ft_strjoin(tmp, buff);
		//free(tmp);
	}
	*line = ft_strsub(buff_end, 0, find_nl(buff_end));
	if (set_buff_end(buff_end) == NULL)
		return (0);
	return (1);
}
