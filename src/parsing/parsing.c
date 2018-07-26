/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 12:25:09 by vmiachko          #+#    #+#             */
/*   Updated: 2018/07/05 12:25:13 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"
#include "../../inc/parsing.h"

int 		parsing(int argc, char **argv, t_union *un)
{
	int 	r;

	un->bot = NULL;
	un->pc = NULL;
	un->argc = argc;
	un->count.c = 0;
	un->count.i = 1;
	if (check_if_input_correct(argv, un) == 0)
	{
		ft_printf(RED"Usage: ./corewar [-dump nbr_cycles > 0] [[-n number > 0] champion1.cor] ... \n-v : Ncurses output mode\n"RESET);
		return (0);
	}
	else if ((check_if_input_correct(argv, un) == -1))
	{
		ft_printf(RED"Too many arguments\n"RESET);
		return (0);
	}
	if ((r = parse_bot(un)) == -1)
	{
		ft_printf(RED"Bot's number should be identical\n"RESET);
		return (0);
	}
	return (r);
}