/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 19:56:45 by vmiachko          #+#    #+#             */
/*   Updated: 2018/08/01 16:01:53 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"
#include "../../inc/visualization.h"

void		print_border(WINDOW *win)
{
	int		i;

	i = 1;
	wattron(stdscr, COLOR_PAIR(30));
	wattron(win, COLOR_PAIR(30));
	while (i < 67)
	{
		mvwprintw(win, i, 0, "*");
		mvwprintw(win, i, 196, "*");
		mvwprintw(stdscr, i, 240, "*");
		++i;
	}
	i = 0;
	while (i < 241)
	{
		mvwprintw(i < 197 ? win : stdscr, 0, i, "*");
		mvwprintw(i < 197 ? win : stdscr, 67, i, "*");
		++i;
	}
	wattroff(win, COLOR_PAIR(30));
	wattroff(stdscr, COLOR_PAIR(30));
}

void		change_speed(int key, t_union *un)
{
	if (key == 45)
	{
		if (un->speed_v >= 5)
		{
			un->speed += 8000;
			un->speed_v -= 5;
		}
	}
	if (key == 61)
	{
		if (un->speed >= 8000)
		{
			un->speed -= 8000;
			un->speed_v += 5;
		}
	}
}

WINDOW		*init_colors(int *key)
{
	*key = 1;
	initscr();
	raw();
	nodelay(stdscr, TRUE);
	noecho();
	curs_set(0);
	start_color();
	init_pair(9, COLOR_BLACK, COLOR_WHITE);
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(11, COLOR_WHITE, COLOR_CYAN);
	init_pair(19, COLOR_GREEN, COLOR_GREEN);
	init_pair(12, COLOR_WHITE, COLOR_RED);
	init_pair(13, COLOR_WHITE, COLOR_BLUE);
	init_pair(14, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(15, COLOR_WHITE, COLOR_YELLOW);
	init_pair(30, COLOR_WHITE, COLOR_WHITE);
	init_pair(31, COLOR_GREEN, COLOR_BLACK);
	return (newwin(YMAX, XMAX, 0, 0));
}

void		print_help(void)
{
	wattron(stdscr, COLOR_PAIR(5));
	mvprintw(55, XMAX + 4, "* Press space to resume/pause *\n");
	mvprintw(57, XMAX + 4, "* Press - to decrease speed *\n");
	mvprintw(59, XMAX + 4, "* Press + to increase speed *\n");
	mvprintw(61, XMAX + 4, "* Press ESC to exit *\n");
	wattroff(stdscr, COLOR_PAIR(5));
}

void		split_print(int b, int c, t_bot *bot)
{
	wattron(stdscr, COLOR_PAIR(c));
	mvprintw(27 + b, XMAX + 4, "* WINNER * %i : %.15s",
		bot->id, bot->name);
	if (ft_strlen(bot->name) > 15)
		mvprintw(27 + b, XMAX + 35, "...\n", bot->id, bot->name);
	wattroff(stdscr, COLOR_PAIR(c));
}
