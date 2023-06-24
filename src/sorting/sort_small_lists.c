/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_lists.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:50:56 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/24 13:45:42 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				ft_sort_list_up_to_5(t_dllist *stack_a, t_dllist *stack_b);
void				ft_sort_list_up_to_3(t_dllist *stack_a);
static unsigned int	ft_get_desired_index(t_dllist *stack, int n);
static unsigned int	ft_get_value_index(t_dllist *stack, int n);
static void			ft_do_ra_or_rra(t_dllist *stack, unsigned int i);

void	ft_sort_list_up_to_5(t_dllist *stack_a, t_dllist *stack_b)
{
	unsigned int	i;
	int				min_value;

	while (stack_a->total_nodes > 3)
		ft_pb(stack_a, stack_b);
	if (ft_stack_is_sorted(stack_a) == false)
		ft_sort_list_up_to_3(stack_a);
	while (ft_dllist_is_empty(stack_b) == false)
	{
		i = ft_get_desired_index(stack_a, ft_dllist_first(stack_b)->val);
		ft_do_ra_or_rra(stack_a, i);
		ft_pa(stack_a, stack_b);
	}
	if (ft_stack_is_sorted(stack_a) == true)
		return ;
	min_value = ft_get_min_value(stack_a);
	i = ft_get_value_index(stack_a, min_value);
	ft_do_ra_or_rra(stack_a, i);
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

static unsigned int	ft_get_desired_index(t_dllist *stack, int n)
{
	t_dllist_node	*temp;
	int				min_value;
	unsigned int	i;

	if (n < ft_dllist_first(stack)->val && n > ft_dllist_last(stack)->val)
		return (0);
	min_value = ft_get_min_value(stack);
	i = ft_get_value_index(stack, min_value);
	if (n > ft_get_max_value(stack) || n < min_value)
		return (i);
	temp = ft_dllist_first(stack);
	while (temp->val != min_value)
		temp = ft_dllist_next(temp);
	while (n > temp->val)
	{
		++i;
		temp = ft_dllist_next(temp);
		if (temp == stack->sentinel_node)
		{
			temp = ft_dllist_first(stack);
			i = 0;
		}
	}
	return (i);
}

static unsigned int	ft_get_value_index(t_dllist *stack, int n)
{
	t_dllist_node	*current_node;
	unsigned int	i;

	current_node = ft_dllist_first(stack);
	i = 0;
	while (current_node->val != n)
	{
		current_node = ft_dllist_next(current_node);
		++i;
	}
	return (i);
}

static void	ft_do_ra_or_rra(t_dllist *stack, unsigned int i)
{
	if (stack->total_nodes - stack->total_nodes + i <= stack->total_nodes / 2)
		while (i-- > 0)
			ft_ra(stack);
	else
		while (i++ < stack->total_nodes)
			ft_rra(stack);
}
