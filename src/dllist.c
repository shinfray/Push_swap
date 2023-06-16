/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:52:37 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/16 10:19:39 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

t_dllist	*ft_new_dllist(void)
{
	t_dllist		*dllist;
	t_dllist_node	*node;

	dllist = ft_calloc(1, sizeof(*dllist));
	if (dllist == NULL)
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
	return (ft_dllist_next(dllist->sentinel_node) == dllist->sentinel_node);
}

void	ft_dllist_delete_node(t_dllist_node *node)
{
	ft_dllist_prev(node)->next = ft_dllist_next(node)->prev;
	free(node);
}

t_dllist_node	*ft_dllist_first(t_dllist *dllist)
{
	return (ft_dllist_next(dllist->sentinel_node));
}

t_dllist_node	*ft_dllist_last(t_dllist *dllist)
{
	return (ft_dllist_prev(dllist->sentinel_node));
}

void	ft_free_dllist(t_dllist *dllist)
{
	while (!ft_dllist_is_empty(dllist))
		ft_dllist_delete_node(ft_dllist_first(dllist));
	free(dllist->sentinel_node);
	// dllist->sentinel_node = NULL;
	free(dllist);
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

t_dllist_node	*ft_dllist_insert_after(t_dllist_node *node, int value)
{
	t_dllist_node	*new_node;
	t_dllist_node	*next_node;

	next_node = ft_dllist_next(node);
	new_node = ft_calloc(1, sizeof(*new_node));
	if (new_node == NULL)
		return (NULL);
	new_node->val = value;

	new_node->next = next_node;
	new_node->prev = node;
	next_node->prev = new_node;
	node->next = new_node;
	return (new_node);
}

t_dllist_node	*ft_dllist_prepend(t_dllist *dllist, int value)
{
	t_dllist_node	*new_node;
	t_dllist_node	*next_node;

	next_node = ft_dllist_first(dllist);
	new_node = ft_calloc(1, sizeof(*new_node));
	if (new_node == NULL)
		return (NULL);
	new_node->val = value;
	new_node->next = next_node;
	new_node->prev = dllist->sentinel_node;
	dllist->sentinel_node->next = new_node;
	next_node->prev = new_node;
	return (new_node);
}

t_dllist_node	*ft_dllist_append(t_dllist *dllist, int value)
{
	t_dllist_node	*new_node;
	t_dllist_node	*prev_node;

	prev_node = ft_dllist_last(dllist);
	new_node = ft_calloc(1, sizeof(*new_node));
	if (new_node == NULL)
		return (NULL);
	new_node->val = value;
	new_node->next = dllist->sentinel_node;
	new_node->prev = prev_node;
	dllist->sentinel_node->prev = new_node;
	prev_node->next = new_node;
	return (new_node);
}

t_dllist_node	*ft_dllist_next(t_dllist_node *node)
{
  return node->next;
}

t_dllist_node	*ft_dllist_prev(t_dllist_node *node)
{
  return node->prev;
}
