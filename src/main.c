/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 12:23:04 by vmiachko          #+#    #+#             */
/*   Updated: 2018/07/05 12:27:01 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vm.h"
#include "../inc/parsing.h"


int				main(int argc, char **argv)
{
	t_union		un;

	un.dump = 0;
	un.visual = 0;
	un.checks = 0;
	un.cycle_to_die = CYCLE_TO_DIE;
	un.bots_number = 0;
	un.procces_number = 0;
	if (parsing(argc, argv, &un))
	{
		un.map = (t_map *)malloc(MEM_SIZE * sizeof(t_map) + 1);
		initialize_map(&un);
		move_code_to_map(&un, 2);
		pc_sort_ascending(&un);
		if (un.visual)
			display_map(&un);
		else
			without_visual(&un);
		bot_clear_list(un.bot);
		pc_clear_list(un.pc);
		free(un.map);
	}
	return (0);
}
