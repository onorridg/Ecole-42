/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onorridg <onorridg@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:03:21 by onorridg          #+#    #+#             */
/*   Updated: 2022/12/19 22:19:32 by onorridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ret(t_list **a, t_list **b, int *numbers)
{	
	t_info	max_a;
	t_info	min_a;

	while ((*b))
	{
		max_a = max(*a);
		min_a = min(*a);
		if (max_a.number < (*b)->number)
			ret_one(a, b, max_a);
		else if (min_a.number > (*b)->number)
			ret_two(a, b, min_a);
		else if (min_a.number < (*b)->number && max_a.number > (*b)->number)
			ret_three(a, b, numbers);
	}
}

static void	help_sort(t_list **a, t_list **b, int len, int *numbers)
{	
	int	y;
	int	i;
	int	len_10;

	y = 2;
	len_10 = len / 10;
	while (y < 10)
	{
		i = 0;
		while (i < len)
		{
			while ((*a)->number >= numbers[len_10 * (y - 1)]
				&& (*a)->number < numbers[len_10 * y])
				pa_pb(a, b, 1);
			if (ft_lstsize(*b) >= len_10 * y)
				break ;
			ra_rb(a, 0);
			i++;
		}
		y++;
	}
}

void	get_first_nb(t_list **a)
{	
	t_info	min_a;

	min_a = min(*a);
	while (min_a.number != (*a)->number)
	{
		if (min_a.index < ft_lstsize(*a) / 2)
			ra_rb(a, 0);
		else
			rra_rrb(a, 0);
	}
}

static void	sort(t_list **a, t_list *b, int len, int *numbers)
{	
	int		i;

	i = 0;
	while (i < len)
	{
		while ((*a)->number < numbers[len / 10])
			pa_pb(a, &b, 1);
		if (ft_lstsize(b) >= len / 10)
			break ;
		ra_rb(a, 0);
		i++;
	}
	help_sort(a, &b, len, numbers);
	while ((*a) && ft_lstsize(*a) > 1)
		pa_pb(a, &b, 1);
	ret(a, &b, numbers);
	get_first_nb(a);
}

void	big_sort(int *numbers, int len)
{
	t_list	*a;

	a = ft_lstmap(numbers, len);
	ft_sort(numbers, len);
	if (!a)
		ft_exit(numbers);
	if (ft_chek_sort(numbers, a, len) != 0)
		sort(&a, NULL, len, numbers);
	ft_lstclear(&a);
}
