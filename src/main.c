/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:05:55 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/17 15:23:00 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_initialize_stacks(t_dllist **stack_a, t_dllist **stack_b);
static int	ft_exit_on_error(void);
static void	ft_free_stacks(t_dllist *stack_a, t_dllist *stack_b);

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

static int	ft_initialize_stacks(t_dllist **stack_a, t_dllist **stack_b)
{
	*stack_a = ft_new_dllist();
	if (*stack_a == NULL)
		return (-1);
	*stack_b = ft_new_dllist();
	if (*stack_b == NULL)
	{
		ft_free_dllist(*stack_a);
		return (-1);
	}
	return (0);
}

static int	ft_exit_on_error(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	return (EXIT_FAILURE);
}

static void	ft_free_stacks(t_dllist *stack_a, t_dllist *stack_b)
{
	ft_free_dllist(stack_a);
	ft_free_dllist(stack_b);
}
