/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:06:36 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/15 15:53:01 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdbool.h>
# include <stdlib.h>
# include "libft.h"

typedef struct dllist_node
{
    struct dllist_node  *next;
    struct dllist_node  *prev;
    int                 val;
}               t_dllist_node;

typedef struct dllist
{
    t_dllist_node   *sentinel_node;
}               t_dllist;

/*  DLLIST FUNCTIONS    */
t_dllist	    *ft_new_dllist(void);
bool	        ft_dllist_is_empty(t_dllist *dllist);
void	        ft_dllist_delete_node(t_dllist_node *node);
t_dllist_node	*ft_dllist_first(t_dllist *dllist);
t_dllist_node	*ft_dllist_last(t_dllist *dllist);
void	        ft_free_dllist(t_dllist *dllist);

#endif
