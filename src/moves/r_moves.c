/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:03:22 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/24 01:17:32 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_ra(t_dllist *stack_a);
void		ft_rb(t_dllist *stack_b);
void		ft_rr(t_dllist *stack_a, t_dllist *stack_b);
static void	ft_r(t_dllist *stack);

void	ft_ra(t_dllist *stack_a)
{
	if (stack_a->total_nodes > 1)
		ft_r(stack_a);
	ft_putendl_fd("ra", STDOUT_FILENO);
}

void	ft_rb(t_dllist *stack_b)
{
	if (stack_b->total_nodes > 1)
		ft_r(stack_b);
	ft_putendl_fd("rb", STDOUT_FILENO);
}

void	ft_rr(t_dllist *stack_a, t_dllist *stack_b)
{
	if (stack_a->total_nodes > 1)
		ft_r(stack_a);
	if (stack_b->total_nodes > 1)
		ft_r(stack_b);
	ft_putendl_fd("rr", STDOUT_FILENO);
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
