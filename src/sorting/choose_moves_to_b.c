/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 01:18:01 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/25 01:33:30 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_choose_moves_to_b(t_dllist *stack_a, t_dllist *stack_b, t_choice *choice);
static void	ft_apply_r_rr(t_choice *choice, unsigned int index_a, unsigned int index_b, unsigned int steps);
static void	ft_apply_rr_rrr(t_choice *choice, unsigned int index_a, unsigned int index_b, unsigned int steps);
static void	ft_apply_ra_rrb(t_choice *choice, unsigned int index_a, unsigned int index_b, unsigned int steps);
static void	ft_apply_rra_rb(t_choice *choice, unsigned int index_a, unsigned int index_b, unsigned int steps);

void	ft_choose_moves_to_b(t_dllist *stack_a, t_dllist *stack_b, t_choice *choice)
{
	t_dllist_node	*current_node;
	unsigned int	index_a;
	unsigned int	index_b;

	index_a = 0;
	choice->steps = -1;
	current_node = ft_dllist_first(stack_a);
	while (current_node != stack_a->sentinel_node)
	{
		index_b = ft_get_desired_index_to_b(stack_b, current_node->val);
		if (choice->steps == -1 || choice->steps > ft_max(index_a, index_b))
			ft_apply_r_rr(choice, index_a, index_b, ft_max(index_a, index_b));
		if (choice->steps > ft_max(stack_a->total_nodes - index_a, stack_b->total_nodes - index_b))
			ft_apply_rr_rrr(choice, index_a, index_b, ft_max(stack_a->total_nodes - index_a, stack_b->total_nodes - index_b));
		if (choice->steps > index_a + stack_b->total_nodes - index_b)
			ft_apply_ra_rrb(choice, index_a, index_b, index_a + stack_b->total_nodes - index_b);
		if (choice->steps > index_b + stack_a->total_nodes - index_a)
			ft_apply_rra_rb(choice, index_a, index_b, index_b + stack_a->total_nodes - index_a);
		current_node = ft_dllist_next(current_node);
		++index_a;
	}
}

static void	ft_apply_r_rr(t_choice *choice, unsigned int index_a, unsigned int index_b, unsigned int steps)
{
	choice->steps = steps;
	choice->from = index_a;
	choice->to = index_b;
	choice->fun = &ft_do_r_rr;
}

static void	ft_apply_rr_rrr(t_choice *choice, unsigned int index_a, unsigned int index_b, unsigned int steps)
{
	choice->steps = steps;
	choice->from = index_a;
	choice->to = index_b;
	choice->fun = &ft_do_rr_rrr;
}

static void	ft_apply_ra_rrb(t_choice *choice, unsigned int index_a, unsigned int index_b, unsigned int steps)
{
	choice->steps = steps;
	choice->from = index_a;
	choice->to = index_b;
	choice->fun = &ft_do_ra_rrb;
}

static void	ft_apply_rra_rb(t_choice *choice, unsigned int index_a, unsigned int index_b, unsigned int steps)
{
	choice->steps = steps;
	choice->from = index_a;
	choice->to = index_b;
	choice->fun = &ft_do_rra_rb;
}
