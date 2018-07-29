//
// Created by Tetiana PIVEN on 7/28/18.
//

#include "../../inc/vm.h"
#include "../../inc/commands.h"

void ft_sti_reg_dir(t_pc *pc, t_union *un)
{
	int one;
	int two;
	int three;
	int position;
	uint8_t *num;

	one = un->map[ft_check_position(pc->curr_position + 2)].value;
	two = un->map[ft_check_position(pc->curr_position + 3)].value;
	if (one <= 16 && one > 0 && two <= 16 && two > 0)
	{
		three = (short)ft_get_int(un, ft_check_position(pc->curr_position + 4), 2);
		position = ((int)pc->reg[two - 1] + three) % IDX_MOD + pc->curr_position;
		position = ft_check_position(position);
		num = ft_get_char_from_int(pc, one - 1);
		un->map[ft_check_position(position)].value = num[0];
		un->map[ft_check_position(position + 1)].value = num[1];
		un->map[ft_check_position(position + 2)].value = num[2];
		un->map[ft_check_position(position + 3)].value = num[3];
		un->map[ft_check_position(position)].color = un->map[pc->curr_position].color;
		un->map[ft_check_position(position + 1)].color = un->map[pc->curr_position].color;
		un->map[ft_check_position(position + 2)].color = un->map[pc->curr_position].color;
		un->map[ft_check_position(position + 3)].color = un->map[pc->curr_position].color;
	}
	pc->curr_position = pc->curr_position + 6;
}

void ft_sti_dir_dir(t_pc *pc, t_union *un)
{
	int one;
	int two;
	int three;
	int position;
	uint8_t *num;

	one = un->map[ft_check_position(pc->curr_position + 2)].value;
	if (one <= 16 && one > 0)
	{
		two = (short)ft_get_int(un, ft_check_position(pc->curr_position + 3), 2);
		three = (short)ft_get_int(un, ft_check_position(pc->curr_position + 5), 2);
		position = (two + three) % IDX_MOD + pc->curr_position;
		position = ft_check_position(position);
		num = ft_get_char_from_int(pc, one - 1);
		un->map[ft_check_position(position)].value = num[0];
		un->map[ft_check_position(position + 1)].value = num[1];
		un->map[ft_check_position(position + 2)].value = num[2];
		un->map[ft_check_position(position + 3)].value = num[3];
		un->map[ft_check_position(position)].color = un->map[pc->curr_position].color;
		un->map[ft_check_position(position + 1)].color = un->map[pc->curr_position].color;
		un->map[ft_check_position(position + 2)].color = un->map[pc->curr_position].color;
		un->map[ft_check_position(position + 3)].color = un->map[pc->curr_position].color;
	}

	pc->curr_position = pc->curr_position + 7;
}

void ft_sti_ind_dir(t_pc *pc, t_union *un)
{
	int one;
	int two;
	int three;
	int position;
	uint8_t *num;

	one = un->map[ft_check_position(pc->curr_position + 2)].value;
	if (one <= 16 && one > 0)
	{
		two = ft_get_int(un, ft_check_position(pc->curr_position + ((short)ft_get_int(un, ft_check_position(pc->curr_position + 3), 2) % IDX_MOD)), 4);
		three = (short)ft_get_int(un, ft_check_position(pc->curr_position + 5), 2);
		position = (two + (int)pc->reg[three - 1]) % IDX_MOD + pc->curr_position;
		position = ft_check_position(position);
		num = ft_get_char_from_int(pc, one - 1);
		un->map[ft_check_position(position)].value = num[0];
		un->map[ft_check_position(position + 1)].value = num[1];
		un->map[ft_check_position(position + 2)].value = num[2];
		un->map[ft_check_position(position + 3)].value = num[3];
		un->map[ft_check_position(position)].color = un->map[pc->curr_position].color;
		un->map[ft_check_position(position + 1)].color = un->map[pc->curr_position].color;
		un->map[ft_check_position(position + 2)].color = un->map[pc->curr_position].color;
		un->map[ft_check_position(position + 3)].color = un->map[pc->curr_position].color;
	}

	pc->curr_position = pc->curr_position + 7;
}