/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:44:12 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/26 19:20:07 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int		ft_get_moves(t_dllist *stack_a, t_dllist *stack_b);
int		ft_get_move_index(char *move);
void	ft_execute_move(int index_move, t_dllist *stack_a, t_dllist *stack_b);

int	main(int argc, char **argv)
{
	t_stacks	s_stacks;
	char		**nums;
	int			exit_status;

	if (argc < 2)
		return (EXIT_SUCCESS);
	if (ft_initialize_stacks(&s_stacks) == -1)
		return (ft_exit_push_swap(EXIT_FAILURE));
	nums = ft_check_args_format(argc, argv);
	if (ft_retrieve_args(s_stacks.stack_a, nums) != NULL)
	{
		if (ft_get_moves(s_stacks.stack_a, s_stacks.stack_b) == -1)
			exit_status = EXIT_FAILURE;
		else
			exit_status = EXIT_SUCCESS;
	}
	else
		exit_status = EXIT_FAILURE;
	if (ft_dllist_is_empty(s_stacks.stack_b) == true && ft_stack_is_sorted(s_stacks.stack_a) == true)
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
	ft_free_push_swap(&s_stacks, nums, argv);
	return (ft_exit_push_swap(exit_status));
}

int	ft_get_moves(t_dllist *stack_a, t_dllist *stack_b)
{
	char		*move;
	int			move_index;
	
	move = get_next_line(STDIN_FILENO);
	while (move != NULL)
	{
		move_index = ft_get_move_index(move);
		if (move_index == -1)
		{
			free(move);
			return (-1);
		}
		ft_execute_move(move_index, stack_a, stack_b);
		free(move);
		move = get_next_line(STDIN_FILENO);
	}
	return (0);
}

int	ft_get_move_index(char *move)
{
	const char	*legal_moves[11] = {"sa\n", "sb\n", "ss\n", "pa\n", "pb\n", "ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"};
	int	i;
	
	i = 0;
	while (legal_moves[i] != NULL && ft_strncmp(move, legal_moves[i], 4) != 0)
		++i;
	if (legal_moves[i] == NULL)
		return (-1);
	return (i);
}

void	ft_execute_move(int index_move, t_dllist *stack_a, t_dllist *stack_b)
{
	void	(*fun[11])(t_dllist *stack_a, t_dllist *stack_b);
	int		i;

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
	i = 0;
	while (i != index_move)
		++i;
	(fun[i])(stack_a, stack_b);
}
