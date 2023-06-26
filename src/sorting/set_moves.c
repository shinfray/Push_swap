/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:26:17 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/26 11:30:08 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_r_rr(t_choice *choice, t_pos *pos, unsigned int steps);
void	ft_set_rr_rrr(t_choice *choice, t_pos *pos, unsigned int steps);
void	ft_set_ra_rrb(t_choice *choice, t_pos *pos, unsigned int steps);
void	ft_set_rra_rb(t_choice *choice, t_pos *pos, unsigned int steps);

void	ft_set_r_rr(t_choice *choice, t_pos *pos, unsigned int steps)
{
	choice->steps = steps;
	choice->from = pos->pos_a;
	choice->to = pos->pos_b;
	choice->fun = &ft_do_r_rr;
}

void	ft_set_rr_rrr(t_choice *choice, t_pos *pos, unsigned int steps)
{
	choice->steps = steps;
	choice->from = pos->pos_a;
	choice->to = pos->pos_b;
	choice->fun = &ft_do_rr_rrr;
}

void	ft_set_ra_rrb(t_choice *choice, t_pos *pos, unsigned int steps)
{
	choice->steps = steps;
	choice->from = pos->pos_a;
	choice->to = pos->pos_b;
	choice->fun = &ft_do_ra_rrb;
}

void	ft_set_rra_rb(t_choice *choice, t_pos *pos, unsigned int steps)
{
	choice->steps = steps;
	choice->from = pos->pos_a;
	choice->to = pos->pos_b;
	choice->fun = &ft_do_rra_rb;
}
