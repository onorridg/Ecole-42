/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onorridg <onorridg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:03:13 by onorridg          #+#    #+#             */
/*   Updated: 2021/12/12 18:53:38 by onorridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(t_list *lst, int flag)
{
	int		swap_number;
	int		swap_index;

	if (lst && lst->next)
	{
		swap_number = lst->number;
		swap_index = lst->index;
		lst->number = lst->next->number;
		lst->next->number = swap_number;
		lst->index = lst->next->index;
		lst->next->index = swap_index;
		if (flag == 0)
			write(1, "sa\n", 3);
		else
			write(1, "sb\n", 3);
	}
}

void	ss(t_list *a, t_list *b)
{
	sa_sb(a, 0);
	sa_sb(b, 1);
}

void	pa_pb(t_list **a, t_list **b, int flag)
{
	if (b && flag == 0)
	{	
		if ((*a))
			ft_lstadd_front(a, ft_lstnew((*b)->number, (*b)->index, 0));
		else
			*a = ft_lstnew((*b)->number, (*b)->index, 0);
		*b = ft_lstdelone(ft_lstfist(*b));
		write(1, "pa\n", 3);
	}
	else if (a && flag == 1)
	{	
		if ((*b))
			ft_lstadd_front(b, ft_lstnew((*a)->number, (*a)->index, 0));
		else
			*b = ft_lstnew((*a)->number, (*a)->index, 0);
		*a = ft_lstdelone(ft_lstfist(*a));
		write(1, "pb\n", 3);
	}
}

void	ra_rb(t_list **lst, int flag)
{	
	ft_lstadd_back(lst, ft_lstnew((*lst)->number, (*lst)->index, 0));
	*lst = ft_lstdelone(*lst);
	if (flag == 0)
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	ra_rb(a, 0);
	ra_rb(b, 1);
}
