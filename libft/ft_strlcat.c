/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:10:32 by jprevota          #+#    #+#             */
/*   Updated: 2016/11/23 14:00:21 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char		*s;
	size_t		dlen;
	size_t		slen;
	size_t		i;
	int			j;

	j = 0;
	i = ft_strlen(dest);
	s = (char *)src;
	dlen = ft_strlen(dest);
	slen = ft_strlen(s);
	if (size < dlen + 1)
		return (slen + size);
	if (size > dlen + 1)
	{
		while (i < size - 1)
		{
			*(dest + i) = *(s + j);
			j++;
			i++;
		}
		*(dest + i) = '\0';
	}
	return (dlen + slen);
}
