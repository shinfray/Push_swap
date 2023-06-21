/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closure.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:36:29 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/21 22:09:44 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_free_push_swap(t_stacks *stacks, char **nums, char **argv);
int			ft_exit_push_swap(int exit_status);
static void	ft_free_stacks(t_stacks *stacks);
static void	ft_free_nums(char **nums);

void	ft_free_push_swap(t_stacks *stacks, char **nums, char **argv)
{
	ft_free_stacks(stacks);
	if (nums != NULL && nums != argv + 1)
		ft_free_nums(nums);
}

int	ft_exit_push_swap(int exit_status)
{
	if (exit_status == EXIT_FAILURE)
		ft_putendl_fd("Error", STDERR_FILENO);
	return (exit_status);
}

static void	ft_free_stacks(t_stacks *stacks)
{
	ft_free_dllist(stacks->stack_a);
	ft_free_dllist(stacks->stack_b);
}

static void	ft_free_nums(char **nums)
{
	char	**save;

	save = nums;
	while (*nums != NULL)
		free(*nums++);
	free(save);
}
