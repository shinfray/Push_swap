/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 02:22:48 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/25 02:24:35 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVES_H
# define MOVES_H

# include "dllist.h"

/*
 *	MOVES FUNCTIONS
*/
/*	S_MOVES SWAP	*/
void	ft_sa(t_dllist *stack_a);
void	ft_sb(t_dllist *stack_b);
void	ft_ss(t_dllist *stack_a, t_dllist *stack_b);
/*	P_MOVES PUSH	*/
void	ft_pa(t_dllist *stack_a, t_dllist *stack_b);
void	ft_pb(t_dllist *stack_a, t_dllist *stack_b);
/*	R_MOVES ROTATE	*/
void	ft_ra(t_dllist *stack_a);
void	ft_rb(t_dllist *stack_b);
void	ft_rr(t_dllist *stack_a, t_dllist *stack_b);
/*	RR_MOVES REVERSE ROTATE	*/
void	ft_rra(t_dllist *stack_a);
void	ft_rrb(t_dllist *stack_b);
void	ft_rrr(t_dllist *stack_a, t_dllist *stack_b);

#endif
