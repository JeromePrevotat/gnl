/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:29:43 by jprevota          #+#    #+#             */
/*   Updated: 2016/11/15 16:18:37 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	ft_isspace(char c)
{
	if (c == '\n' || c == '\v' || c == '\n' || c == '\r' || c == '\f'
			|| c == '\t' || c == ' ')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int i;
	int nb;
	int sign;

	nb = 0;
	sign = 1;
	i = 0;
	while ((ft_isspace(str[i]) && (str[i] != '\0')))
		i++;
	if ((str[i] == '-') && (str[i + 1] >= '0' && str[i + 1] <= '9'))
	{
		i++;
		sign = -1;
	}
	if ((str[i] == '+') && (str[i + 1] >= '0' && str[i + 1] <= '9'))
	{
		i++;
		sign = 1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb * sign);
}
