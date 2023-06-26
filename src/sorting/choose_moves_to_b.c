/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_moves_to_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 01:18:01 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/26 12:13:39 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_choose_moves_to_b(t_stacks *stacks, t_choice *choice);
static void	ft_check_steps(t_choice *choice, t_pos *pos);

void	ft_choose_moves_to_b(t_stacks *stacks, t_choice *choice)
{
	t_dllist_node	*current_node;
	t_pos			s_pos;

	s_pos.size_a = stacks->stack_a->total_nodes;
	s_pos.size_b = stacks->stack_b->total_nodes;
	s_pos.pos_a = 0;
	choice->steps = -1;
	current_node = ft_dllist_first(stacks->stack_a);
	while (current_node != stacks->stack_a->sentinel_node)
	{
		s_pos.pos_b = ft_correct_pos_b(stacks->stack_b, current_node->val);
		ft_check_steps(choice, &s_pos);
		current_node = ft_dllist_next(current_node);
		++s_pos.pos_a;
	}
}

static void	ft_check_steps(t_choice *choice, t_pos *pos)
{
	unsigned int		steps;

	steps = ft_max(pos->pos_a, pos->pos_b);
	if (choice->steps == -1 || choice->steps > steps)
		ft_set_r_rr(choice, pos, steps);
	steps = ft_max(pos->size_a - pos->pos_a, pos->size_b - pos->pos_b);
	if (choice->steps > steps)
		ft_set_rr_rrr(choice, pos, steps);
	steps = pos->pos_a + pos->size_b - pos->pos_b;
	if (choice->steps > steps)
		ft_set_ra_rrb(choice, pos, steps);
	steps = pos->pos_b + pos->size_a - pos->pos_a;
	if (choice->steps > steps)
		ft_set_rra_rb(choice, pos, steps);
}
