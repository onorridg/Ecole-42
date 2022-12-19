/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onorridg <onorridg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:42:54 by onorridg          #+#    #+#             */
/*   Updated: 2021/12/13 12:43:09 by onorridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int		main(int ac, char **av);
void	ft_push_swap(int ac, char **av);
void	ft_double(int *arr, int ac);
void	ft_sort(int *arr, int ac);
int		ft_int_len(int nb);
void	ft_exit(int *numbers);

typedef struct s_list
{
	int				number;
	int				index;
	struct s_list	*next;
	struct s_list	*previous;
}	t_list;

typedef struct s_info
{
	int	number;
	int	index;
}	t_info;

t_list	*ft_lstnew(int content, int index, t_list *previous);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);
t_list	*ft_lstfist(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstmap(int *numbers, int ac);
int		ft_chek_sort(int *numbers, t_list *lst, int len);

void	sa_sb(t_list *lst, int flag);
void	ss(t_list *a, t_list *b);
void	pa_pb(t_list **a, t_list **b, int flag);
void	ra_rb(t_list **lst, int flag);
void	rr(t_list **a, t_list **b);
void	rra_rrb(t_list **lst, int flag);
void	rrr(t_list **a, t_list **b);

int		chek_sort(int *numbers, t_list *lst);
void	ft_five(int *numbers, int len);
void	ft_sort_three(t_list **a);
void	big_sort(int *numbers, int len);
t_info	max(t_list *lst);
t_info	min(t_list *b);
int		find_nb_lst(t_list *a, int nb);
int		find_nb_index(int *numbers, int nb, t_list *a);
void	get_first_nb(t_list **a);
void	ret_one(t_list **a, t_list **b, t_info max_a);
void	ret_two(t_list **a, t_list **b, t_info min_a);
void	ret_three(t_list **a, t_list **b, int *numbers);

#endif