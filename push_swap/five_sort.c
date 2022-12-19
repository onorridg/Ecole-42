/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onorridg <onorridg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:57:00 by onorridg          #+#    #+#             */
/*   Updated: 2021/12/13 11:43:10 by onorridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_five(int *num, t_list **a, t_list *b)
{	
	while (ft_lstsize(b) != 2)
	{
		if ((*a)->number == num[0] || (*a)->number == num[1])
			pa_pb(a, &b, 1);
		else if (ft_lstlast(*a)->number == num[0]
			|| ft_lstlast(*a)->number == num[1])
		{	
			rra_rrb(a, 0);
			pa_pb(a, &b, 1);
		}
		else
			ra_rb(a, 0);
	}
	if (b->number < b->next->number)
		sa_sb(b, 1);
	ft_sort_three(a);
	pa_pb(a, &b, 0);
	pa_pb(a, &b, 0);
}

void	ft_sort_four(int *num, t_list **a, t_list *b)
{
	while (ft_lstsize(b) != 1)
	{
		if ((*a)->number == num[0])
			pa_pb(a, &b, 1);
		else if (ft_lstlast(*a)->number == num[0])
		{	
			rra_rrb(a, 0);
			pa_pb(a, &b, 1);
		}
		else
			ra_rb(a, 0);
	}
	ft_sort_three(a);
	pa_pb(a, &b, 0);
}

void	ft_sort_three(t_list **a)
{	
	if ((*a)->number > (*a)->next->next->number)
	{	
		if ((*a)->number < (*a)->next->number)
			rra_rrb(a, 0);
		else
		{
			if ((*a)->number < (*a)->next->number)
				sa_sb(*a, 0);
			ra_rb(a, 0);
		}
	}
	else if ((*a)->next->number > (*a)->next->next->number)
		rra_rrb(a, 0);
	if ((*a)->number > (*a)->next->number)
		sa_sb(*a, 0);
}

void	ft_five(int *numbers, int len)
{
	t_list	*a;

	a = ft_lstmap(numbers, len);
	if (!a)
		ft_exit(numbers);
	ft_sort(numbers, len);
	if (ft_chek_sort(numbers, a, len) != 0)
	{	
		if (len == 2 && a->number > a->next->number)
			sa_sb(a, 0);
		else if (len == 3)
			ft_sort_three(&a);
		else if (len == 4)
			ft_sort_four(numbers, &a, NULL);
		else if (len == 5)
			ft_sort_five(numbers, &a, NULL);
	}
	ft_lstclear(&a);
}
