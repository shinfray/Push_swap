/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 09:41:12 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/20 09:49:29 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// #include "ft_printf.h"
// #include <stdio.h>
// void	ft_print_stack(t_dllist *stack_a, t_dllist *stack_b)
// {
// 	t_dllist_node	*temp_a;
// 	t_dllist_node	*temp_b;

// 	temp_a = ft_dllist_first(stack_a);
// 	temp_b = ft_dllist_first(stack_b);
// 	ft_printf("stack a:\n");
// 	while (temp_a != stack_a->sentinel_node)
// 	{
// 		ft_printf("%d\n", temp_a->val);
// 		temp_a = ft_dllist_next(temp_a);
// 	}
// 	ft_printf("stack b:\n");
// 	while (temp_b != stack_b->sentinel_node)
// 	{
// 		ft_printf("%d\n", temp_b->val);
// 		temp_b = ft_dllist_next(temp_b);
// 	}
// }

int	main(int argc, char **argv)
{
	t_dllist	*stack_a;
	t_dllist	*stack_b;
	char		**args_list;
	int			exit_status;

	if (argc < 2 || ft_initialize_stacks(&stack_a, &stack_b) == -1)
		return (ft_exit_push_swap(EXIT_FAILURE));
	args_list = ft_check_args_format(argc, argv);
	if (ft_retrieve_args(stack_a, args_list) != NULL)
	{
		//sort
		exit_status = EXIT_SUCCESS;
	}
	else
		exit_status = EXIT_FAILURE;
	ft_free_stacks(stack_a, stack_b);
	if (args_list != NULL && args_list != argv + 1)
		ft_free_args_list(args_list);
	return (ft_exit_push_swap(exit_status));
}
