/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:34:12 by jprevota          #+#    #+#             */
/*   Updated: 2016/11/16 16:24:13 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*mem1;
	unsigned char	*mem2;

	i = 0;
	mem1 = (unsigned char *)s1;
	mem2 = (unsigned char *)s2;
	while (n > 0 && *mem1 == *mem2)
	{
		mem1++;
		mem2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*mem1 - *mem2);
}
