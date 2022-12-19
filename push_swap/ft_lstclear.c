/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onorridg <onorridg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:37:24 by                   #+#    #+#             */
/*   Updated: 2021/11/25 16:01:50 by onorridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*next;

	if (lst)
	{
		while (*lst)
		{
			next = (*lst)->next;
			ft_lstdelone(*lst);
			(*lst) = next;
		}
		lst = NULL;
	}
}
