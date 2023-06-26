/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:47:33 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/26 18:30:20 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void		ft_rra_s(t_dllist *stack_a, t_dllist *stack_b);
void		ft_rrb_s(t_dllist *stack_a, t_dllist *stack_b);
void		ft_rrr_s(t_dllist *stack_a, t_dllist *stack_b);
static void	ft_reverse_r(t_dllist *stack);

void	ft_rra_s(t_dllist *stack_a, t_dllist *stack_b)
{
	(void)stack_b;
	if (stack_a->total_nodes > 1)
		ft_reverse_r(stack_a);
}

void	ft_rrb_s(t_dllist *stack_a, t_dllist *stack_b)
{
	(void)stack_a;
	if (stack_b->total_nodes > 1)
		ft_reverse_r(stack_b);
}

void	ft_rrr_s(t_dllist *stack_a, t_dllist *stack_b)
{
	if (stack_a->total_nodes > 1)
		ft_reverse_r(stack_a);
	if (stack_b->total_nodes > 1)
		ft_reverse_r(stack_b);
}

static void	ft_reverse_r(t_dllist *stack)
{
	t_dllist_node	*first_node;
	t_dllist_node	*last_node;
	t_dllist_node	*before_last_node;

	first_node = ft_dllist_first(stack);
	last_node = ft_dllist_last(stack);
	before_last_node = ft_dllist_prev(last_node);
	stack->sentinel_node->next = last_node;
	stack->sentinel_node->prev = before_last_node;
	first_node->prev = last_node;
	last_node->next = first_node;
	last_node->prev = stack->sentinel_node;
	before_last_node->next = stack->sentinel_node;
}
