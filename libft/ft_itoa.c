/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:43:04 by jprevota          #+#    #+#             */
/*   Updated: 2016/11/22 13:57:44 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	ft_nb_len(int n)
{
	unsigned int	nb;
	int				nb_len;

	nb = n;
	nb_len = 1;
	if (n < 0)
	{
		nb = -n;
		nb_len++;
	}
	while (nb / 10 > 0)
	{
		nb_len++;
		nb = nb / 10;
	}
	return (nb_len);
}

char		*ft_itoa(int n)
{
	char			*str;
	int				nb_len;
	unsigned int	nb;

	nb_len = ft_nb_len(n);
	nb = n;
	if (n < 0)
		nb = -n;
	str = (char *)malloc((nb_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[nb_len] = '\0';
	nb_len--;
	while (nb_len >= 0)
	{
		str[nb_len] = nb % 10 + '0';
		nb = nb / 10;
		nb_len--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
