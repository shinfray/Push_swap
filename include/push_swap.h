/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:06:36 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/16 16:49:51 by shinfray         ###   ########.fr       */
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

#endif
