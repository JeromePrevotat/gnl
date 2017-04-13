/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 19:52:29 by jprevota          #+#    #+#             */
/*   Updated: 2016/11/16 18:41:52 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	tf;
	int		i;

	i = ft_strlen(s);
	tf = c;
	while (i >= 0)
	{
		if (*(s + i) == tf)
			return (char *)(s + i);
		i--;
	}
	return (NULL);
}
