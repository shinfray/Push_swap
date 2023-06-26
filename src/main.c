/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 09:41:12 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/26 13:39:25 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	s_stacks;
	char		**nums;
	int			exit_status;

	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
		return (EXIT_SUCCESS);
	if (ft_initialize_stacks(&s_stacks) == -1)
		return (ft_exit_push_swap(EXIT_FAILURE));
	nums = ft_check_args_format(argc, argv);
	if (ft_retrieve_args(s_stacks.stack_a, nums) != NULL)
	{
		ft_sort(&s_stacks);
		exit_status = EXIT_SUCCESS;
	}
	else
		exit_status = EXIT_FAILURE;
	ft_free_push_swap(&s_stacks, nums, argv);
	return (ft_exit_push_swap(exit_status));
}
