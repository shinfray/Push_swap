/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closure.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:36:29 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/17 15:40:12 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_exit_on_error(void);
void	ft_free_stacks(t_dllist *stack_a, t_dllist *stack_b);

int	ft_exit_on_error(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	return (EXIT_FAILURE);
}

void	ft_free_stacks(t_dllist *stack_a, t_dllist *stack_b)
{
	ft_free_dllist(stack_a);
	ft_free_dllist(stack_b);
}
