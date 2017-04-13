/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 16:49:39 by jprevota          #+#    #+#             */
/*   Updated: 2016/11/22 13:57:57 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*tmp;

	if (!lst || !(*f))
		return ;
	tmp = lst;
	while (tmp->next != NULL)
	{
		(*f)(tmp);
		tmp = tmp->next;
	}
	(*f)(tmp);
}
