/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:41:32 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/26 11:53:10 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_r_rr(t_stacks *stacks, t_choice s_choice);
void	ft_do_rr_rrr(t_stacks *stacks, t_choice s_choice);
void	ft_do_ra_rrb(t_stacks *stacks, t_choice s_choice);
void	ft_do_rra_rb(t_stacks *stacks, t_choice s_choice);
void	ft_do_ra_or_rra(t_dllist *stack, unsigned int i);

void	ft_do_r_rr(t_stacks *stacks, t_choice s_choice)
{
	while (s_choice.from > 0 && s_choice.to > 0)
	{
		ft_rr(stacks->stack_a, stacks->stack_b);
		--s_choice.from;
		--s_choice.to;
	}
	while (s_choice.from-- > 0)
		ft_ra(stacks->stack_a);
	while (s_choice.to-- > 0)
		ft_rb(stacks->stack_b);
}

void	ft_do_rr_rrr(t_stacks *stacks, t_choice s_choice)
{
	while (s_choice.from < stacks->stack_a->total_nodes && s_choice.to < stacks->stack_b->total_nodes)
	{
		ft_rrr(stacks->stack_a, stacks->stack_b);
		++s_choice.from;
		++s_choice.to;
	}
	while (s_choice.from++ < stacks->stack_a->total_nodes)
		ft_rra(stacks->stack_a);
	while (s_choice.to++ < stacks->stack_b->total_nodes)
		ft_rrb(stacks->stack_b);
}

void	ft_do_ra_rrb(t_stacks *stacks, t_choice s_choice)
{
	while (s_choice.from-- > 0)
		ft_ra(stacks->stack_a);
	while (s_choice.to++ < stacks->stack_b->total_nodes)
		ft_rrb(stacks->stack_b);
}

void	ft_do_rra_rb(t_stacks *stacks, t_choice s_choice)
{
	while (s_choice.from++ < stacks->stack_a->total_nodes)
		ft_rra(stacks->stack_a);
	while (s_choice.to-- > 0)
		ft_rb(stacks->stack_b);
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
