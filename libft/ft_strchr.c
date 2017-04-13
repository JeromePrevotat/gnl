/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:48:39 by jprevota          #+#    #+#             */
/*   Updated: 2016/11/23 17:20:03 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strchr(char *str, char c)
{
	char	*occ;
	size_t	s;

	s = 0;
	occ = NULL;
	while (s <= ft_strlen(str))
	{
		if (str[s] == c)
		{
			occ = (str + s);
			return (occ);
		}
		s++;
	}
	return (occ);
}
