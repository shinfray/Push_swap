/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 19:59:09 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/21 20:33:34 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_radix_sort(t_dllist *stack_a, t_dllist *stack_b);
static void	ft_sort_digit(t_dllist *stack_a, t_dllist *stack_b, int bitshift, int neg_pos_num);
static int	ft_width(unsigned int number);

void	ft_radix_sort(t_dllist *stack_a, t_dllist *stack_b)
{
	const int	width = ft_width(stack_a->biggest_number);
	int			current_bit;
	int			neg_pos_num;

	current_bit = 0;
	neg_pos_num = 1;
	while (current_bit <= width)
	{
		if (current_bit == width)
			neg_pos_num = 0;
		ft_sort_digit(stack_a, stack_b, current_bit++, neg_pos_num);
	}
}

static void	ft_sort_digit(t_dllist *stack_a, t_dllist *stack_b, int bitshift, int neg_pos_num)
{
	size_t	total_number = stack_a->total_nodes;

	while (total_number--)
	{
		if ((((ft_dllist_first(stack_a)->val) >> bitshift) & 1) == neg_pos_num)
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
 *	because we don't need more than that.
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
