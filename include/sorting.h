/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 02:19:40 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/25 02:22:13 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

# include "dllist.h"

typedef struct choice
{
	t_dllist		*stack_a;
	t_dllist		*stack_b;
	void			(*fun)(t_dllist *, t_dllist *, unsigned int, unsigned int);
	long int		steps;
	unsigned int	from;
	unsigned int	to;
}				t_choice;

/*
 *	SORTING FUNCTIONS
*/
/*	SORT	*/
void			ft_sort(t_dllist *stack_a, t_dllist *stack_b);
void			ft_sort_list_up_to_3(t_dllist *stack_a);
/*	CHECK_INDEX	*/
unsigned int	ft_get_desired_index_to_a(t_dllist *stack, int n);
unsigned int	ft_get_desired_index_to_b(t_dllist *stack, int n);
unsigned int	ft_get_value_index(t_dllist *stack, int n);
/*	CHOOSE_MOVES_TO_B	*/
void			ft_choose_moves_to_b(t_dllist *stack_a, t_dllist *stack_b, t_choice *choice);
/*	DO_MOVES	*/
void			ft_do_r_rr(t_dllist *stack_a, t_dllist *stack_b, unsigned int index_a, unsigned int index_b);
void			ft_do_rr_rrr(t_dllist *stack_a, t_dllist *stack_b, unsigned int index_a, unsigned int index_b);
void			ft_do_ra_rrb(t_dllist *stack_a, t_dllist *stack_b, unsigned int index_a, unsigned int index_b);
void			ft_do_rra_rb(t_dllist *stack_a, t_dllist *stack_b, unsigned int index_a, unsigned int index_b);
void			ft_do_ra_or_rra(t_dllist *stack, unsigned int i);
/*	SORT_UTILS	*/
bool			ft_stack_is_sorted(t_dllist *stack_a);
int				ft_get_min_value(t_dllist *stack);
int				ft_get_max_value(t_dllist *stack);
unsigned int	ft_max(unsigned int a, unsigned int b);

#endif
