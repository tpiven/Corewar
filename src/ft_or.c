//
// Created by Tetiana PIVEN on 7/27/18.
//

#include "../inc/vm.h"

void ft_or(t_pc *pc, t_union *un)
{
	unsigned int one;
	unsigned int two;
	int plus;
	if (AND_OR(un->map[ft_check_position(pc->curr_position + 1)].value) && AND_XOR(un->map[ft_check_position(pc->curr_position + 1)].value))
	{
		pc->curr_position += 2;
		return ;
	}
	ft_check_codage(un->map[ft_check_position(pc->curr_position + 1)].value, un);
	if (un->arg[0] == REG_CODE)
	{
		one = pc->reg[un->map[pc->curr_position + 2].value - 1];
		plus = 3;
	}
	if (un->arg[0] == DIR_CODE)
	{
		one = (unsigned int)ft_get_int(un, pc->curr_position + 2, 4);
		plus = 6;
	}
	if (un->arg[0] == IND_CODE)
	{
		one = (unsigned int)ft_get_int(un, (pc->curr_position + ((short)ft_get_int(un, pc->curr_position + 2, 2) % IDX_MOD)), 4);
		plus = 4;
	}
	if (un->arg[1] == REG_CODE)
	{
		two = pc->reg[un->map[pc->curr_position + plus].value - 1];
		plus += 1;
	}
	if (un->arg[1] == DIR_CODE)
	{
		two = (unsigned int)ft_get_int(un, pc->curr_position + plus, 4);
		plus += 4;
	}
	if (un->arg[1] == IND_CODE)
	{
		two = (unsigned int)ft_get_int(un, (pc->curr_position + ((short)ft_get_int(un, pc->curr_position + plus, 2) % IDX_MOD)), 4);
		plus += 2;
	}
	pc->reg[un->map[pc->curr_position + plus].value - 1] = one | two;
	if ( pc->reg[un->map[pc->curr_position + plus].value - 1] == 0)
		pc->carry = 1;
	else
		pc->carry = 0;
	pc->curr_position = pc->curr_position + plus + 1;
}
