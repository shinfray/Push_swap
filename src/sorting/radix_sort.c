/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 22:12:05 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/22 16:00:44 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_radix_sort(t_stacks *stacks);
static void	ft_sort_bit_x(t_stacks *s_stacks, int bitshift, int neg_pos_num);
static int	ft_width(unsigned int number);


#include <stdio.h>
int comparator (const void * p1, const void * p2)
{
  return (*(int*)p1 - *(int*)p2);
}

/*
 *	In this function, the variable number_sign is set to 0 only when all
 *	the significants bits have been sorted,
 *	in order to place the negatives numbers before the positives numbers
 *	(the non significant bits of negative numbers are filled with 1s, not 0s).
*/
void	ft_radix_sort(t_stacks *stacks)
{
	const int	width = ft_width(stacks->stack_a->biggest_abs_number);
	int			current_bit;
	int			number_sign;

	size_t			i;
	int			*new_stack;
	t_dllist_node	*current_node;


	new_stack = ft_calloc(stacks->stack_a->total_nodes, sizeof(*new_stack));
	// if !new_stack ---> exit error;
	i = 0;
	current_node = ft_dllist_first(stacks->stack_a);
	while (current_node != stacks->stack_a->sentinel_node)
	{
		new_stack[i++] = current_node->val;
		current_node = ft_dllist_next(current_node);
	}
	qsort(new_stack, stacks->stack_a->total_nodes, sizeof(*new_stack), comparator);
	i = 0;
	while (i < stacks->stack_a->total_nodes)
		printf("array: %d\n", new_stack[i++]);
	free(new_stack);

	current_bit = 0;
	number_sign = 1;
	while (current_bit <= width)
	{
		if (current_bit == width)
			number_sign = 0;
		ft_sort_bit_x(stacks, current_bit++, number_sign);
	}
}

static void	ft_sort_bit_x(t_stacks *s_stacks, int bit, int number_sign)
{
	t_dllist	*stack_a;
	t_dllist	*stack_b;
	size_t		nodes_count_stack_a;

	stack_a = s_stacks->stack_a;
	stack_b = s_stacks->stack_b;
	nodes_count_stack_a = stack_a->total_nodes;
	while (nodes_count_stack_a--)
	{
		if ((((ft_dllist_first(stack_a)->val) >> bit) & 1) == number_sign)
			ft_ra(stack_a, stack_b);
		else
			ft_pb(stack_a, stack_b);
	}
	while (ft_dllist_is_empty(stack_b) == false)
		ft_pa(stack_a, stack_b);
}

/*
 *	special case:
 *	this function return 31 when number is 1 bigger than INT_MAX,
 *	because we don't need more than that for radix_sort.
*/
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
