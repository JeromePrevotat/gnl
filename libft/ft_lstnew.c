/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 19:08:36 by jprevota          #+#    #+#             */
/*   Updated: 2016/11/22 13:56:52 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list			*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	if (content == NULL || content_size == 0)
	{
		list->content_size = 0;
		list->content = NULL;
	}
	else
	{
		list->content_size = content_size;
		list->content = ft_memalloc(content_size);
		if (!list->content)
			return (NULL);
		list->content = ft_memcpy(list->content, content, content_size);
	}
	list->next = NULL;
	return (list);
}
