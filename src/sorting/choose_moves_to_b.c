/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_moves_to_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 01:18:01 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/26 10:53:54 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_choose_moves_to_b(t_dllist *stack_a, t_dllist *stack_b, t_choice *choice);
static void	ft_apply_r_rr(t_choice *choice, unsigned int index_a, unsigned int index_b, unsigned int steps);
static void	ft_apply_rr_rrr(t_choice *choice, unsigned int index_a, unsigned int index_b, unsigned int steps);
static void	ft_apply_ra_rrb(t_choice *choice, unsigned int index_a, unsigned int index_b, unsigned int steps);
static void	ft_apply_rra_rb(t_choice *choice, unsigned int index_a, unsigned int index_b, unsigned int steps);

static void	ft_check_steps(t_choice *choice, t_pos *s_pos)
{
	const unsigned int	pos_a = s_pos->pos_a;
	const unsigned int	pos_b = s_pos->pos_b;
	const unsigned int	size_a = s_pos->size_a;
	const unsigned int	size_b = s_pos->size_b;

	if (choice->steps == -1 || choice->steps > ft_max(pos_a, pos_b))
		ft_apply_r_rr(choice, pos_a, pos_b, ft_max(pos_a, pos_b));
	if (choice->steps > ft_max(size_a - pos_a, size_b - pos_b))
		ft_apply_rr_rrr(choice, pos_a, pos_b, ft_max(size_a - pos_a, size_b - pos_b));
	if (choice->steps > pos_a + size_b - pos_b)
		ft_apply_ra_rrb(choice, pos_a, pos_b, pos_a + size_b - pos_b);
	if (choice->steps > pos_b + size_a - pos_a)
		ft_apply_rra_rb(choice, pos_a, pos_b, pos_b + size_a - pos_a);
}

void	ft_choose_moves_to_b(t_dllist *stack_a, t_dllist *stack_b, t_choice *choice)
{
	t_dllist_node	*current_node;
	t_pos			s_pos;

	s_pos.size_a = stack_a->total_nodes;
	s_pos.size_b = stack_b->total_nodes;
	s_pos.pos_a = 0;
	choice->steps = -1;
	current_node = ft_dllist_first(stack_a);
	while (current_node != stack_a->sentinel_node)
	{
		s_pos.pos_b = ft_get_desired_index_to_b(stack_b, current_node->val);
		ft_check_steps(choice, &s_pos);
		current_node = ft_dllist_next(current_node);
		++s_pos.pos_a;
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
