/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 12:54:26 by vmiachko          #+#    #+#             */
/*   Updated: 2018/07/27 17:35:36 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"

void			initialize_map(t_union *un)
{
	t_map		*tmp;
	int			i;

	tmp = un->map;
	i = 0;
	while (i < MEM_SIZE)
	{
		tmp[i].color = 1;
		tmp[i].value = '\0';
		tmp[i].cursor = 0;
		++i;
	}
}

void			move_code_to_map(t_union *un, int color)
{
	int			i;
	int			move;
	t_bot		*bot;

	un->pc = NULL;
	bot = un->bot;
	move = 0;
	while (bot)
	{
		un->pc = pc_push_front(un->pc, pc_new(move, bot->id), un);
		i = 0;
		while (i < bot->code_length)
		{
			un->map[i + move].value = bot->code[i];
			un->map[i + move].color = color;
			if (i == 0)
				un->map[move].cursor = 1;
			++i;
		}
		move += MEM_SIZE / un->bots_number;
		++color;
		bot = bot->next;
	}
}

void			update_pc(t_union *un)
{
	int			i;
	t_pc		*pc;

	i = 0;
	while (i < MEM_SIZE)
	{
		un->map[i].cursor = 0;
		++i;
	}
	pc = un->pc;
	while (pc)
	{
		un->map[pc->curr_position].cursor = 1;
		pc = pc->next;
	}
}
