/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:03:59 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/24 01:19:33 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_sa(t_dllist *stack_a);
void		ft_sb(t_dllist *stack_b);
void		ft_ss(t_dllist *stack_a, t_dllist *stack_b);
static void	ft_s(t_dllist *stack);

void	ft_sa(t_dllist *stack_a)
{
	if (stack_a->total_nodes > 1)
	{
		ft_s(stack_a);
		ft_putendl_fd("sa", STDOUT_FILENO);
	}
}

void	ft_sb(t_dllist *stack_b)
{
	if (stack_b->total_nodes > 1)
	{
		ft_s(stack_b);
		ft_putendl_fd("sb", STDOUT_FILENO);
	}
}

void	ft_ss(t_dllist *stack_a, t_dllist *stack_b)
{
	if (stack_a->total_nodes > 1 || stack_b->total_nodes > 1)
	{
		if (stack_a->total_nodes > 1)
			ft_s(stack_a);
		if (stack_b->total_nodes > 1)
			ft_s(stack_b);
		ft_putendl_fd("ss", STDOUT_FILENO);
	}
}

static void	ft_s(t_dllist *stack)
{
	t_dllist_node	*node_a;
	t_dllist_node	*node_b;
	t_dllist_node	*node_c;

	node_a = ft_dllist_first(stack);
	node_b = ft_dllist_next(node_a);
	node_c = ft_dllist_next(node_b);
	stack->sentinel_node->next = node_b;
	node_a->prev = node_b;
	node_a->next = node_c;
	node_b->prev = stack->sentinel_node;
	node_b->next = node_a;
	node_c->prev = node_a;
}
