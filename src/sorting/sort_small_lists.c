/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_lists.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:50:56 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/23 18:56:06 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_list_up_to_3(t_dllist *stack_a);
void	ft_sort_list_up_to_5(t_dllist *stack_a, t_dllist *stack_b);

void	ft_sort_list_up_to_3(t_dllist *stack_a)
{
	int	a;
	int	b;
	int	c;

	a = ft_dllist_first(stack_a)->val;
	b = ft_dllist_next(ft_dllist_first(stack_a))->val;
	c = ft_dllist_last(stack_a)->val;
	if (stack_a->total_nodes == 2)
		ft_sa(stack_a, NULL);
	else if (a > b && b < c && c < a)
		ft_ra(stack_a, NULL);
	else if (a < b && b > c && c < a)
		ft_rra(stack_a, NULL);
	else
	{
		ft_sa(stack_a, NULL);
		if (ft_stack_is_sorted(stack_a) == true)
			return ;
		a = ft_dllist_first(stack_a)->val;
		b = ft_dllist_next(ft_dllist_first(stack_a))->val;
		if (a > b)
			ft_ra(stack_a, NULL);
		else
			ft_rra(stack_a, NULL);
	}
}

// void	ft_sort_list_up_to_5(t_dllist *stack_a, t_dllist *stack_b)
// {
// 	while (stack_a->total_nodes > 3)
// 		ft_pb(stack_a, stack_b);
// 	if (ft_stack_is_sorted(stack_a) == false)
// 		ft_sort_list_up_to_3(stack_a);
// 	while (ft_dllist_is_empty(stack_b) == false)
// 	{
// 		if (ft_dllist_first(stack_b)->val < ft_dllist_first(stack_a)->val)
// 			ft_pa(stack_a, stack_b);
// 		else if (ft_dllist_first(stack_b)->val > ft_dllist_last(stack_a)->val)
// 		{
// 			ft_pa(stack_a, stack_b);
// 			ft_ra(stack_a, stack_b);
// 		}
// 		else
// 		{
// 			while (ft_dllist_first(stack_b)->val \
// 					> ft_dllist_first(stack_a)->val)
// 				ft_ra(stack_a, stack_b);
// 			ft_pa(stack_a, stack_b);
// 			while (ft_stack_is_sorted(stack_a) == false)
// 				ft_rra(stack_a, stack_b);
// 		}
// 	}
// }

static int	ft_get_min_value(t_dllist *stack_a)
{
	t_dllist_node	*current_node;
	int	min;

	min = 0;
	current_node = ft_dllist_first(stack_a);
	while (current_node != stack_a->sentinel_node)
	{
		if (min > current_node->val)
			min = current_node->val;
		current_node = ft_dllist_next(current_node);
	}
	return (min);
}

static int	ft_get_max_value(t_dllist *stack_a)
{
	t_dllist_node	*current_node;
	int	max;

	max = 0;
	current_node = ft_dllist_first(stack_a);
	while (current_node != stack_a->sentinel_node)
	{
		if (max > current_node->val)
			max = current_node->val;
		current_node = ft_dllist_next(current_node);
	}
	return (max);
}

unsigned int	ft_get_value_index(t_dllist *stack, int n)
{
	t_dllist_node	*current_node;
	unsigned int	i;

	current_node = ft_dllist_first(stack);
	i = 0;
	while (current_node->val != n)
	{
		current_node = ft_dllist_next(current_node);
		++i;
	}
	return (i);
}

unsigned int	ft_get_desired_index_in_stack_a(t_dllist *stack_a, int n)
{
	int		min_value;
	int		max_value;
	int		i;
	t_list	*temp;

	if (n < ft_dllist_first(stack_a)->val && n > ft_dllist_last(stack_a)->val)
		return (0);
	min_value = ft_get_min_value(stack_a);
	max_value = ft_get_max_value(stack_a);
	if (n > max_value || n < min_value)
		return (ft_get_value_index(stack_a, min_value));
	//here!
	i = ft_get_value_index(s);
	tmp = ft_lstget_nth(a, i);
	while (tmp && n > tmp->value)
	{
		++i;
		tmp = tmp->next;
	}
	if (!tmp)
		return (sub_go_to_a_at(n, a));
	return (i);	




}

void	ft_sort_list_up_to_5(t_dllist *stack_a, t_dllist *stack_b)
{
	while (stack_a->total_nodes > 3)
		ft_pb(stack_a, stack_b);
	if (ft_stack_is_sorted(stack_a) == false)
		ft_sort_list_up_to_3(stack_a);


	while (ft_dllist_is_empty(stack_b) == false)
	{
		//get index goal of the top stack b to stack a;
		
		// calculate if ra or rra;

		// push to a;

	}
	//roll the stack to get min on thop;
}
