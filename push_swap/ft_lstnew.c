/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onorridg <onorridg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:29:58 by                   #+#    #+#             */
/*   Updated: 2021/12/12 18:52:11 by onorridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int number, int index, t_list *previous)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new)
	{	
		new->number = number;
		new->index = index;
		new->next = NULL;
		new->previous = previous;
	}
	return (new);
}
