/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onorridg <onorridg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:27:59 by onorridg          #+#    #+#             */
/*   Updated: 2021/12/14 14:01:08 by onorridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	if (ac > 1)
		ft_push_swap(ac - 1, av);
	else
		write(1, "Where's the money(numbers), Lebowski ???\n", 41);
	return (0);
}
