/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:03:44 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/17 14:48:12 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_pa(t_dllist *stack_a, t_dllist *stack_b);
void		ft_pb(t_dllist *stack_a, t_dllist *stack_b);
static void	ft_p(t_dllist *stack_to_push, t_dllist *stack_to_pop);

void	ft_pa(t_dllist *stack_a, t_dllist *stack_b)
{
	if (ft_dllist_is_empty(stack_b) == false)
	{
		ft_p(stack_a, stack_b);
		ft_putendl_fd("pa", STDOUT_FILENO);
		++(stack_a->total_nodes);
		--(stack_b->total_nodes);
	}
}

void	ft_pb(t_dllist *stack_a, t_dllist *stack_b)
{
	if (ft_dllist_is_empty(stack_a) == false)
	{
		ft_p(stack_b, stack_a);
		ft_putendl_fd("pb", STDOUT_FILENO);
		++(stack_b->total_nodes);
		--(stack_a->total_nodes);
	}
}

static void	ft_p(t_dllist *stack_to_push, t_dllist *stack_to_pop)
{
	t_dllist_node	*first_node_stack_to_pop;
	t_dllist_node	*second_node_stack_to_pop;
	t_dllist_node	*first_node_stack_to_push;

	first_node_stack_to_pop = ft_dllist_first(stack_to_pop);
	second_node_stack_to_pop = ft_dllist_next(first_node_stack_to_pop);
	first_node_stack_to_push = ft_dllist_first(stack_to_push);
	first_node_stack_to_pop->prev = stack_to_push->sentinel_node;
	first_node_stack_to_pop->next = first_node_stack_to_push;
	stack_to_pop->sentinel_node->next = second_node_stack_to_pop;
	second_node_stack_to_pop->prev = stack_to_pop->sentinel_node;
	stack_to_push->sentinel_node->next = first_node_stack_to_pop;
	first_node_stack_to_push->prev = first_node_stack_to_pop;
}
