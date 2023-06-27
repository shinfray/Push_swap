/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 01:25:30 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/27 20:21:31 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

unsigned int	ft_correct_pos_a(t_dllist *stack, int n);
unsigned int	ft_correct_pos_b(t_dllist *stack, int n);
unsigned int	ft_get_value_index(t_dllist *stack, int n);

unsigned int	ft_correct_pos_a(t_dllist *stack, int n)
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

unsigned int	ft_correct_pos_b(t_dllist *stack, int n)
{
	t_dllist_node	*temp;
	int				max_value;
	unsigned int	i;

	if (n > ft_dllist_first(stack)->val && n < ft_dllist_last(stack)->val)
		return (0);
	max_value = ft_get_max_value(stack);
	i = ft_get_value_index(stack, max_value);
	if (n < ft_get_min_value(stack) || n > max_value)
		return (i);
	temp = ft_dllist_first(stack);
	while (temp->val != max_value)
		temp = ft_dllist_next(temp);
	while (n < temp->val)
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

unsigned int	ft_get_value_index(t_dllist *stack, int n)
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
