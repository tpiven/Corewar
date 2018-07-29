//
// Created by Tetiana PIVEN on 7/27/18.
//

#include "../../inc/vm.h"
#include "../../inc/commands.h"

void ft_fork(t_pc *pc, t_union *un)
{
	int position;
	t_pc *new;

	position = pc->curr_position + ((short)ft_get_int(un, pc->curr_position + 1, 2) % IDX_MOD);
	position = ft_check_position(position);
	new = pc_copy(pc, position);
	un->pc = pc_push_front(un->pc, new, un);
	pc->curr_position = pc->curr_position + 3;
}


void ft_lfork(t_pc *pc, t_union *un)
{
	int position;
	t_pc *new;

	position = pc->curr_position + ((short)ft_get_int(un, pc->curr_position + 1, 2));
	position = ft_check_position(position);
	new = pc_copy(pc, position);
	un->pc = pc_push_front(un->pc, new, un);
	pc->curr_position = pc->curr_position + 3;
}