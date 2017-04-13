/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_str_wc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:24:26 by jprevota          #+#    #+#             */
/*   Updated: 2016/11/25 15:27:49 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int		ft_bonus_str_wc(char const *str, char c)
{
	int		wc;
	size_t	i;

	wc = 0;
	i = 0;
	while (i < ft_strlen(str))
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i] != c && i < ft_strlen(str))
			wc++;
		while (str[i] != c && i < ft_strlen(str))
			i++;
		i++;
	}
	return (wc);
}
