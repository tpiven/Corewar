/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 13:23:18 by vmiachko          #+#    #+#             */
/*   Updated: 2018/07/31 14:44:46 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"

void		check_if_pc_alive(t_union *un)
{
	t_pc	*pc;
	t_pc	*tmp;

	pc = un->pc;
	while (pc)
	{
		if (!pc->alive)
		{
			tmp = pc->next;
			if (un->p == 1)
				ft_printf("Process %d died\n", pc->id);
			un->pc = delete_pc(un->pc, pc, un);
			pc = tmp;
		}
		else
		{
			pc->alive = 0;
			pc = pc->next;
		}
	}
}

void		decrease_cycle_to_die(t_union *un)
{
	if (un->num_plives >= 21)
	{
		un->cycle_to_die -= CYCLE_DELTA;
		un->checks = 0;
		if (un->c == 1 || un->p == 1)
			ft_printf("Cycle to die is now %d\n", un->cycle_to_die);
	}
	else
		++un->checks;
	if (un->checks == MAX_CHECKS)
	{
		un->checks = 0;
		un->cycle_to_die -= CYCLE_DELTA;
		if (un->c == 1 || un->p == 1)
			ft_printf("Cycle to die is now %d\n", un->cycle_to_die);
	}
}

void		clear_num_live(t_union *un)
{
	t_bot	*bot;

	un->num_plives = 0;
	bot = un->bot;
	while (bot)
	{
		bot->num_live = 0;
		bot = bot->next;
	}
}

int			choose_winner(t_union *un)
{
	t_bot	*bot;
	int		max;
	int		id;

	bot = un->bot;
	if (bot)
	{
		max = bot->last_live;
		id = bot->id;
	}
	else
		return (-5);
	while (bot)
	{
		if (max < bot->last_live)
		{
			max = bot->last_live;
			id = bot->id;
		}
		bot = bot->next;
	}
	return (id);
}
