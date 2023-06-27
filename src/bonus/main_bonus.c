/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:07:25 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/27 10:07:26 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char **argv)
{
	t_stacks	s_stacks;
	char		**nums;
	int			exit_status;

	if (argc < 2)
		return (EXIT_SUCCESS);
	if (ft_initialize_stacks(&s_stacks) == -1)
		return (ft_exit_push_swap(EXIT_FAILURE));
	nums = ft_check_args_format(argc, argv);
	if (ft_retrieve_args(s_stacks.stack_a, nums) != NULL \
		&& ft_get_moves(s_stacks.stack_a, s_stacks.stack_b) == 0)
		exit_status = EXIT_SUCCESS;
	else
		exit_status = EXIT_FAILURE;
	if (exit_status == EXIT_SUCCESS \
		&& ft_dllist_is_empty(s_stacks.stack_a) == false)
		ft_print_result(&s_stacks);
	ft_free_push_swap(&s_stacks, nums, argv);
	return (ft_exit_push_swap(exit_status));
}
