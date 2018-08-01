/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_winner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 11:57:37 by vmiachko          #+#    #+#             */
/*   Updated: 2018/07/27 14:09:22 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"

static t_bot		*find_bot(int id, t_union *un)
{
	t_bot	*bot;

	bot = un->bot;
	while (bot)
	{
		if (bot->id == id)
			return (bot);
		bot = bot->next;
	}
	return (NULL);
}

void				print_winner(t_union *un)
{
	int				id;
	t_bot			*bot;

	id = choose_winner(un);
	if (id == -999)
		exit(33);
	bot = find_bot(id, un);
//	ft_printf(GREEN"Contestant %i, \"%s\", has won !\n"RESET,
//			bot->id, bot->name);
	ft_printf("Contestant %i, \"%s\", has won !\n",
			-bot->id, bot->name);
}

void				print_players_info(t_union *un)
{
	t_bot			*bot;

	bot = un->bot;
	//ft_printf(GREEN"Introducing contestants...\n"RESET);
	ft_printf("Introducing contestants...\n");
	while (bot)
	{
//		ft_printf(GREEN"* Player % i, weighing %i bytes,", bot->id, bot->size);
//		ft_printf("  \"%s\" (\"%s\") !\n"RESET, bot->name, bot->comment);
		ft_printf("* Player %i, weighing %i bytes,", -bot->id, bot->size);
		ft_printf(" \"%s\" (\"%s\") !\n", bot->name, bot->comment);
		bot = bot->next;
	}
}
