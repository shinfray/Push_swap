/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist_creation_destruction.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:03:52 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/17 14:19:09 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dllist	*ft_new_dllist(void);
void		ft_free_dllist(t_dllist *dllist);
bool		ft_dllist_is_empty(t_dllist *dllist);
static void	ft_dllist_delete_node(t_dllist_node *node);

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

void	ft_free_dllist(t_dllist *dllist)
{
	while (!ft_dllist_is_empty(dllist))
		ft_dllist_delete_node(ft_dllist_first(dllist));
	free(dllist->sentinel_node);
	free(dllist);
}

bool	ft_dllist_is_empty(t_dllist *dllist)
{
	return (ft_dllist_next(dllist->sentinel_node) == dllist->sentinel_node);
}

static void	ft_dllist_delete_node(t_dllist_node *node)
{
	ft_dllist_prev(node)->next = ft_dllist_next(node);
	ft_dllist_next(node)->prev = ft_dllist_prev(node);
	free(node);
}
