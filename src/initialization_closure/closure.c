/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closure.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:36:29 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/20 09:41:40 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_exit_push_swap(int exit_status);
void	ft_free_stacks(t_dllist *stack_a, t_dllist *stack_b);
void	ft_free_args_list(char **args_list);

int	ft_exit_push_swap(int exit_status)
{
	if (exit_status == EXIT_FAILURE)
		ft_putendl_fd("Error", STDERR_FILENO);
	return (exit_status);
}

void	ft_free_stacks(t_dllist *stack_a, t_dllist *stack_b)
{
	ft_free_dllist(stack_a);
	ft_free_dllist(stack_b);
}

void	ft_free_args_list(char **args_list)
{
	char	**save;

	save = args_list;
	while (*args_list != NULL)
		free(*args_list++);
	free(save);
}
