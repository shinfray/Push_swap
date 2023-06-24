/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:50:56 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/25 01:44:44 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_sort(t_dllist *stack_a, t_dllist *stack_b);
void		ft_sort_list_up_to_3(t_dllist *stack_a);
static void	ft_roll_stack_a(t_dllist *stack_a);

void	ft_sort(t_dllist *stack_a, t_dllist *stack_b)
{
	t_choice		s_choice;
	unsigned int	i;

	if (ft_stack_is_sorted(stack_a) == true)
		return ;
	while (stack_a->total_nodes > 3)
	{
		if (ft_dllist_is_empty(stack_b) == false)
		{	
			ft_choose_moves_to_b(stack_a, stack_b, &s_choice);
			s_choice.fun(stack_a, stack_b, s_choice.from, s_choice.to);
		}
		ft_pb(stack_a, stack_b);
	}
	if (ft_stack_is_sorted(stack_a) == false)
		ft_sort_list_up_to_3(stack_a);
	while (ft_dllist_is_empty(stack_b) == false)
	{
		i = ft_get_desired_index_to_a(stack_a, ft_dllist_first(stack_b)->val);
		ft_do_ra_or_rra(stack_a, i);
		ft_pa(stack_a, stack_b);
	}
	ft_roll_stack_a(stack_a);
}

void	ft_sort_list_up_to_3(t_dllist *stack_a)
{
	const int	min_value = ft_get_min_value(stack_a);
	const int	max_value = ft_get_max_value(stack_a);

	if (ft_dllist_first(stack_a)->val == max_value)
		ft_ra(stack_a);
	if (stack_a->total_nodes != 3 || ft_stack_is_sorted(stack_a) == true)
		return ;
	if (ft_dllist_next(ft_dllist_first(stack_a))->val == max_value)
		ft_rra(stack_a);
	if (ft_dllist_next(ft_dllist_first(stack_a))->val == min_value)
		ft_sa(stack_a);
}

static void	ft_roll_stack_a(t_dllist *stack_a)
{
	int				min_value;
	unsigned int	index;
	
	if (ft_stack_is_sorted(stack_a) == true)
		return ;
	min_value = ft_get_min_value(stack_a);
	index = ft_get_value_index(stack_a, min_value);
	ft_do_ra_or_rra(stack_a, index);
}
