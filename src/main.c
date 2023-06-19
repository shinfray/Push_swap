/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:05:55 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/19 18:05:57by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// #include "ft_printf.h"
// static void	ft_print_stack(t_dllist *stack_a, t_dllist *stack_b)
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

	if (argc < 2 || ft_initialize_stacks(&stack_a, &stack_b) == -1)
		return (ft_exit_on_error());
	args_list = ft_check_args_format(argc, argv);
	if (args_list == NULL || ft_retrieve_args(stack_a, args_list) == NULL)
	{
		ft_free_stacks(stack_a, stack_b);
		if (args_list != NULL && argc == 2)
			ft_free_args_list(args_list);
		return (ft_exit_on_error());
	}
	//sort
	ft_free_stacks(stack_a, stack_b);
	if (argc == 2)
		ft_free_args_list(args_list);
	return (EXIT_SUCCESS);
}
