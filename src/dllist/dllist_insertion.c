/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist_insertion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:03:58 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/17 14:23:05 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dllist_node			*ft_dllist_append(t_dllist *dllist, int value);
static t_dllist_node	*ft_dllist_insert_before(t_dllist_node *node, int value);
// t_dllist_node	*ft_dllist_insert_after(t_dllist_node *node, int value);
// t_dllist_node	*ft_dllist_prepend(t_dllist *dllist, int value);

t_dllist_node	*ft_dllist_append(t_dllist *dllist, int value)
{
	return (ft_dllist_insert_before(dllist->sentinel_node, value));
}

t_dllist_node	*ft_dllist_insert_before(t_dllist_node *node, int value)
{
	t_dllist_node	*new_node;
	t_dllist_node	*prev_node;

	prev_node = ft_dllist_prev(node);
	new_node = ft_calloc(1, sizeof(*new_node));
	if (new_node == NULL)
		return (NULL);
	new_node->val = value;
	new_node->next = node;
	new_node->prev = prev_node;
	prev_node->next = new_node;
	node->prev = new_node;
	return (new_node);
}

// t_dllist_node	*ft_dllist_insert_after(t_dllist_node *node, int value)
// {
// 	t_dllist_node	*new_node;
// 	t_dllist_node	*next_node;

// 	next_node = ft_dllist_next(node);
// 	new_node = ft_calloc(1, sizeof(*new_node));
// 	if (new_node == NULL)
// 		return (NULL);
// 	new_node->val = value;

// 	new_node->next = next_node;
// 	new_node->prev = node;
// 	next_node->prev = new_node;
// 	node->next = new_node;
// 	return (new_node);
// }

// t_dllist_node	*ft_dllist_prepend(t_dllist *dllist, int value)
// {
// 	return (ft_dllist_insert_after(dllist->sentinel_node, value));
// }
