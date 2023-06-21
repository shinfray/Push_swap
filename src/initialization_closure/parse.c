/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:04:24 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/21 20:57:14 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char				**ft_check_args_format(int argc, char **argv);
t_dllist			*ft_retrieve_args(t_dllist *dllist, char **args_list);
static int			ft_atoi_push_swap(const char *str, bool *error_status);
static bool			ft_is_duplicate_number(t_dllist *dllist, int n);
static unsigned int	ft_abs(int number);

char	**ft_check_args_format(int argc, char **argv)
{
	char		**args_list;

	if (argc == 2)
	{
		args_list = ft_split(argv[1], ' ');
		if (args_list == NULL)
			return (NULL);
	}
	else
		args_list = argv + 1;
	return (args_list);
}

t_dllist	*ft_retrieve_args(t_dllist *dllist, char **args_list)
{
	bool	status_ft_atoi_push_swap;
	int		temp;

	if (args_list == NULL || *args_list == NULL)
		return (NULL);
	while (*args_list != NULL)
	{
		temp = ft_atoi_push_swap(*args_list++, &status_ft_atoi_push_swap);
		if (status_ft_atoi_push_swap == EXIT_FAILURE \
			|| ft_is_duplicate_number(dllist, temp) == true \
			|| ft_dllist_append(dllist, temp) == NULL)
			return (NULL);
		dllist->total_nodes++;
		if (ft_abs(ft_dllist_last(dllist)->val) > dllist->biggest_abs_number)
			dllist->biggest_abs_number = ft_abs(ft_dllist_last(dllist)->val);
	}
	return (dllist);
}

int	ft_atoi_push_swap(const char *str, bool *error_status)
{
	long int	n;
	int			sign;
	const char	*save;

	n = 0;
	sign = 1;
	save = str;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while (ft_isdigit(*str) != 0)
	{
		n = n * 10 + *str - '0';
		if (n > (long int)INT_MAX + 1)
			break ;
		++str;
	}
	n *= sign;
	if (*str == '\0' && save != str && n >= INT_MIN && n <= INT_MAX)
		*error_status = EXIT_SUCCESS;
	else
		*error_status = EXIT_FAILURE;
	return ((int)n);
}

bool	ft_is_duplicate_number(t_dllist *dllist, int n)
{
	t_dllist_node	*temp;

	if (ft_dllist_is_empty(dllist) == true)
		return (false);
	temp = ft_dllist_first(dllist);
	while (temp != dllist->sentinel_node)
	{
		if (temp->val == n)
			return (true);
		temp = ft_dllist_next(temp);
	}
	return (false);
}

static unsigned int	ft_abs(int number)
{
	if (number < 0)
		return (-number);
	return (number);
}
