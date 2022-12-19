/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onorridg <onorridg@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:30:05 by                   #+#    #+#             */
/*   Updated: 2021/12/01 14:00:20 by onorridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*save;

	if (lst)
	{
		i = 1;
		save = lst;
		if (lst->next)
		{
			while (save->next)
			{
				save = save->next;
				i++;
			}
		}
		return (i);
	}
	return (0);
}
