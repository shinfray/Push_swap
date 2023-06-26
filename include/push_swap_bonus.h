/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 02:25:01 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/26 23:56:14 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <limits.h>
# include <stdbool.h>
# include "push_swap.h"
# include "get_next_line.h"

/*
 *	CHECKER_UTILS FUNCTIONS
*/
int		ft_get_moves(t_dllist *stack_a, t_dllist *stack_b);
void	ft_print_result(t_stacks *stacks);
/*
 *	SILENT_MOVES FUNCTIONS
*/
/*	S_MOVES	*/
void	ft_sa_s(t_dllist *stack_a, t_dllist *stack_b);
void	ft_sb_s(t_dllist *stack_a, t_dllist *stack_b);
void	ft_ss_s(t_dllist *stack_a, t_dllist *stack_b);
/*	P_MOVES	*/
void	ft_pa_s(t_dllist *stack_a, t_dllist *stack_b);
void	ft_pb_s(t_dllist *stack_a, t_dllist *stack_b);
/*	R_MOVES	*/
void	ft_ra_s(t_dllist *stack_a, t_dllist *stack_b);
void	ft_rb_s(t_dllist *stack_a, t_dllist *stack_b);
void	ft_rr_s(t_dllist *stack_a, t_dllist *stack_b);
/*	RR_MOVES	*/
void	ft_rra_s(t_dllist *stack_a, t_dllist *stack_b);
void	ft_rrb_s(t_dllist *stack_a, t_dllist *stack_b);
void	ft_rrr_s(t_dllist *stack_a, t_dllist *stack_b);

#endif
