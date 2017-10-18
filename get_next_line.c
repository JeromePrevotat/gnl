/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:44:38 by jprevota          #+#    #+#             */
/*   Updated: 2017/04/20 15:56:30 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	find_nl(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

static char		*str_memcat(char *s1, char *s2)
{
	char	*tmp;
	size_t	size1;
	size_t	size2;
	size_t	size;

	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	size = size1 + size2 + 1;
	if (!(tmp = (char *)malloc(size * sizeof(char))))
		return (NULL);
	ft_memset(tmp, '\0', size);
	ft_memcpy(tmp, s1, size1);
	ft_memcpy(tmp + size1, s2, size2);
	return (tmp);
}

static char		*set_buff_end(char *buff_end)
{
	if (ft_strchr(buff_end, '\n'))
	{
		ft_strcpy(buff_end, ft_strchr(buff_end, '\n') + 1);
		return (buff_end);
	}
	if (find_nl(buff_end) > 0)
	{
		buff_end[0] = '\0';
		return (buff_end);
	}
	return (NULL);
}

int				get_next_line(int const fd, char **line)
{
	static char	*buff_end[1024];
	char		buff[BUFF_SIZE + 1];
	int			ret;
	char		*tmp;

	if (fd < 0 || BUFF_SIZE < 1 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (!(buff_end[fd]) && (buff_end[fd] = ft_strnew(0)) == NULL)
		return (-1);
	while (!(ft_strchr(buff_end[fd], '\n'))
		&& (ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = buff_end[fd];
		buff_end[fd] = str_memcat(tmp, buff);
		free(tmp);
	}
	*line = ft_strsub(buff_end[fd], 0, find_nl(buff_end[fd]));
	return ((set_buff_end(buff_end[fd]) == NULL)) ? 0 : 1;
}
