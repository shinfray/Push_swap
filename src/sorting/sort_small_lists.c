/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_lists.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:50:56 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/24 18:55:08 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				ft_sort(t_dllist *stack_a, t_dllist *stack_b);
void				ft_sort_list_up_to_3(t_dllist *stack_a);
static unsigned int	ft_get_desired_index_to_a(t_dllist *stack, int n);
static unsigned int	ft_get_desired_index_to_b(t_dllist *stack, int n);
static unsigned int	ft_get_value_index(t_dllist *stack, int n);
static void			ft_do_ra_or_rra(t_dllist *stack, unsigned int i);




static unsigned int	ft_max(unsigned int a, unsigned int b)
{
	if (a > b)
		return (a);
	return (b);
}

static void	ft_apply_r_rr(t_choice *choice, unsigned int index_a, unsigned int index_b, unsigned int steps)
{
	choice->steps = steps;
	choice->from = index_a;
	choice->to = index_b;
	//choice->fun = 
}

static void	ft_apply_rr_rrr(t_choice *choice, unsigned int index_a, unsigned int index_b, unsigned int steps)
{
	choice->steps = steps;
	choice->from = index_a;
	choice->to = index_b;
	//choice->fun = 
}

static void	ft_apply_ra_rrb(t_choice *choice, unsigned int index_a, unsigned int index_b, unsigned int steps)
{
	choice->steps = steps;
	choice->from = index_a;
	choice->to = index_b;
	//choice->fun = 
}

static void	ft_apply_rra_rb(t_choice *choice, unsigned int index_a, unsigned int index_b, unsigned int steps)
{
	choice->steps = steps;
	choice->from = index_a;
	choice->to = index_b;
	//choice->fun = 
}

static void	ft_choose_a_and_b(t_dllist *stack_a, t_dllist *stack_b, t_choice *choice)
{
	t_dllist_node	*current_node;
	unsigned int	steps;
	unsigned int	index_a;
	unsigned int	index_b;

	index_a = 0;
	choice->steps = -1;
	current_node = ft_dllist_first(stack_a);
	while (current_node != stack_a->sentinel_node)
	{
		index_b = ft_get_desired_index_to_b(stack_b, current_node->val);
		if (choice->steps == -1 || steps > ft_max(index_a, index_b))
			ft_apply_r_rr(choice, index_a, index_b, steps);
		if (choice->steps > ft_max(stack_a->total_nodes - index_a, stack_b->total_nodes - index_b))
			ft_apply_rr_rrr(choice, index_a, index_b, steps);
		if (choice->steps > index_a + stack_b->total_nodes - index_b)
			ft_apply_ra_rrb(choice, index_a, index_b, steps);
		if (choice->steps > index_b + stack_a->total_nodes - index_a)
			ft_apply_rra_rb(choice, index_a, index_b, steps);
		current_node = ft_dllist_next(current_node);
		++index_a;
	}
}


void	ft_sort(t_dllist *stack_a, t_dllist *stack_b)
{
	t_choice		s_choice;
	unsigned int	i;
	int				min_value;

	if (ft_stack_is_sorted(stack_a) == true)
		return ;
	while (stack_a->total_nodes > 3)
	{
		//check best a and best place, fill the t_choice (arg : stacka, stackb, &s_choice)
		s_choice.fun(stack_a, stack_b, s_choice.from, s_choice.to);
		ft_pb(stack_a, stack_b);
	}
	if (ft_stack_is_sorted(stack_a) == false)
		ft_sort_list_up_to_3(stack_a);
	while (ft_dllist_is_empty(stack_b) == false)
	{
		i = ft_get_desired_index_to_a(stack_a, ft_dllist_first(stack_b)->val);
		ft_do_ra_or_rra(stack_a, i);
		ft_pa(stack_a, stack_b);
	}
	if (ft_stack_is_sorted(stack_a) == true)
		return ;
	min_value = ft_get_min_value(stack_a);
	i = ft_get_value_index(stack_a, min_value);
	ft_do_ra_or_rra(stack_a, i);
}

void	ft_sort_list_up_to_3(t_dllist *stack_a)
{
	const int	min_value = ft_get_min_value(stack_a);
	const int	max_value = ft_get_max_value(stack_a);

	if (ft_dllist_first(stack_a)->val == max_value)
		ft_ra(stack_a);
	if (stack_a->total_nodes != 3 || ft_stack_is_sorted(stack_a) == true)
		return ;
	if (ft_dllist_next(ft_dllist_first(stack_a))->val == max_value)
		ft_rra(stack_a);
	if (ft_dllist_next(ft_dllist_first(stack_a))->val == min_value)
		ft_sa(stack_a);
}

static unsigned int	ft_get_desired_index_to_a(t_dllist *stack, int n)
{
	t_dllist_node	*temp;
	int				min_value;
	unsigned int	i;

	if (n < ft_dllist_first(stack)->val && n > ft_dllist_last(stack)->val)
		return (0);
	min_value = ft_get_min_value(stack);
	i = ft_get_value_index(stack, min_value);
	if (n > ft_get_max_value(stack) || n < min_value)
		return (i);
	temp = ft_dllist_first(stack);
	while (temp->val != min_value)
		temp = ft_dllist_next(temp);
	while (n > temp->val)
	{
		++i;
		temp = ft_dllist_next(temp);
		if (temp == stack->sentinel_node)
		{
			temp = ft_dllist_first(stack);
			i = 0;
		}
	}
	return (i);
}

static unsigned int	ft_get_desired_index_to_b(t_dllist *stack, int n)
{
	t_dllist_node	*temp;
	int				max_value;
	unsigned int	i;

	if (n > ft_dllist_first(stack)->val && n < ft_dllist_last(stack)->val)
		return (0);
	max_value = ft_get_max_value(stack);
	i = ft_get_value_index(stack, max_value);
	if (n < ft_get_min_value(stack) || n > max_value)
		return (i);
	temp = ft_dllist_first(stack);
	while (temp->val != max_value)
		temp = ft_dllist_next(temp);
	while (n < temp->val)
	{
		++i;
		temp = ft_dllist_next(temp);
		if (temp == stack->sentinel_node)
		{
			temp = ft_dllist_first(stack);
			i = 0;
		}
	}
	return (i);
}

static unsigned int	ft_get_value_index(t_dllist *stack, int n)
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

static void	ft_do_ra_or_rra(t_dllist *stack, unsigned int i)
{
	if (i <= stack->total_nodes / 2)
		while (i-- > 0)
			ft_ra(stack);
	else
		while (i++ < stack->total_nodes)
			ft_rra(stack);
}
