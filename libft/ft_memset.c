/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:59:48 by jprevota          #+#    #+#             */
/*   Updated: 2017/05/12 10:09:33 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*s_set;

	s_set = (unsigned char *)s;
	while (n)
	{
		*s_set = (unsigned char)c;
		s_set++;
		n--;
	}
	return (s);
}
