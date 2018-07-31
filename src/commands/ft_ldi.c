/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 16:01:42 by vmiachko          #+#    #+#             */
/*   Updated: 2018/07/30 16:10:52 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"
#include "../../inc/commands.h"

void		ft_ldi_reg(t_pc *pc, t_union *un)
{
	int		one;
	int		two;
	int		three;

	one = un->map[cp(pc->curr_position + 2)].value;
	if (un->arg[1] == REG_CODE)
	{
		two = un->map[cp(pc->curr_position + 3)].value;
		three = un->map[cp(pc->curr_position + 4)].value;
		if (one <= 16 && one > 0 && two <= 16 &&
				two > 0 && three <= 16 && three > 0)
			pc->reg[three - 1] = (unsigned int)ft_get_int(un,
					cp((pc->reg[one - 1]
				+ pc->reg[two - 1]) % IDX_MOD + pc->curr_position), 4);
		pc->curr_position = pc->curr_position + 5;
	}
	if (un->arg[1] == DIR_CODE)
	{
		two = (short)ft_get_int(un, cp(pc->curr_position + 3), 2);
		three = un->map[cp(pc->curr_position + 5)].value;
		if (one <= 16 && one > 0 && three <= 16 && three > 0)
			pc->reg[three - 1] = (unsigned int)ft_get_int(un,
		cp((pc->reg[one - 1] + two) % IDX_MOD + pc->curr_position), 4);
		pc->curr_position = pc->curr_position + 6;
	}
}

void		ft_ldi_dir(t_pc *pc, t_union *un)
{
	int		one;
	int		two;
	int		three;

	one = (short)ft_get_int(un, cp(pc->curr_position + 2), 2);
	if (un->arg[1] == REG_CODE)
	{
		two = un->map[cp(pc->curr_position + 4)].value;
		three = un->map[cp(pc->curr_position + 5)].value;
		if (two <= 16 && two > 0 && three <= 16 && three > 0)
			pc->reg[three - 1] = (unsigned int)ft_get_int(un,
				cp((one + pc->reg[two - 1]) % IDX_MOD + pc->curr_position), 4);
		pc->curr_position = pc->curr_position + 6;
	}
	if (un->arg[1] == DIR_CODE)
	{
		two = (short)ft_get_int(un, cp(pc->curr_position + 4), 2);
		three = un->map[cp(pc->curr_position + 6)].value;
		if (three <= 16 && three > 0)
			pc->reg[three - 1] = (unsigned int)ft_get_int(un,
				cp((one + two) % IDX_MOD + pc->curr_position), 4);
		pc->curr_position = pc->curr_position + 7;
	}
}

void		ft_ldi_ind(t_pc *pc, t_union *un)
{
	int		one;
	int		two;
	int		three;

	one = (unsigned int)ft_get_int(un, cp(pc->curr_position +
		((short)ft_get_int(un, cp(pc->curr_position + 2), 2) % IDX_MOD)), 4);
	if (un->arg[1] == REG_CODE)
	{
		two = un->map[cp(pc->curr_position + 4)].value;
		three = un->map[cp(pc->curr_position + 5)].value;
		if (two <= 16 && two > 0 && three <= 16 && three > 0)
			pc->reg[three - 1] = (unsigned int)ft_get_int(un,
				cp((one + pc->reg[two - 1]) % IDX_MOD + pc->curr_position), 4);
		pc->curr_position += 6;
	}
	if (un->arg[1] == DIR_CODE)
	{
		two = (short)ft_get_int(un, cp(pc->curr_position + 4), 2);
		three = un->map[cp(pc->curr_position + 6)].value;
		if (three <= 16 && three > 0)
			pc->reg[three - 1] = (unsigned int)ft_get_int(un,
				cp((one + two) % IDX_MOD + pc->curr_position), 4);
		pc->curr_position += 7;
	}
}

void		ft_ldi(t_pc *pc, t_union *un)
{
	ft_check_codage(un->map[cp(pc->curr_position + 1)].value, un);
	if (LDI_COD(un->map[cp(pc->curr_position + 1)].value >> 2)
			&& LLDI_COD(un->map[cp(pc->curr_position + 1)].value >> 2))
	{
		pc->curr_position += ft_move_wrong_codage(un, pc->curr_command);
		return ;
	}
	if (un->arg[0] == REG_CODE)
		ft_ldi_reg(pc, un);
	if (un->arg[0] == DIR_CODE)
		ft_ldi_dir(pc, un);
	if (un->arg[0] == IND_CODE)
		ft_ldi_ind(pc, un);
}
