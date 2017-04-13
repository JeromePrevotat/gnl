/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_lstadd_end.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:21:06 by jprevota          #+#    #+#             */
/*   Updated: 2016/11/23 14:21:11 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_bonus_lstadd_end(t_list **alst, t_list *new_list)
{
	if (!alst || !new_list)
		return ;
	while ((*alst)->next != NULL)
		*alst = (*alst)->next;
	(*alst)->next = new_list;
}
