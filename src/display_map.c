#include "../inc/vm.h"


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
    int yMax = 200;
    int xMax = 200;
    //getmaxyx(stdscr, yMax, xMax);
    start_color();
    win = newwin(yMax, xMax, 1, 1);
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


        mvprintw(5, xMax + 5, "Cycle: %d\n", un->cycle);
        mvprintw(8, xMax + 5, "Cycle_to_die: %d\n", un->cycle_to_die);
        mvprintw(12, xMax + 5, "Number live: %d\n", un->bot->num_live);
        mvprintw(15, xMax + 5, "Last live: %d\n", un->bot->last_live);
        mvprintw(18, xMax + 5, "Number proccess: %d\n", un->procces_number);
        /* Start color 			*/
        while (i < MEM_SIZE)
        {
            wattron(win, COLOR_PAIR(un->map[i].color));
            if (un->map[i].cursor)
            {
                attron(A_BOLD);
                wattron(win, COLOR_PAIR(un->map[i].color + 10));
            }


            mvwprintw(win, y, x, "%02x", un->map[i].value);
            x +=3;

            wattroff(win, COLOR_PAIR(un->map[i].color));
            mvwprintw(win, y, x, " ");
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
        if (key == 32)
        {
            while (1)
            {
                key = getch();
                if (key == 32)
                    break ;
                if (key == 27)
                    break ;
            }
        }

        if (un->cycle_to_die <= 0 || !un->pc)
        {
            while (1)
            {
                key = getch();
                if (key == 27)
                    break ;
            }
        }
        if (key == 27)
            break ;
        //usleep(100000);
        corewar(un);
        update_pc(un);
        //clear();
    }
    endwin();
    //curs_set(1);
}