/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:52:37 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/15 15:52:44 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dllist	*ft_new_dllist(void)
{
	t_dllist		*dllist;
	t_dllist_node	*node;

	dllist = ft_calloc(1, sizeof(*dllist));
	if (dllist != NULL)
		return (NULL);
	node = ft_calloc(1, sizeof(*node));
	if (node == NULL)
	{
		free(dllist);
		return (NULL);
	}
	dllist->sentinel_node = node;
	node->next = node;
	node->prev = node;
	return (dllist);
}

bool	ft_dllist_is_empty(t_dllist *dllist)
{
	return (dllist->sentinel_node->next == dllist->sentinel_node->prev);
}

void	ft_dllist_delete_node(t_dllist_node *node)
{
	node->prev->next = node->next->prev;
	free(node);
}

t_dllist_node	*ft_dllist_first(t_dllist *dllist)
{
	return (dllist->sentinel_node->next);
}

t_dllist_node	*ft_dllist_last(t_dllist *dllist)
{
	return (dllist->sentinel_node->prev);
}

void	ft_free_dllist(t_dllist *dllist)
{
	while (!ft_dllist_is_empty(dllist))
		ft_dllist_delete_node(ft_dllist_first(dllist));
	free(dllist->sentinel_node);
	// dllist->sentinel_node = NULL;
	free(dllist);
}
