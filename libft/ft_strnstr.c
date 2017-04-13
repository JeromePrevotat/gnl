/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 19:38:45 by jprevota          #+#    #+#             */
/*   Updated: 2016/11/16 18:57:30 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strnstr(const char *src, const char *tf, size_t len)
{
	int		i;
	int		j;
	char	*found;

	i = 0;
	j = 0;
	found = NULL;
	if (ft_strcmp(tf, "") == 0)
		return (found = (char*)(src));
	while (src[i] != '\0' && tf[j] != '\0' && len > 0)
	{
		j = 0;
		found = NULL;
		while (src[i + j] == tf[j] && src[i + j] != '\0' && (len - j) > 0
				&& tf[j] != '\0')
		{
			found = (char *)(src + i);
			j++;
		}
		i++;
		len--;
	}
	return (found);
}
