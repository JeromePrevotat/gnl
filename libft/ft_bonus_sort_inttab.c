/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_sort_inttab.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:38:43 by jprevota          #+#    #+#             */
/*   Updated: 2016/11/25 15:48:13 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	*ft_bonus_sort_inttab(int *tab, size_t tsize)
{
	size_t	i;
	size_t	j;
	int		tmp;

	i = 0;
	j = 0;
	while (i < tsize)
	{
		j = i + 1;
		while (j < tsize)
		{
			if (tab[j] < tab[i])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}
