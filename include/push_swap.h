/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 02:25:01 by shinfray          #+#    #+#             */
/*   Updated: 2023/06/27 20:27:29 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "sorting.h"

/*
 *	INITIALIZATION_CLOSURE FUNCTIONS
*/
/*	INITIALIZE_STACKS	*/
int			ft_initialize_stacks(t_stacks *stacks);
/*	PARSE FUNCTIONS	*/
char		**ft_check_args_format(int argc, char **argv);
t_dllist	*ft_retrieve_args(t_dllist *dllist, char **args_list);
/*	CLOSURE FUNCTIONS	*/
void		ft_free_push_swap(t_stacks *stacks, char **nums, char **argv);
int			ft_exit_push_swap(int exit_status);

#endif
