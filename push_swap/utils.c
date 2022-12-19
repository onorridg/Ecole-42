/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onorridg <onorridg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:49:43 by onorridg          #+#    #+#             */
/*   Updated: 2021/12/14 13:37:00 by onorridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(int *numbers)
{
	free(numbers);
	write(1, "Error\n", 6);
	exit(1);
}

int	ft_int_len(int nb)
{	
	int	len;

	len = 0;
	while (nb / 10 > 0)
	{
		nb /= 10;
		len += 1;
	}
	return (len);
}

int	ft_chek_sort(int *numbers, t_list *lst, int len)
{
	int		i;

	i = 0;
	while (lst)
	{
		if (lst->number != numbers[i])
			return (1);
		lst = lst->next;
		i++;
	}
	if (i != len)
		return (1);
	return (0);
}

void	ft_sort(int *arr, int ac)
{
	int	i;
	int	y;
	int	swap;

	i = 0;
	while (i < ac)
	{	
		y = 0;
		while (y < ac - 1)
		{	
			if (arr[y] > arr[y + 1] && y + 1 < ac)
			{
				swap = arr[y];
				arr[y] = arr[y + 1];
				arr[y + 1] = swap;
			}
			y++;
		}
		i++;
	}
}

void	ft_double(int *arr, int ac)
{
	int	i;
	int	y;

	i = 0;
	while (i < ac)
	{	
		y = 0;
		while (y < ac)
		{	
			if (arr[i] == arr[y] && i != y)
			{
				write(1, "Error\n", 6);
				free(arr);
				exit(1);
			}
			y++;
		}
		i++;
	}	
}
