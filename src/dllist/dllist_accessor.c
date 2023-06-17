/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist_accessor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:03:39 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/17 14:49:17 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dllist_node	*ft_dllist_next(t_dllist_node *dllist);
t_dllist_node	*ft_dllist_prev(t_dllist_node *dllist);
t_dllist_node	*ft_dllist_first(t_dllist *dllist);
t_dllist_node	*ft_dllist_last(t_dllist *dllist);

t_dllist_node	*ft_dllist_next(t_dllist_node *node)
{
	return (node->next);
}

t_dllist_node	*ft_dllist_prev(t_dllist_node *node)
{
	return (node->prev);
}

t_dllist_node	*ft_dllist_first(t_dllist *dllist)
{
	return (ft_dllist_next(dllist->sentinel_node));
}

t_dllist_node	*ft_dllist_last(t_dllist *dllist)
{
	return (ft_dllist_prev(dllist->sentinel_node));
}
