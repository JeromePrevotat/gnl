/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:46:29 by jprevota          #+#    #+#             */
/*   Updated: 2016/11/14 17:30:32 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memalloc(size_t size)
{
	size_t			i;
	unsigned char	*mem;

	mem = (unsigned char *)malloc(size * sizeof(unsigned char));
	if (!mem)
		return (NULL);
	i = 0;
	while (i <= size)
	{
		mem[i] = '\0';
		i++;
	}
	return (mem);
}
