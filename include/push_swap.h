/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:06:36 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/17 12:17:11 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include "libft.h"

/*  to remove   */
#include <stdio.h>

typedef struct dllist_node
{
    struct dllist_node  *next;
    struct dllist_node  *prev;
    int                 val;
}               t_dllist_node;

typedef struct dllist
{
    t_dllist_node   *sentinel_node;
	size_t			total_nodes;
}               t_dllist;

/*  DLLIST FUNCTIONS    */
t_dllist	    *ft_new_dllist(void);
bool	        ft_dllist_is_empty(t_dllist *dllist);
void	        ft_dllist_delete_node(t_dllist_node *node);
t_dllist_node	*ft_dllist_first(t_dllist *dllist);
t_dllist_node	*ft_dllist_last(t_dllist *dllist);
void	        ft_free_dllist(t_dllist *dllist);
t_dllist_node	*ft_dllist_insert_before(t_dllist_node *node, int value);
t_dllist_node	*ft_dllist_insert_after(t_dllist_node *node, int value);
t_dllist_node	*ft_dllist_prepend(t_dllist *dllist, int value);
t_dllist_node	*ft_dllist_append(t_dllist *dllist, int value);
t_dllist_node 	*ft_dllist_next(t_dllist_node *node);
t_dllist_node	*ft_dllist_prev(t_dllist_node *node);

/*  PARSE FUNCTIONS    */
t_dllist	*ft_retrieve_args(t_dllist *dllist, int argc, char **argv);
int			ft_atoi_ps(const char *str, bool *error_status);
bool		ft_is_duplicate_number(t_dllist *dllist, int n);

/*	MOVES FUNCTIONS	*/
void	ft_sa(t_dllist *stack_a, t_dllist *stack_b);
void	ft_sb(t_dllist *stack_a, t_dllist *stack_b);
void	ft_ss(t_dllist *stack_a, t_dllist *stack_b);
void	ft_pa(t_dllist *stack_a, t_dllist *stack_b);
void	ft_pb(t_dllist *stack_a, t_dllist *stack_b);
void	ft_ra(t_dllist *stack_a, t_dllist *stack_b);
void	ft_rb(t_dllist *stack_a, t_dllist *stack_b);
void	ft_rr(t_dllist *stack_a, t_dllist *stack_b);
void	ft_rra(t_dllist *stack_a, t_dllist *stack_b);
void	ft_rrb(t_dllist *stack_a, t_dllist *stack_b);
void	ft_rrr(t_dllist *stack_a, t_dllist *stack_b);

#endif
