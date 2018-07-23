

#include "../inc/vm.h"

void choose_number_cycles_to_wait(t_pc *pc, t_union *un)
{
    pc->curr_command = un->map[pc->curr_position].value;
    if (pc->curr_command == 1 || pc->curr_command == 4 || pc->curr_command == 5 || pc->curr_command == 13)
        pc->number_cycles_to_wait = 10;
    else if (pc->curr_command == 2 || pc->curr_command == 3)
        pc->number_cycles_to_wait = 5;
    else if (pc->curr_command == 6 || pc->curr_command == 7 || pc->curr_command == 8)
        pc->number_cycles_to_wait = 6;
    else if (pc->curr_command == 9)
        pc->number_cycles_to_wait = 20;
    else if (pc->curr_command == 10 || pc->curr_command == 11)
        pc->number_cycles_to_wait = 25;
    else if (pc->curr_command == 12)
        pc->number_cycles_to_wait = 800;
    else if (pc->curr_command == 14)
        pc->number_cycles_to_wait = 50;
    else if (pc->curr_command == 15)
        pc->number_cycles_to_wait = 1000;
    else if (pc->curr_command == 16)
        pc->number_cycles_to_wait = 2;
}

void choose_commands(t_pc *pc, t_union *un)
{
    if (pc->curr_command == 1)
        ft_live(pc, un);
    if (pc->curr_command == 2)
        ft_load(pc, un);
    if (pc->curr_command == 3)
        ft_st(pc, un);
    if (pc->curr_command == 4)
        ft_add(pc, un);
    if (pc->curr_command == 5)
        ft_sub(pc, un);
    if (pc->curr_command == 6)
        ft_and(pc, un);
    if (pc->curr_command == 7)
        ft_or(pc, un);
    if (pc->curr_command == 8)
        ft_xor(pc, un);
    if (pc->curr_command == 9)
        ft_zjmp(pc, un);
    if (pc->curr_command == 10)
        ft_ldi(pc, un);
    if (pc->curr_command == 11)
        ft_sti(pc, un);
    if (pc->curr_command == 12)
        ft_fork(pc, un);
    if (pc->curr_command == 13)
        ft_lld(pc, un);
    if (pc->curr_command == 14)
        ft_lldi(pc, un);
    if (pc->curr_command == 15)
        ft_lfork(pc, un);
    if (pc->curr_command == 16)
       ft_aff(pc, un);

}
