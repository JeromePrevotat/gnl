/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:46:09 by jprevota          #+#    #+#             */
/*   Updated: 2016/11/16 18:41:30 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strstr(char *src, char *tofind)
{
	int		j;
	int		i;
	char	*found;

	i = 0;
	j = 0;
	found = NULL;
	if (ft_strcmp(tofind, "") == 0)
		return (found = src);
	while (src[i] != '\0' && tofind[j] != '\0')
	{
		j = 0;
		found = NULL;
		while (src[i + j] == tofind[j] && src[i + j] != '\0'
				&& tofind[j] != '\0')
		{
			found = (src + i);
			j++;
		}
		i++;
	}
	return (found);
}
