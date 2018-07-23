

#include "../inc/vm.h"


void		execute_command(t_pc *pc, t_union *un)
{

		if (un->map[pc->curr_position].value >= 1 && un->map[pc->curr_position].value <= 16 && pc->number_cycles_to_wait == -1)
		{
			choose_number_cycles_to_wait(pc, un);
		}
		else if (pc->number_cycles_to_wait == 0)
		{
			choose_commands(pc, un);
			pc->number_cycles_to_wait = -1;
		}
		else if (pc->number_cycles_to_wait > 0)
			--pc->number_cycles_to_wait;
		else
			pc->curr_position++;
}

void		move_pc(t_union *un)
{
	t_pc	*pc;

	pc = un->pc;
	while (pc)
	{
		execute_command(pc, un);
		pc = pc->next;
	}
}


void	corewar(t_union *un)
{

		++un->cycle;
		move_pc(un);
}