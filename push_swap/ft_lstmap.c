/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onorridg <onorridg@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:08:43 by                   #+#    #+#             */
/*   Updated: 2021/12/01 14:07:08 by onorridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstmap(int *numbers, int ac)
{
	t_list	*node;
	t_list	*first;
	t_list	*lst;
	int		i;

	i = 0;
	if (0 < ac)
	{
		first = ft_lstnew(numbers[i++], 0, 0);
		lst = first;
		while (i < ac)
		{
			node = ft_lstnew(numbers[i++], 0, lst);
			if (!node)
			{
				ft_lstclear(&first);
				return (0);
			}
			lst = node;
			ft_lstadd_back(&first, node);
		}
	}
	else
		return (NULL);
	return (first);
}
