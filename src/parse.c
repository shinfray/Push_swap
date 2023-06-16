/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:04:24 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/16 16:24:12 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dllist	*ft_retrieve_args(t_dllist *dllist, int argc, char **argv);
int			ft_atoi_ps(const char *str, bool *error_status);
bool		ft_is_duplicate_number(t_dllist *dllist, int n);

t_dllist	*ft_retrieve_args(t_dllist *dllist, int argc, char **argv)
{
	bool	status_ft_atoi_ps;
	int		temp;
	int		i;
	
	i = 1;
	while (argc-- > 1)
	{
		temp = ft_atoi_ps(argv[i++], &status_ft_atoi_ps);
		if (status_ft_atoi_ps == EXIT_FAILURE \
			|| ft_is_duplicate_number(dllist, temp) == true \
			|| ft_dllist_append(dllist, temp) == NULL)
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
