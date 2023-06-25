/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 02:14:14 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/25 02:18:05 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLLIST_H
# define DLLIST_H

typedef struct dllist_node
{
	struct dllist_node	*next;
	struct dllist_node	*prev;
	int					val;
}				t_dllist_node;

typedef struct dllist
{
	t_dllist_node	*sentinel_node;
	unsigned int	total_nodes;
	unsigned int	biggest_number;
}				t_dllist;

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

#endif
