/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_lstadd_n.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:21:31 by jprevota          #+#    #+#             */
/*   Updated: 2016/11/23 14:21:35 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_bonus_lstadd_n(t_list **alst, t_list *new_list, int n)
{
	if (!alst || !new_list)
		return ;
	if (n <= 0)
	{
		n = -n;
		ft_lstadd(alst, new_list);
	}
	while (n != 0)
	{
		*alst = (*alst)->next;
		n--;
	}
	new_list->next = (*alst)->next;
	(*alst)->next = new_list;
}
