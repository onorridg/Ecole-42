/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onorridg <onorridg@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:33:37 by onorridg          #+#    #+#             */
/*   Updated: 2022/12/19 22:22:09 by onorridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ret_one(t_list **a, t_list **b, t_info max_a)
{
	if (max_a.index < ft_lstsize(*a) / 2)
	{
		while ((*a)->number != max_a.number)
			ra_rb(a, 0);
	}
	else
	{
		while ((*a)->number != max_a.number)
			rra_rrb(a, 0);
	}
	ra_rb(a, 0);
	pa_pb(a, b, 0);
}

void	ret_two(t_list **a, t_list **b, t_info min_a)
{
	if (min_a.index < ft_lstsize(*a) / 2)
	{
		while ((*a)->number != min_a.number)
			ra_rb(a, 0);
	}
	else
	{
		while ((*a)->number != min_a.number)
			rra_rrb(a, 0);
	}
	pa_pb(a, b, 0);
}

void	ret_three(t_list **a, t_list **b, int *numbers)
{
	int		index;

	index = find_nb_index(numbers, (*b)->number, *a);
	if ((*b)->number > (*a)->number)
	{
		while ((*a)->number != numbers[index])
			ra_rb(a, 0);
	}
	else
	{
		while ((*a)->number != numbers[index])
			rra_rrb(a, 0);
	}	
	pa_pb(a, b, 0);
}
