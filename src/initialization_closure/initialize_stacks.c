/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:28:30 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/17 15:39:41 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_initialize_stacks(t_dllist **stack_a, t_dllist **stack_b);

int	ft_initialize_stacks(t_dllist **stack_a, t_dllist **stack_b)
{
	*stack_a = ft_new_dllist();
	if (*stack_a == NULL)
		return (-1);
	*stack_b = ft_new_dllist();
	if (*stack_b == NULL)
	{
		ft_free_dllist(*stack_a);
		return (-1);
	}
	return (0);
}
