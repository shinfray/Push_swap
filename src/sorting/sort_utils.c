/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:03:09 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/22 15:37:47 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_stack_is_sorted(t_dllist *stack_a);

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
