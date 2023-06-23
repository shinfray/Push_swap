/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 00:58:15 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/24 00:59:05 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_qsort(int *array, ssize_t start, ssize_t end);
static ssize_t	ft_partition(int *array, ssize_t start, ssize_t end);

void	ft_qsort(int *array, ssize_t start, ssize_t end)
{
	ssize_t	pivot;

	if (end <= start)
		return ;
	pivot = ft_partition(array, start, end);
	ft_qsort(array, start, pivot - 1);
	ft_qsort(array, pivot + 1, end);
}

static ssize_t	ft_partition(int *array, ssize_t start, ssize_t end)
{
	ssize_t	i;
	ssize_t	j;
	int		pivot;
	int		temp;

	pivot = array[end];
	i = start - 1;
	j = start;
	while (j <= end - 1)
	{
		if (array[j] < pivot)
		{
			++i;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
		++j;
	}
	++i;
	temp = array[i];
	array[i] = array[end];
	array[end] = temp;
	return (i);
}
