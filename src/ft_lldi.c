//
// Created by Tetiana PIVEN on 7/27/18.
//

#include "../inc/vm.h"



void ft_lldi(t_pc *pc, t_union *un)
{
	int plus;
	int one;
	int two;
	if (LDI_COD(un->map[ft_check_position(pc->curr_position + 1)].value) && LLDI_COD(un->map[ft_check_position(pc->curr_position + 1)].value))
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
		one = (short)ft_get_int(un, pc->curr_position + 2, 2);
		plus = 4;
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
		two = (short)ft_get_int(un, pc->curr_position + plus, 2);
		plus += 2;
	}
	pc->reg[un->map[pc->curr_position + plus].value - 1] = (unsigned int)ft_get_int(un, ft_check_position((one + two) + pc->curr_position), 4);
	if (pc->reg[un->map[pc->curr_position + plus].value - 1] == 0)
		pc->carry = 1;
	else
		pc->carry = 0;
	pc->curr_position = pc->curr_position + plus + 1;
}