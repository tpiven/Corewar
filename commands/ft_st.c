//
// Created by Tetiana PIVEN on 7/27/18.
//

#include "../../inc/vm.h"
#include "../../inc/commands.h"

void ft_st_reg(t_pc *pc, t_union *un)
{
	uint8_t one;
	uint8_t two;

	one = un->map[ft_check_position(pc->curr_position + 2)].value;
	two = un->map[ft_check_position(pc->curr_position + 3)].value;
	if (two > 16 || two == 0 || one > 16 || one == 0)
	{
		pc->curr_position = pc->curr_position + 4;
		return ;
	}
	pc->reg[two - 1] = pc->reg[one - 1];
	pc->curr_position = pc->curr_position + 4;
}

void ft_st_ind(t_pc *pc, t_union *un)
{
	int position;
	uint8_t *num;
	uint8_t one;

	one = un->map[ft_check_position(pc->curr_position + 2)].value;
	if ( one > 16 || one == 0)
	{
		pc->curr_position = pc->curr_position + 5;
		return ;
	}
	position = pc->curr_position + ((short)ft_get_int(un, ft_check_position(pc->curr_position + 3), 2) % IDX_MOD);
	position = ft_check_position(position);
	num = ft_get_char_from_int(pc, one - 1);
	un->map[position].value = num[0];
	un->map[position].color = un->map[pc->curr_position].color;
	un->map[ft_check_position(position + 1)].value = num[1];
	un->map[ft_check_position(position + 1)].color = un->map[pc->curr_position].color;
	un->map[ft_check_position(position + 2)].value = num[2];
	un->map[ft_check_position(position + 2)].color = un->map[pc->curr_position].color;
	un->map[ft_check_position(position + 3)].color = un->map[pc->curr_position].color;
	un->map[ft_check_position(position + 3)].value = num[3];
	pc->curr_position = pc->curr_position + 5;
}



void ft_st(t_pc *pc, t_union *un)
{
	ft_check_codage(un->map[ft_check_position(pc->curr_position + 1)].value,  un);
	if (ST_COD(un->map[ft_check_position(pc->curr_position + 1)].value))
	{
		pc->curr_position += ft_move_wrong_codage(un, pc->curr_command);
		return ;
	}
	if (un->arg[1] == REG_CODE)
		ft_st_reg(pc, un);
	if (un->arg[1] == IND_CODE)
		ft_st_ind(pc, un);

}
