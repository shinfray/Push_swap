/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:04:18 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/22 18:50:23 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_radix_sort(t_stacks *stacks);
static void	ft_fill_temp_array(t_dllist *stack_a, int *temp_array);
static void	ft_fill_array_with_index(t_dllist *stack_a, int *temp_array);
static void	ft_sort_bit_x(t_stacks *s_stacks, int bit);
static int	ft_width(unsigned int number);

// #include <stdio.h>
// int	ft_comparator(const void *p1, const void *p2)
// {
// 	return (*(int *)p1 - *(int *)p2);
// }
// qsort(temp_array, stacks->stack_a->total_nodes, sizeof(*temp_array),
//ft_comparator);

int	ft_radix_sort(t_stacks *stacks)
{
	int	*temp_array;
	int	width;
	int	current_bit;

	temp_array = ft_calloc(stacks->stack_a->total_nodes, sizeof(*temp_array));
	if (temp_array == NULL)
		return (-1);
	ft_fill_temp_array(stacks->stack_a, temp_array);
	ft_qsort(temp_array, 0, (ssize_t)(stacks->stack_a->total_nodes - 1));
	ft_fill_array_with_index(stacks->stack_a, temp_array);
	free(temp_array);
	width = ft_width(stacks->stack_a->biggest_number);
	current_bit = 0;
	while (current_bit < width)
		ft_sort_bit_x(stacks, current_bit++);
	return (0);
}

static void	ft_fill_temp_array(t_dllist *stack_a, int *temp_array)
{
	t_dllist_node	*current_node;

	current_node = ft_dllist_first(stack_a);
	while (current_node != stack_a->sentinel_node)
	{
		*temp_array++ = current_node->val;
		current_node = ft_dllist_next(current_node);
	}
}

static void	ft_fill_array_with_index(t_dllist *stack_a, int *temp_array)
{
	t_dllist_node	*current_node;
	unsigned int	i;

	current_node = ft_dllist_first(stack_a);
	while (current_node != stack_a->sentinel_node)
	{
		i = 0;
		while (i < stack_a->total_nodes)
		{
			if (current_node->val == temp_array[i])
			{
				current_node->val = (int)i;
				if (stack_a->biggest_number < i)
					stack_a->biggest_number = i;
			}
			++i;
		}
		current_node = ft_dllist_next(current_node);
	}
}

static void	ft_sort_bit_x(t_stacks *s_stacks, int bit)
{
	t_dllist	*stack_a;
	t_dllist	*stack_b;
	size_t		nodes_count_stack_a;

	stack_a = s_stacks->stack_a;
	stack_b = s_stacks->stack_b;
	nodes_count_stack_a = stack_a->total_nodes;
	while (nodes_count_stack_a--)
	{
		if (((((unsigned int)ft_dllist_first(stack_a)->val) >> bit) & 1) == 1)
			ft_ra(stack_a, stack_b);
		else
			ft_pb(stack_a, stack_b);
	}
	while (ft_dllist_is_empty(stack_b) == false)
		ft_pa(stack_a, stack_b);
}

static int	ft_width(unsigned int number)
{
	int	count;

	if (number > INT_MAX)
		return (31);
	count = 0;
	while (number != 0)
	{
		number >>= 1;
		count++;
	}
	return (count);
}
