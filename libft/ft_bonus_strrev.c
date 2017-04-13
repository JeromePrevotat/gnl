/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_strrev.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:22:08 by jprevota          #+#    #+#             */
/*   Updated: 2016/11/23 14:22:13 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_bonus_strrev(char *str)
{
	int		i;
	int		len;
	char	tmp;

	if (!str)
		return (NULL);
	if (ft_strcmp(str, "") == 0)
		return (str);
	i = 0;
	len = ft_strlen(str) - 1;
	while (i <= len / 2)
	{
		tmp = str[i];
		str[i] = str[len - i];
		str[len - i] = tmp;
		i++;
	}
	return (str);
}
