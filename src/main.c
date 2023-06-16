/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:05:55 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/16 16:05:45 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_initialize_stacks(t_dllist **stack_a, t_dllist **stack_b);
static void		ft_print_stack(t_dllist *stack_a, t_dllist *stack_b);

int	main(int argc, char **argv)
{
	t_dllist	*stack_a;
	t_dllist	*stack_b;

	if (argc < 2)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		exit(2);
	}
	ft_initialize_stacks(&stack_a, &stack_b);
	if (ft_retrieve_args(stack_a, argc, argv) == NULL)
	{
		ft_free_dllist(stack_a);
		ft_free_dllist(stack_b);
		ft_putendl_fd("Error", STDERR_FILENO);
		exit(3);
	}

	ft_print_stack(stack_a, stack_b);

	return (0);
}

static void	ft_print_stack(t_dllist *stack_a, t_dllist *stack_b)
{
	t_dllist_node	*temp_a;
	t_dllist_node	*temp_b;

	temp_a = ft_dllist_first(stack_a);
	temp_b = ft_dllist_first(stack_b);
	printf("stack a:\n");
	while (temp_a != stack_a->sentinel_node)
	{
		printf("%d\n", temp_a->val);
		temp_a = ft_dllist_next(temp_a);
	}
	printf("stack b:\n");
	while (temp_b != stack_b->sentinel_node)
	{
		printf("%d\n", temp_b->val);
		temp_b = ft_dllist_next(temp_b);
	}
}

static void	ft_initialize_stacks(t_dllist **stack_a, t_dllist **stack_b)
{
	*stack_a = ft_new_dllist();
	if (*stack_a == NULL)
		exit(4);
	*stack_b = ft_new_dllist();
	if (*stack_b == NULL)
	{
		ft_free_dllist(*stack_a);
		exit(5);
	}
}
