/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 01:14:01 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/25 01:51:56by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_r_rr(t_dllist *stack_a, t_dllist *stack_b, unsigned int index_a, unsigned int index_b);
void	ft_do_rr_rrr(t_dllist *stack_a, t_dllist *stack_b, unsigned int index_a, unsigned int index_b);
void	ft_do_ra_rrb(t_dllist *stack_a, t_dllist *stack_b, unsigned int index_a, unsigned int index_b);
void	ft_do_rra_rb(t_dllist *stack_a, t_dllist *stack_b, unsigned int index_a, unsigned int index_b);
void	ft_do_ra_or_rra(t_dllist *stack, unsigned int i);

void	ft_do_r_rr(t_dllist *stack_a, t_dllist *stack_b, unsigned int index_a, unsigned int index_b)
{
	while (index_a > 0 && index_b > 0)
	{
		ft_rr(stack_a, stack_b);
		--index_a;
		--index_b;
	}
	while (index_a-- > 0)
		ft_ra(stack_a);
	while (index_b-- > 0)
		ft_rb(stack_b);
}

void	ft_do_rr_rrr(t_dllist *stack_a, t_dllist *stack_b, unsigned int index_a, unsigned int index_b)
{
	while (index_a < stack_a->total_nodes && index_b < stack_b->total_nodes)
	{
		ft_rrr(stack_a, stack_b);
		++index_a;
		++index_b;
	}
	while (index_a++ < stack_a->total_nodes)
		ft_rra(stack_a);
	while (index_b++ < stack_b->total_nodes)
		ft_rrb(stack_b);
}

void	ft_do_ra_rrb(t_dllist *stack_a, t_dllist *stack_b, unsigned int index_a, unsigned int index_b)
{
	while (index_a-- > 0)
		ft_ra(stack_a);
	while (index_b++ < stack_b->total_nodes)
		ft_rrb(stack_b);
}

void	ft_do_rra_rb(t_dllist *stack_a, t_dllist *stack_b, unsigned int index_a, unsigned int index_b)
{
	while (index_a++ < stack_a->total_nodes)
		ft_rra(stack_a);
	while (index_b-- > 0)
		ft_rb(stack_b);
}

void	ft_do_ra_or_rra(t_dllist *stack, unsigned int i)
{
	if (i <= stack->total_nodes / 2)
		while (i-- > 0)
			ft_ra(stack);
	else
		while (i++ < stack->total_nodes)
			ft_rra(stack);
}
