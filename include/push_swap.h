/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:55:25 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/25 01:56:02by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include "libft.h"

typedef struct dllist_node
{
	struct dllist_node	*next;
	struct dllist_node	*prev;
	int					val;
}				t_dllist_node;

typedef struct dllist
{
	t_dllist_node	*sentinel_node;
	unsigned int	total_nodes;
	unsigned int	biggest_number;
}				t_dllist;

typedef struct stacks
{
	t_dllist	*stack_a;
	t_dllist	*stack_b;
}				t_stacks;

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
 *	INITIALIZATION_CLOSURE FUNCTIONS
*/
/*	INITIALIZE_STACKS	*/
int				ft_initialize_stacks(t_stacks *stacks);
/*	PARSE FUNCTIONS	*/
char			**ft_check_args_format(int argc, char **argv);
t_dllist		*ft_retrieve_args(t_dllist *dllist, char **args_list);
/*	CLOSURE FUNCTIONS	*/
void			ft_free_push_swap(t_stacks *stacks, char **nums, char **argv);
int				ft_exit_push_swap(int exit_status);

/*
 *	DLLIST FUNCTIONS
*/
/*  DLLIST_ACCESSOR    */
t_dllist_node	*ft_dllist_next(t_dllist_node *node);
t_dllist_node	*ft_dllist_prev(t_dllist_node *node);
t_dllist_node	*ft_dllist_first(t_dllist *dllist);
t_dllist_node	*ft_dllist_last(t_dllist *dllist);
/*	DLLIST_CREATION_DESTRUCTION	*/
t_dllist		*ft_new_dllist(void);
void			ft_free_dllist(t_dllist *dllist);
bool			ft_dllist_is_empty(t_dllist *dllist);
/*	DLLIST_INSERTION	*/
t_dllist_node	*ft_dllist_append(t_dllist *dllist, int val);

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

/*
 *	MOVES FUNCTIONS
*/
/*	S_MOVES SWAP	*/
void			ft_sa(t_dllist *stack_a);
void			ft_sb(t_dllist *stack_b);
void			ft_ss(t_dllist *stack_a, t_dllist *stack_b);
/*	P_MOVES PUSH	*/
void			ft_pa(t_dllist *stack_a, t_dllist *stack_b);
void			ft_pb(t_dllist *stack_a, t_dllist *stack_b);
/*	R_MOVES ROTATE	*/
void			ft_ra(t_dllist *stack_a);
void			ft_rb(t_dllist *stack_b);
void			ft_rr(t_dllist *stack_a, t_dllist *stack_b);
/*	RR_MOVES REVERSE ROTATE	*/
void			ft_rra(t_dllist *stack_a);
void			ft_rrb(t_dllist *stack_b);
void			ft_rrr(t_dllist *stack_a, t_dllist *stack_b);

#endif
