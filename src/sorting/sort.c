/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:15:58 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/22 14:23:34 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_sort(t_stacks *stacks)
{
    if (ft_stack_is_sorted(stacks->stack_a) == true)
        return ;
    if (stacks->stack_a->total_nodes <= 5)
        ft_sort_list_up_to_5(stacks->stack_a, stacks->stack_b);
    else
        ft_radix_sort(stacks);
}
