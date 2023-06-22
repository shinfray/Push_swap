/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:03:09 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/22 18:50:43 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool			ft_stack_is_sorted(t_dllist *stack_a);
void			ft_qsort(int *array, ssize_t start, ssize_t end);
static ssize_t	ft_partition(int *array, ssize_t start, ssize_t end);

bool	ft_stack_is_sorted(t_dllist *stack_a)
{
	t_dllist_node	*current_node;
	t_dllist_node	*next_node;

	current_node = ft_dllist_first(stack_a);
	next_node = ft_dllist_next(current_node);
	while (next_node != stack_a->sentinel_node)
	{
		if (current_node->val > next_node->val)
			return (false);
		current_node = next_node;
		next_node = ft_dllist_next(current_node);
	}
	return (true);
}

void	ft_qsort(int *array, ssize_t start, ssize_t end)
{
	ssize_t	pivot;

	if (end <= start)
		return ;
	pivot = ft_partition(array, start, end);
	ft_qsort(array, start, pivot - 1);
	ft_qsort(array, pivot + 1, end);
}

static ssize_t	ft_partition(int *array, ssize_t start, ssize_t end)
{
	ssize_t	i;
	ssize_t	j;
	int		pivot;
	int		temp;

	pivot = array[end];
	i = start - 1;
	j = start;
	while (j <= end - 1)
	{
		if (array[j] < pivot)
		{
			++i;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
		++j;
	}
	++i;
	temp = array[i];
	array[i] = array[end];
	array[end] = temp;
	return (i);
}
