/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:55:25 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/22 12:14:29 by shinfray         ###   ########.fr       */
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
	size_t			total_nodes;
	unsigned int	biggest_abs_number;
}				t_dllist;

typedef struct stacks
{
	t_dllist	*stack_a;
	t_dllist	*stack_b;
}				t_stacks;

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
/*	RADIX_SORT	*/
void			ft_radix_sort(t_stacks *stacks);
/*	SORT_SMALL_LISTS	*/
void    		ft_sort_list_up_to_3(t_dllist *stack_a);
void    		ft_sort_list_up_to_5(t_dllist *stack_a, t_dllist *stack_b);
/*	SORT_UTILS	*/
bool			ft_stack_is_sorted(t_dllist *stack_a);

/*
 *	MOVES FUNCTIONS
*/
/*	S_MOVES SWAP	*/
void			ft_sa(t_dllist *stack_a, t_dllist *stack_b);
void			ft_sb(t_dllist *stack_a, t_dllist *stack_b);
void			ft_ss(t_dllist *stack_a, t_dllist *stack_b);
/*	P_MOVES PUSH	*/
void			ft_pa(t_dllist *stack_a, t_dllist *stack_b);
void			ft_pb(t_dllist *stack_a, t_dllist *stack_b);
/*	R_MOVES ROTATE	*/
void			ft_ra(t_dllist *stack_a, t_dllist *stack_b);
void			ft_rb(t_dllist *stack_a, t_dllist *stack_b);
void			ft_rr(t_dllist *stack_a, t_dllist *stack_b);
/*	RR_MOVES REVERSE ROTATE	*/
void			ft_rra(t_dllist *stack_a, t_dllist *stack_b);
void			ft_rrb(t_dllist *stack_a, t_dllist *stack_b);
void			ft_rrr(t_dllist *stack_a, t_dllist *stack_b);

#endif
