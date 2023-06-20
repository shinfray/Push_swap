/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:55:25 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/20 09:36:41 by shinfray         ###   ########.fr       */
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
}				t_dllist;

/*
 *	INITIALIZATION_CLOSURE FUNCTIONS
*/
/*	INITIALIZE STACKS	*/
int				ft_initialize_stacks(t_dllist **stack_a, t_dllist **stack_b);
/*	PARSE FUNCTIONS	*/
char			**ft_check_args_format(int argc, char **argv);
t_dllist		*ft_retrieve_args(t_dllist *dllist, char **args_list);
/*	CLOSURE FUNCTIONS	*/
int				ft_exit_push_swap(int exit_status);
void			ft_free_stacks(t_dllist *stack_a, t_dllist *stack_b);
void			ft_free_args_list(char **args_list);

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
 *	MOVES FUNCTIONS
*/
/*	SWAP	*/
void			ft_sa(t_dllist *stack_a, t_dllist *stack_b);
void			ft_sb(t_dllist *stack_a, t_dllist *stack_b);
void			ft_ss(t_dllist *stack_a, t_dllist *stack_b);
/*	PUSH	*/
void			ft_pa(t_dllist *stack_a, t_dllist *stack_b);
void			ft_pb(t_dllist *stack_a, t_dllist *stack_b);
/*	ROTATE	*/
void			ft_ra(t_dllist *stack_a, t_dllist *stack_b);
void			ft_rb(t_dllist *stack_a, t_dllist *stack_b);
void			ft_rr(t_dllist *stack_a, t_dllist *stack_b);
/*	REVERSE ROTATE	*/
void			ft_rra(t_dllist *stack_a, t_dllist *stack_b);
void			ft_rrb(t_dllist *stack_a, t_dllist *stack_b);
void			ft_rrr(t_dllist *stack_a, t_dllist *stack_b);

#endif
