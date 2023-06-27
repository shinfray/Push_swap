/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 23:51:46 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/27 10:01:51 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int			ft_get_moves(t_dllist *stack_a, t_dllist *stack_b);
void		ft_print_result(t_stacks *stacks);
static int	ft_get_move_index(char *move);
static void	ft_exec_move(int index_move, t_dllist *stack_a, t_dllist *stack_b);

int	ft_get_moves(t_dllist *stack_a, t_dllist *stack_b)
{
	char		*move;
	int			move_index;

	if (ft_dllist_is_empty(stack_a) == true)
		return (0);
	move = get_next_line(STDIN_FILENO);
	while (move != NULL)
	{
		move_index = ft_get_move_index(move);
		free(move);
		if (move_index == -1)
			return (-1);
		ft_exec_move(move_index, stack_a, stack_b);
		move = get_next_line(STDIN_FILENO);
	}
	return (0);
}

void	ft_print_result(t_stacks *stacks)
{
	if (ft_dllist_is_empty(stacks->stack_b) == true \
		&& ft_stack_is_sorted(stacks->stack_a) == true)
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
}

static int	ft_get_move_index(char *move)
{
	const char	*legal_moves[12] = {"sa\n", "sb\n", "ss\n", "pa\n", \
									"pb\n", "ra\n", "rb\n", "rr\n", \
									"rra\n", "rrb\n", "rrr\n", NULL};
	int			i;

	i = 0;
	while (legal_moves[i] != NULL && ft_strncmp(move, legal_moves[i], 4) != 0)
		++i;
	if (legal_moves[i] == NULL)
		return (-1);
	return (i);
}

static void	ft_exec_move(int index_move, t_dllist *stack_a, t_dllist *stack_b)
{
	void	(*fun[11])(t_dllist *stack_a, t_dllist *stack_b);

	(fun[0]) = &ft_sa_s;
	(fun[1]) = &ft_sb_s;
	(fun[2]) = &ft_ss_s;
	(fun[3]) = &ft_pa_s;
	(fun[4]) = &ft_pb_s;
	(fun[5]) = &ft_ra_s;
	(fun[6]) = &ft_rb_s;
	(fun[7]) = &ft_rr_s;
	(fun[8]) = &ft_rra_s;
	(fun[9]) = &ft_rrb_s;
	(fun[10]) = &ft_rrr_s;
	(fun[index_move])(stack_a, stack_b);
}
