/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:05:55 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/16 02:04:49 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <limits.h>

static void	ft_initialize_stacks(t_dllist **stack_a, t_dllist **stack_b);
static t_dllist	*ft_retrieve_args(t_dllist *dllist, int argc, char **argv);
int	ft_atoi_ps(const char *str, bool *error_status);

int	main(int argc, char **argv)
{
	t_dllist	*stack_a;
	t_dllist	*stack_b;
	t_dllist_node	*temp;

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
		exit(3);
	}
	temp = ft_dllist_first(stack_a);
	while (temp != stack_a->sentinel_node)
	{
		printf("%d\n", temp->val);
		temp = ft_dllist_next(temp);
	}
	return (0);
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

static t_dllist	*ft_retrieve_args(t_dllist *dllist, int argc, char **argv)
{
	bool	status_ft_atoi_ps;
	int		temp;
	int		i;
	
	i = 1;
	while (argc-- > 1)
	{
		temp = ft_atoi_ps(argv[i++], &status_ft_atoi_ps);
		if (status_ft_atoi_ps == EXIT_FAILURE || ft_dllist_append(dllist, temp) == NULL)
			return (NULL);
	}
	return (dllist);
}

int	ft_atoi_ps(const char *str, bool *error_status)
{
	long int		n;
	int				sign;

	n = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while (ft_isdigit(*str) != 0)
	{
		n = n * 10 + *str - '0';
		if (n > (long int)INT_MAX + 1)
			break;
		++str;
	}
	n *= sign;
	if (*str == '\0' && n >= INT_MIN && n <= INT_MAX)
		*error_status = EXIT_SUCCESS;
	else
		*error_status = EXIT_FAILURE;
	return (n);
}
