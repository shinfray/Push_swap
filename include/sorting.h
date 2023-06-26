/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 02:19:40 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/26 12:26:28 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

# include "dllist.h"

typedef struct choice
{
	void			(*fun)(t_stacks *, struct choice *);
	long int		steps;
	unsigned int	from;
	unsigned int	to;
}				t_choice;

typedef struct pos
{
	unsigned int	pos_a;
	unsigned int	pos_b;
	unsigned int	size_a;
	unsigned int	size_b;
}				t_pos;

/*
 *	SORTING FUNCTIONS
*/
/*	SORT	*/
void			ft_sort(t_stacks *stacks);
void			ft_sort_list_up_to_3(t_dllist *stack_a);
/*	CHECK_INDEX	*/
unsigned int	ft_correct_pos_a(t_dllist *stack, int n);
unsigned int	ft_correct_pos_b(t_dllist *stack, int n);
unsigned int	ft_get_value_index(t_dllist *stack, int n);
/*	CHOOSE_MOVES_TO_B	*/
void			ft_choose_moves_to_b(t_stacks *stacks, t_choice *choice);
/*	SET_MOVES	*/
void			ft_set_r_rr(t_choice *choice, t_pos *pos, unsigned int steps);
void			ft_set_rr_rrr(t_choice *choice, t_pos *pos, unsigned int steps);
void			ft_set_ra_rrb(t_choice *choice, t_pos *pos, unsigned int steps);
void			ft_set_rra_rb(t_choice *choice, t_pos *pos, unsigned int steps);
/*	DO_MOVES	*/
void			ft_do_r_rr(t_stacks *stacks, t_choice *choice);
void			ft_do_rr_rrr(t_stacks *stacks, t_choice *choice);
void			ft_do_ra_rrb(t_stacks *stacks, t_choice *choice);
void			ft_do_rra_rb(t_stacks *stacks, t_choice *choice);
void			ft_do_ra_or_rra(t_dllist *stack, unsigned int i);
/*	SORT_UTILS	*/
bool			ft_stack_is_sorted(t_dllist *stack_a);
int				ft_get_min_value(t_dllist *stack);
int				ft_get_max_value(t_dllist *stack);
unsigned int	ft_max(unsigned int a, unsigned int b);

#endif
