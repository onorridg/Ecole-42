/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onorridg <onorridg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:42:12 by onorridg          #+#    #+#             */
/*   Updated: 2021/12/15 14:55:58 by onorridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_find_space(char *string)
{	
	int	i;
	int	numbers;

	i = 0;
	numbers = 0;
	while (string[i])
	{	
		while (string[i] == ' ')
			i++;
		if ((string[i] >= '0' && string[i] <= '9') || string[i] == '-')
		{
			while ((string[i] >= '0' && string[i] <= '9') || string[i] == '-')
				i++;
			numbers++;
		}
		if (string[i] != '\0' && string[i] != ' ')
			ft_exit(0);
	}
	return (numbers);
}

static void	ft_atoi_spaces(char *numbers, int *arr, long long nb)
{	
	int			i;
	int			y;
	int			sign;

	i = 0;
	y = 0;
	while (numbers[i])
	{
		nb = 0;
		sign = 1;
		while (numbers[i] == ' ')
			i++;
		if (numbers[i] == '-')
		{
			sign *= -1;
			i++;
		}
		while (numbers[i] >= '0' && numbers[i] <= '9' && numbers[i])
			nb = nb * 10 + (numbers[i++] - '0');
		if ((numbers[i] != '\0' && numbers[i] != ' ')
			|| ((nb * sign) > INT_MAX || (nb * sign) < INT_MIN
				|| (sign == -1 && nb == 0)))
			ft_exit(arr);
		arr[y++] = nb * sign;
	}
}

static void	ft_atoi(char **numbers, int len, int *arr)
{	
	int			y;
	int			i;
	long long	nb;
	int			sign;

	y = 1;
	while (y <= len)
	{
		i = 0;
		nb = 0;
		sign = 1;
		if (numbers[y][i] == '-')
		{
			sign *= -1;
			i++;
		}
		while (numbers[y][i] >= '0' && numbers[y][i] <= '9')
			nb = nb * 10 + (numbers[y][i++] - '0');
		if (numbers[y][i] != '\0' || ((nb * sign) > INT_MAX
			|| (nb * sign) < INT_MIN) || (sign == -1 && nb == 0))
			ft_exit(arr);
		arr[y - 1] = nb * sign;
		y++;
	}
}

static int	*ft_check_argv(int *ac, char **av)
{
	int	*arr;
	int	space;

	space = 0;
	if (*ac == 1)
		space = ft_find_space(av[1]);
	if (space != 0)
		*ac = space;
	arr = (int *)malloc(sizeof(int) * *ac);
	if (!arr)
	{	
		write(1, "Error\n", 6);
		exit(1);
	}
	if (space == 0)
		ft_atoi(av, *ac, arr);
	else
		ft_atoi_spaces(av[1], arr, 0);
	ft_double(arr, *ac);
	return (arr);
}

void	ft_push_swap(int ac, char **av)
{
	int	*arr;

	arr = ft_check_argv(&ac, av);
	if (ac <= 5)
		ft_five(arr, ac);
	else
		big_sort(arr, ac);
	free(arr);
}
