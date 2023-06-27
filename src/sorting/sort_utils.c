/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:03:09 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/27 20:21:52 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

bool			ft_stack_is_sorted(t_dllist *stack_a);
int				ft_get_min_value(t_dllist *stack);
int				ft_get_max_value(t_dllist *stack);
unsigned int	ft_max(unsigned int a, unsigned int b);

bool	ft_stack_is_sorted(t_dllist *stack_a)
{
	t_dllist_node	*current_node;
	t_dllist_node	*next_node;

	current_node = ft_dllist_first(stack_a);
	next_node = ft_dllist_next(current_node);
	while (next_node != stack_a->sentinel_node)
	{
		if (current_node->val > next_node->val)
			return (false);
		current_node = next_node;
		next_node = ft_dllist_next(current_node);
	}
	return (true);
}

int	ft_get_min_value(t_dllist *stack)
{
	t_dllist_node	*current_node;
	int				min;

	current_node = ft_dllist_first(stack);
	min = current_node->val;
	while (current_node != stack->sentinel_node)
	{
		if (min > current_node->val)
			min = current_node->val;
		current_node = ft_dllist_next(current_node);
	}
	return (min);
}

int	ft_get_max_value(t_dllist *stack)
{
	t_dllist_node	*current_node;
	int				max;

	current_node = ft_dllist_first(stack);
	max = current_node->val;
	while (current_node != stack->sentinel_node)
	{
		if (max < current_node->val)
			max = current_node->val;
		current_node = ft_dllist_next(current_node);
	}
	return (max);
}

unsigned int	ft_max(unsigned int a, unsigned int b)
{
	if (a > b)
		return (a);
	return (b);
}
