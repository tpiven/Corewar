//
// Created by Tetiana PIVEN on 7/27/18.
//


#include "../inc/vm.h"

void ft_lld_dir(t_pc *pc, t_union *un)
{
	unsigned int n;

	n = (unsigned int)ft_get_int(un, ft_check_position(pc->curr_position + 2), 4);
	if (un->map[ft_check_position(pc->curr_position + 6)].value > 16 || un->map[ft_check_position(pc->curr_position + 6)].value == 0)
	{
		pc->curr_position = pc->curr_position + 7;
		return ;
	}
	pc->reg[un->map[ft_check_position(pc->curr_position + 6)].value - 1] = n;
	if (n == 0)
		pc->carry = 1;
	else
		pc->carry = 0;
	pc->curr_position = pc->curr_position + 7;
}

void ft_lld_ind(t_pc *pc, t_union *un)
{
	unsigned int n;

	n = (unsigned int)ft_get_int(un, ft_check_position(pc->curr_position + ((short)ft_get_int(un, ft_check_position(pc->curr_position + 2), 2))), 4);
	if (un->map[ft_check_position(pc->curr_position + 6)].value > 16 || un->map[ft_check_position(pc->curr_position + 6)].value == 0)
	{
		pc->curr_position = pc->curr_position + 7;
		return ;
	}
	pc->reg[un->map[ft_check_position(pc->curr_position + 6)].value - 1] = n;
	if (n == 0)
		pc->carry = 1;
	else
		pc->carry = 0;
	pc->curr_position = pc->curr_position + 5;

}

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
		ft_lld_dir(pc, un);
	if (un->arg[0] == IND_CODE)
		ft_lld_ind(pc, un);
}
