/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onorridg <onorridg@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:23:31 by                   #+#    #+#             */
/*   Updated: 2021/11/30 23:24:22 by onorridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstdelone(t_list *lst)
{	
	t_list	*first;

	first = NULL;
	if (lst->previous && lst->next)
	{
		lst->previous->next = lst->next;
		lst->next->previous = lst->previous;
		first = ft_lstfist(lst);
	}
	else if (lst->previous && !lst->next)
	{
		lst->previous->next = NULL;
		first = ft_lstfist(lst);
	}
	else if (!lst->previous && lst->next)
	{
		lst->next->previous = NULL;
		first = lst->next;
	}
	else if (!lst->previous && !lst->next)
		first = NULL;
	free(lst);
	lst = NULL;
	return (first);
}
