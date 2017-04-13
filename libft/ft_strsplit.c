/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:08:54 by jprevota          #+#    #+#             */
/*   Updated: 2016/11/22 13:46:34 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	ft_word_count(char const *s, char c)
{
	size_t	i;
	int		word;

	word = 0;
	i = 0;
	while (i < ft_strlen(s))
	{
		while (s[i] == c && i < ft_strlen(s))
			i++;
		if (s[i] != c && i < ft_strlen(s))
			word++;
		while (s[i] != c && i < ft_strlen(s))
			i++;
		i++;
	}
	return (word);
}

static char	*ft_word_start(char const *s, char c)
{
	char	*str;
	char	*word_start;
	size_t	i;

	i = 0;
	str = ft_strdup(s);
	while (str[i] == c && i < ft_strlen(str))
		i++;
	word_start = str + i;
	return (word_start);
}

static int	ft_word_len(char c, char *word)
{
	int i;

	i = 0;
	while (word[i] != c && word[i] != '\0')
		i++;
	return (i);
}

static char	*ft_split(char *word, int len)
{
	char *str;

	str = (char *)malloc((len) * sizeof(char));
	str = ft_strncpy(str, word, len);
	str[len] = '\0';
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		wc;
	int		wl;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	wc = ft_word_count(s, c);
	tab = (char **)malloc((wc + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (i < wc)
	{
		s = ft_word_start(s, c);
		wl = ft_word_len(c, (char *)s);
		if (!(tab[i] = ft_split((char *)s, wl)))
			return (NULL);
		s = s + wl;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
