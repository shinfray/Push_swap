/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:28:30 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/21 21:35:04 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_initialize_stacks(t_stacks *stacks);

int	ft_initialize_stacks(t_stacks *stacks)
{
	stacks->stack_a = ft_new_dllist();
	if (stacks->stack_a == NULL)
		return (-1);
	stacks->stack_b = ft_new_dllist();
	if (stacks->stack_b == NULL)
	{
		ft_free_dllist(stacks->stack_a);
		return (-1);
	}
	return (0);
}
