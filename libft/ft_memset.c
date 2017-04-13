/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:59:48 by jprevota          #+#    #+#             */
/*   Updated: 2016/11/11 17:45:42 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*s_set;
	size_t			i;

	i = 0;
	s_set = (unsigned char *)s;
	while (i < n)
	{
		*s_set = (unsigned char)c;
		s_set++;
		i++;
	}
	return (s);
}
