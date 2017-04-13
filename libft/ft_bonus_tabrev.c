/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_tabrev.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:37:33 by jprevota          #+#    #+#             */
/*   Updated: 2016/11/26 17:24:12 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	*ft_bonus_tabrev(int *tab, size_t size)
{
	size_t	i;
	int		tmp;

	size = size - 1;
	i = 0;
	while (i <= size / 2)
	{
		tmp = tab[i];
		tab[i] = tab[size - i];
		tab[size - i] = tmp;
		i++;
	}
	return (tab);
}
