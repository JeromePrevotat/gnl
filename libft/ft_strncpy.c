/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 13:43:44 by jprevota          #+#    #+#             */
/*   Updated: 2016/11/16 17:04:01 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char *)src;
	while (i < n)
	{
		if (*(s + i))
			*(dest + i) = *(s + i);
		else
		{
			while (i < n)
			{
				*(dest + i) = '\0';
				i++;
			}
		}
		i++;
	}
	return (dest);
}
