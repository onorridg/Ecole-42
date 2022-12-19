/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onorridg <onorridg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:28:23 by onorridg          #+#    #+#             */
/*   Updated: 2021/12/12 18:54:02 by onorridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_rrb(t_list **lst, int flag)
{
	ft_lstadd_front(lst, ft_lstnew(ft_lstlast((*lst))->number,
			(*lst)->index, 0));
	*lst = ft_lstdelone(ft_lstlast(*lst));
	if (flag == 0)
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	rra_rrb(a, 0);
	rra_rrb(b, 1);
}

int	chek_sort(int *numbers, t_list *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		if (lst->number != numbers[i++])
			return (1);
		lst = lst->previous;
	}
	return (0);
}
