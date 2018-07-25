

#include "../inc/vm.h"

void 		move_code_to_map(t_union *un, int color)
{
	int i;
	int j;
	int move;
	t_bot	*bot;

	j = 0;
	un->pc = NULL;
	bot = un->bot;
	move = 0;
	while (bot)
	{
		un->pc = pc_push_front(un->pc,pc_new(j + move, bot->id));

		i = 0;
		while (i < bot->code_length)
		{
			un->map[j + move].value = bot->code[i];
			un->map[j + move].color = color;
			if (i == 0)
			{
				un->map[j + move].cursor = 1;
				un->pc->curr_command = un->map[j + move].value;
			}
			++i;
			++j;
		}
		move += 682 - bot->code_length + 100;
		++color;
		bot = bot->next;
	}
}


void		update_pc(t_union *un)
{
	int		i;
	t_pc	*pc;

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

void		display_map(t_union *un)
{
	int key;
	int i;
	int k;
    WINDOW *win;

	key = 1;
	initscr();
	raw();
	nodelay(stdscr, TRUE);
	noecho();
	curs_set(0);
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
	start_color();
    win = newwin(yMax - 2, xMax - 2, 1, 1);
	init_pair(9,  COLOR_BLACK,COLOR_WHITE);
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


	while (key)
	{

        i = 0;
        k = 0;
        int x = 0;
        int y = 0;


        /* Start color 			*/
        while (i < MEM_SIZE)
        {
            wattron(win, COLOR_PAIR(un->map[i].color));
            if (un->map[i].cursor)
            {
                attron(A_BOLD);
                wattron(win, COLOR_PAIR(un->map[i].color + 10));
            }

            mvwprintw(win, y, x, "%02x ", un->map[i].value);
            x +=3;

            wattroff(win, COLOR_PAIR(un->map[i].color));
            wprintw(win, " ");
            if (un->map[i].cursor)
            {
                wattroff(win, A_BOLD);
                wattroff(win, COLOR_PAIR(un->map[i].color + 10));
            }
            ++k;
            if (k == 64)
            {
                y++;
                x = 0;
                k = 0;
            }
            ++i;
        }
        wrefresh(win);
        refresh();
        key = getch();
        if (key == 27)
            break ;
        if (key == 32)
        {
            while (1)
            {
                key = getch();
                if (key == 32)
                    break ;
            }
        }
        usleep(100000);
        corewar(un);
        update_pc(un);
        //clear();
}
	endwin();
	//curs_set(1);
}