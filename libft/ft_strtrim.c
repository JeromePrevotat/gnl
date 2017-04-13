/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:02:27 by jprevota          #+#    #+#             */
/*   Updated: 2016/11/19 19:10:29 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static char		*ft_strrev(char *str)
{
	char	tmp;
	int		len;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
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

char			*ft_strtrim(char const *s)
{
	char	*r;
	char	*str;
	int		start;
	int		end;

	if (!s)
		return (NULL);
	str = ft_strdup(s);
	if (!str)
		return (NULL);
	start = 0;
	while (str[start] == ' ' || str[start] == '\t' || str[start] == '\n')
		start++;
	str = ft_strrev(str);
	end = 0;
	while (str[end] == ' ' || str[end] == '\t' || str[end] == '\n')
		end++;
	str = ft_strrev(str);
	str[ft_strlen(str) - end] = '\0';
	str = (str + start);
	r = ft_strdup(str);
	if (!r)
		return (NULL);
	return (r);
}
