/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:05:55 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/17 15:37:16 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	if (argc < 2 || ft_initialize_stacks(&stack_a, &stack_b) == -1)
		return (ft_exit_on_error());
	if (ft_retrieve_args(stack_a, argc, argv) == NULL)
	{
		ft_free_stacks(stack_a, stack_b);
		return (ft_exit_on_error());
	}
	ft_free_stacks(stack_a, stack_b);
	return (0);
}
