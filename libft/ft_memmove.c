/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:19:14 by jprevota          #+#    #+#             */
/*   Updated: 2016/11/20 15:56:46 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;
	int				len;

	i = 0;
	len = n;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (s < d)
	{
		while (len-- > 0)
			*(d + len) = *(s + len);
	}
	else
	{
		while (i < n)
		{
			*(d + i) = *(s + i);
			i++;
		}
	}
	return (dest);
}
