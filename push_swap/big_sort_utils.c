/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onorridg <onorridg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:13:04 by onorridg          #+#    #+#             */
/*   Updated: 2021/12/12 18:14:46 by onorridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_info	max(t_list *lst)
{
	t_info	max;
	int		max_int;

	max.index = 0;
	max.number = lst->number;
	max_int = 0;
	while (lst)
	{
		if (lst->number > max.number)
		{
			max.number = lst->number;
			max.index += max_int;
		}
		max_int += 1;
		lst = lst->next;
	}
	return (max);
}

t_info	min(t_list *b)
{
	t_info	min;
	int		min_int;

	min.index = 0;
	min.number = b->number;
	min_int = 0;
	while (b)
	{
		if (b->number < min.number)
		{
			min.number = b->number;
			min.index = min_int;
		}
		min_int += 1;
		b = b->next;
	}
	return (min);
}

int	find_nb_lst(t_list *a, int nb)
{	
	int	i;

	i = 0;
	while (a)
	{
		if (a->number == nb)
			return (i);
		i += 1;
		a = a->next;
	}
	return (-1);
}

int	find_nb_index(int *numbers, int nb, t_list *a)
{
	int	i;

	i = 0;
	while (1)
	{
		if (numbers[i] == nb)
			break ;
		i += 1;
	}
	while (find_nb_lst(a, numbers[i]) == -1)
		i += 1;
	return (i);
}
