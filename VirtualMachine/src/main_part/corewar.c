/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 17:03:35 by vmiachko          #+#    #+#             */
/*   Updated: 2018/07/31 14:46:25 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"
#include "../../inc/commands.h"

void			dump(t_union *un)
{
	int			i;
	int			k;
	int			h;

	i = 0;
	k = 0;
	h = 0;
	ft_printf("%#.4x : ", h);
	while (i < MEM_SIZE)
	{
		ft_printf("%02x ", un->map[i].value);
		++i;
		++k;
		if (k == 64)
		{
			ft_printf("\n");
			h += 64;
			if (i < MEM_SIZE)
				ft_printf("%#.4x : ", h);
			k = 0;
		}
	}
}

void			without_visual(t_union *un)
{
	print_players_info(un);
	while (un->pc)
	{
		corewar(un);
		if (un->finish == 1)
			break ;
		if (un->cycle == un->dump)
		{
			dump(un);
			break ;
		}
	}
	if (!un->dump || un->dump > un->cycle)
		print_winner(un);
//	t_bot	*bot;
//	bot = un->bot;
//	ft_printf("CYCLES: %i\n", un->cycle);
//	while (bot)
//	{
//		ft_printf("LAST LIVE BOT <%i> NUM: %i\n", bot->id, bot->last_live);
//		bot = bot->next;
//	}
}

void			execute_command(t_pc *pc, t_union *un)
{
	if (un->map[pc->curr_position].value >= 1 &&
		un->map[pc->curr_position].value <= 16 &&
			pc->number_cycles_to_wait == -1)
	{
		choose_number_cycles_to_wait(pc, un);
		--pc->number_cycles_to_wait;
	}
	else if (pc->number_cycles_to_wait == 1)
	{
		choose_commands(pc, un);
		pc->number_cycles_to_wait = -1;
	}
	else if (pc->number_cycles_to_wait > 0)
		--pc->number_cycles_to_wait;
	else
		pc->curr_position++;
	if (pc->curr_position >= MEM_SIZE)
		pc->curr_position %= MEM_SIZE;
	else if (pc->curr_position < 0)
		pc->curr_position += MEM_SIZE;
}

void			move_pc(t_union *un)
{
	t_pc		*pc;

	pc = un->pc;
	while (pc)
	{
		execute_command(pc, un);
		pc = pc->next;
	}
}

void			corewar(t_union *un)
{
	++un->cycle;
//	if (un->cycle == 25)
//		ft_printf("df");
	if (un->c == 1 || un->p == 1)
		ft_printf("CYCLE %d\n", un->cycle);
	if (un->cycle_to_die < 0)
	{
		un->finish = 1;
		return ;
	}
	++un->k;
	move_pc(un);
	if (un->k == un->cycle_to_die && un->cycle != 0)
	{
		check_if_pc_alive(un);
		decrease_cycle_to_die(un);
		clear_num_live(un);
		un->k = 0;
	}
}
