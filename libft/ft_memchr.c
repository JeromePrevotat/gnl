/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:27:35 by jprevota          #+#    #+#             */
/*   Updated: 2016/11/13 20:24:41 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*search;
	unsigned char	*found;
	size_t			i;

	i = 0;
	found = NULL;
	search = (unsigned char *)s;
	while (i < n)
	{
		if (search[i] == (unsigned char)c)
		{
			found = (search + i);
			return (found);
		}
		i++;
	}
	return (found);
}
