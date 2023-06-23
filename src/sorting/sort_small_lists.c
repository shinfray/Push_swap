/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_lists.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:50:56 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/23 14:00:39 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_list_up_to_3(t_dllist *stack_a);
void	ft_sort_list_up_to_5(t_dllist *stack_a, t_dllist *stack_b);

void	ft_sort_list_up_to_3(t_dllist *stack_a)
{
	int	a;
	int	b;
	int	c;

	a = ft_dllist_first(stack_a)->val;
	b = ft_dllist_next(ft_dllist_first(stack_a))->val;
	c = ft_dllist_last(stack_a)->val;
	if (stack_a->total_nodes == 2)
		ft_sa(stack_a, NULL);
	else if (a > b && b < c && c < a)
		ft_ra(stack_a, NULL);
	else if (a < b && b > c && c < a)
		ft_rra(stack_a, NULL);
	else
	{
		ft_sa(stack_a, NULL);
		if (ft_stack_is_sorted(stack_a) == true)
			return ;
		a = ft_dllist_first(stack_a)->val;
		b = ft_dllist_next(ft_dllist_first(stack_a))->val;
		if (a > b)
			ft_ra(stack_a, NULL);
		else
			ft_rra(stack_a, NULL);
	}
}

// void	ft_sort_list_up_to_5(t_dllist *stack_a, t_dllist *stack_b)
// {
// 	while (stack_a->total_nodes > 3)
// 		ft_pb(stack_a, stack_b);
// 	if (ft_stack_is_sorted(stack_a) == false)
// 		ft_sort_list_up_to_3(stack_a);
// 	while (ft_dllist_is_empty(stack_b) == false)
// 	{
// 		if (ft_dllist_first(stack_b)->val < ft_dllist_first(stack_a)->val)
// 			ft_pa(stack_a, stack_b);
// 		else if (ft_dllist_first(stack_b)->val > ft_dllist_last(stack_a)->val)
// 		{
// 			ft_pa(stack_a, stack_b);
// 			ft_ra(stack_a, stack_b);
// 		}
// 		else
// 		{
// 			while (ft_dllist_first(stack_b)->val \
// 					> ft_dllist_first(stack_a)->val)
// 				ft_ra(stack_a, stack_b);
// 			ft_pa(stack_a, stack_b);
// 			while (ft_stack_is_sorted(stack_a) == false)
// 				ft_rra(stack_a, stack_b);
// 		}
// 	}
// }

static int	ft_get_min(t_dllist *stack_a)
{
	t_dllist_node	*current_node;
	int	min;

	min = 0;
	current_node = ft_dllist_first(stack_a);
	while (current_node != stack_a->sentinel_node)
	{
		if (min > current_node->val)
			min = current_node->val;
		current_node = ft_dllist_next(current_node);
	}
	return (min);
}

static int	ft_get_max(t_dllist *stack_a)
{
	t_dllist_node	*current_node;
	int	max;

	max = 0;
	current_node = ft_dllist_first(stack_a);
	while (current_node != stack_a->sentinel_node)
	{
		if (max > current_node->val)
			max = current_node->val;
		current_node = ft_dllist_next(current_node);
	}
	return (max);
}

void	ft_sort_list_up_to_5(t_dllist *stack_a, t_dllist *stack_b)
{
	const int	min = ft_get_min(stack_a);
	const int	max = ft_get_max(stack_a);

	while (stack_a->total_nodes > 3)
		ft_pb(stack_a, stack_b);
	if (ft_stack_is_sorted(stack_a) == false)
		ft_sort_list_up_to_3(stack_a);
	if (ft_dllist_is_empty(stack_b) == false)
	{
		if (ft_dllist_first(stack_b)->val < ft_dllist_first(stack_a)->val)
			ft_pa(stack_a, stack_b);
		else if (ft_dllist_first(stack_b)->val > ft_dllist_last(stack_a)->val)
		{
			ft_pa(stack_a, stack_b);
			ft_ra(stack_a, stack_b);
		}
		else
		{
			if (ft_dllist_first(stack_b)->val < ft_dllist_next(ft_dllist_first(stack_a))->val)
			{
				ft_pa(stack_a, stack_b);
				ft_sa(stack_a, stack_b);
			}
			else
			{
				ft_rra(stack_a, stack_b);
				ft_pa(stack_a, stack_b);
				ft_ra(stack_a, stack_b);
				ft_ra(stack_a, stack_b);
			}
		}
	}
	if (ft_dllist_is_empty(stack_b) == false)
	{
		if (ft_dllist_first(stack_b)->val < ft_dllist_first(stack_a)->val)
			ft_pa(stack_a, stack_b);
		else if (ft_dllist_first(stack_b)->val > ft_dllist_last(stack_a)->val)
		{
			ft_pa(stack_a, stack_b);
			ft_ra(stack_a, stack_b);
		}
		else
		{
			// optimize this code
			while (ft_dllist_first(stack_b)->val \
					> ft_dllist_first(stack_a)->val)
				ft_ra(stack_a, stack_b);
			ft_pa(stack_a, stack_b);
			while (ft_stack_is_sorted(stack_a) == false)
				ft_rra(stack_a, stack_b);
		}
	}
}
