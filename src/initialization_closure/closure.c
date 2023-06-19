/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closure.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:36:29 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/19 18:46:52 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_exit_on_error(void);
void	ft_free_stacks(t_dllist *stack_a, t_dllist *stack_b);
void	ft_free_args_list(char **args_list);

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

void	ft_free_args_list(char **args_list)
{
	char	**save;

	save = args_list;
	while (*args_list != NULL)
		free(*args_list++);
	free(save);
}

// void	ft_free_push_swap(t_dllist *stack_a, t_dllist *stack_b, char **args_list, int argc)
// {
// 		ft_free_stacks(stack_a, stack_b);
// 		if (args_list != NULL && argc == 2)
// 			ft_free_args_list(args_list);
// }
