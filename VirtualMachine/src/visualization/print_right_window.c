/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_right_window.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 20:37:26 by vmiachko          #+#    #+#             */
/*   Updated: 2018/07/30 15:00:13 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"
#include "../../inc/visualization.h"

void		print_winner_v(t_union *un)
{
	t_bot	*bot;
	int		b;
	int		c;

	c = 2;
	b = 0;
	bot = un->bot;
	while (bot)
	{
		b += 5;
		bot = bot->next;
	}
	bot = un->bot;
	while (bot)
	{
		if (bot->id == choose_winner(un))
		{
			split_print(b, c, bot);
		}
		++c;
		bot = bot->next;
	}
}

static void	f(t_union *un, int b)
{
	wattron(stdscr, COLOR_PAIR(31));
	mvprintw(15 + b, XMAX + 4, "CYCLE_TO_DIE : %d\n", un->cycle_to_die);
	mvprintw(18 + b, XMAX + 4, "CYCLE_DELTA : %d\n", CYCLE_DELTA);
	mvprintw(21 + b, XMAX + 4, "NUMBER_LIVE : %d\n", NBR_LIVE);
	mvprintw(24 + b, XMAX + 4, "MAX_CHECKS : %d\n", MAX_CHECKS);
	wattroff(stdscr, COLOR_PAIR(31));
}

static void	print(t_union *un)
{
	wattron(stdscr, COLOR_PAIR(31));
	mvprintw(2, XMAX + 4, "* RUNNING *\n");
	mvprintw(5, XMAX + 4, "SPEED : %i %%\n", un->speed_v);
	mvprintw(8, XMAX + 4, "Cycle : %d\n", un->cycle);
	mvprintw(11, XMAX + 4, "Number of proccesses : %d\n", un->procces_number);
	wattroff(stdscr, COLOR_PAIR(31));
}

void		print_to_right_window(t_union *un)
{
	t_bot	*bot;
	int		b;
	int		c;

	print(un);
	bot = un->bot;
	b = 0;
	c = 2;
	while (bot)
	{
		wattron(stdscr, COLOR_PAIR(c));
		mvprintw(14 + b, XMAX + 4, "Player %i : %.20s", bot->id, bot->name);
		if (ft_strlen(bot->name) > 20)
			mvprintw(14 + b, XMAX + 36, "...", bot->id, bot->name);
		mvprintw(15 + b, XMAX + 5,
				"Last live :               %i\n", bot->last_live);
		mvprintw(16 + b, XMAX + 5,
				"Lives in current period : %i\n", bot->num_live);
		bot = bot->next;
		b += 5;
		wattroff(stdscr, COLOR_PAIR(c));
		++c;
	}
	f(un, b);
	print_help();
}

void		print_pause(t_vis vis)
{
	wattron(stdscr, COLOR_PAIR(31));
	mvprintw(2, XMAX + 4, "* PAUSED *\n");
	wattroff(stdscr, COLOR_PAIR(31));
	print_border(vis.win);
	refresh();
}
