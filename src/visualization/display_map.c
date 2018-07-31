/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 14:10:10 by vmiachko          #+#    #+#             */
/*   Updated: 2018/07/30 15:05:24 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"
#include "../../inc/visualization.h"

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

void		print_map(t_vis *vis, t_union *un)
{
	while (vis->i < MEM_SIZE)
	{
		wattron(vis->win, COLOR_PAIR(un->map[vis->i].color));
		if (un->map[vis->i].cursor)
			wattron(vis->win, COLOR_PAIR(un->map[vis->i].color + 10));
		mvwprintw(vis->win, vis->y, vis->x, "%02x", un->map[vis->i].value);
		vis->x += 3;
		wattroff(vis->win, COLOR_PAIR(un->map[vis->i].color));
		mvwprintw(vis->win, vis->y, vis->x, " ");
		if (un->map[vis->i].cursor)
			wattroff(vis->win, COLOR_PAIR(un->map[vis->i].color + 10));
		++vis->k;
		if (vis->k == 64)
		{
			vis->y++;
			vis->x = 3;
			vis->k = 0;
		}
		++vis->i;
	}
	wrefresh(vis->win);
	refresh();
}

static void	win(t_union *un, t_vis vis)
{
	system("afplay music/winner.mp3 &");
	print_winner_v(un);
	print_border(vis.win);
	refresh();
}

int			pause_exit(t_vis vis, t_union *un)
{
	if (vis.key == 32)
	{
		while (1)
		{
			print_pause(vis);
			vis.key = getch();
			if (vis.key == 32)
				break ;
			if (vis.key == 27)
				return (27);
		}
	}
	if (un->cycle_to_die <= 0 || !un->pc)
	{
		win(un, vis);
		while (1)
		{
			vis.key = getch();
			if (vis.key == 27)
				return (27);
		}
	}
	return (vis.key == 27 ? 27 : 1);
}

void		display_map(t_union *un)
{
	t_vis	vis;

	un->speed = 0;
	un->speed_v = 100;
	vis.win = init_colors(&vis.key);
	while (vis.key)
	{
		vis.i = 0;
		vis.k = 0;
		vis.x = 3;
		vis.y = 2;
		print_to_right_window(un);
		print_border(vis.win);
		print_map(&vis, un);
		vis.key = getch();
		change_speed(vis.key, un);
		vis.key = pause_exit(vis, un);
		if (vis.key == 27)
			break ;
		corewar(un);
		update_pc(un);
		usleep(un->speed);
	}
	endwin();
	curs_set(1);
}
