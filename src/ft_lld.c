//
// Created by Tetiana PIVEN on 7/27/18.
//


#include "../inc/vm.h"

void ft_lld(t_pc *pc, t_union *un)
{
	unsigned int n;
	int plus;
	if (LD_COD(un->map[ft_check_position(pc->curr_position + 1)].value))
	{
		pc->curr_position += 2;
		return ;
	}
	ft_check_codage(un->map[ft_check_position(pc->curr_position + 1)].value, un);
	if (un->arg[0] == DIR_CODE)
	{
		plus = 5;
		n = (unsigned int)ft_get_int(un, pc->curr_position, 4);
	}
	if (un->arg[0] == IND_CODE)
	{
		plus = 3;
		n = (unsigned int)ft_get_int(un, ft_check_position(pc->curr_position + ((short)ft_get_int(un, pc->curr_position + 1, 2))), 4);
	}
	if (un->map[pc->curr_position + plus].value > 16)
		return ;
	pc->reg[un->map[pc->curr_position + plus].value - 1] = n;
	if (n == 0)
		pc->carry = 1;
	else
		pc->carry = 0;
	pc->curr_position = pc->curr_position + plus + 1;
}
