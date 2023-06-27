/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist_insertion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:03:58 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/27 20:07:02 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dllist.h"

t_dllist_node			*ft_dllist_append(t_dllist *dllist, int val);
static t_dllist_node	*ft_dllist_insert_before(t_dllist_node *node, int val);

t_dllist_node	*ft_dllist_append(t_dllist *dllist, int val)
{
	return (ft_dllist_insert_before(dllist->sentinel_node, val));
}

t_dllist_node	*ft_dllist_insert_before(t_dllist_node *node, int val)
{
	t_dllist_node	*new_node;
	t_dllist_node	*prev_node;

	prev_node = ft_dllist_prev(node);
	new_node = ft_calloc(1, sizeof(*new_node));
	if (new_node == NULL)
		return (NULL);
	new_node->val = val;
	new_node->next = node;
	new_node->prev = prev_node;
	prev_node->next = new_node;
	node->prev = new_node;
	return (new_node);
}
