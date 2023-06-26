/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:03:22 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/26 18:47:14 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void		ft_ra_s(t_dllist *stack_a, t_dllist *stack_b);
void		ft_rb_s(t_dllist *stack_a, t_dllist *stack_b);
void		ft_rr_s(t_dllist *stack_a, t_dllist *stack_b);
static void	ft_r(t_dllist *stack);

void	ft_ra_s(t_dllist *stack_a, t_dllist *stack_b)
{
	(void)stack_b;
	if (stack_a->total_nodes > 1)
		ft_r(stack_a);
}

void	ft_rb_s(t_dllist *stack_a, t_dllist *stack_b)
{
	(void)stack_a;
	if (stack_b->total_nodes > 1)
		ft_r(stack_b);
}

void	ft_rr_s(t_dllist *stack_a, t_dllist *stack_b)
{
	if (stack_a->total_nodes > 1)
		ft_r(stack_a);
	if (stack_b->total_nodes > 1)
		ft_r(stack_b);
}

static void	ft_r(t_dllist *stack)
{
	t_dllist_node	*first_node;
	t_dllist_node	*second_node;
	t_dllist_node	*last_node;

	first_node = ft_dllist_first(stack);
	second_node = ft_dllist_next(first_node);
	last_node = ft_dllist_last(stack);
	stack->sentinel_node->next = second_node;
	stack->sentinel_node->prev = first_node;
	first_node->prev = last_node;
	first_node->next = stack->sentinel_node;
	last_node->next = first_node;
	second_node->prev = stack->sentinel_node;
}
