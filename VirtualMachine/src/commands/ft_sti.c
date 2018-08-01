/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 16:33:39 by vmiachko          #+#    #+#             */
/*   Updated: 2018/07/30 16:46:56 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"
#include "../../inc/commands.h"

static void	f(t_union *un, int position, uint8_t *num)
{
	un->map[cp(position)].value = num[0];
	un->map[cp(position + 1)].value = num[1];
	un->map[cp(position + 2)].value = num[2];
	un->map[cp(position + 3)].value = num[3];
}

void		ft_sti_reg_reg(t_pc *pc, t_union *un)
{
	int		one;
	int		two;
	int		three;
	int		position;
	uint8_t	*num;

	one = un->map[cp(pc->curr_position + 2)].value;
	two = un->map[cp(pc->curr_position + 3)].value;
	three = un->map[cp(pc->curr_position + 4)].value;
	if (one <= 16 && one > 0 && two <= 16
		&& two > 0 && three <= 16 && three > 0)
	{
		position = (int)(pc->reg[two - 1] +
			pc->reg[three - 1]) % IDX_MOD + pc->curr_position;
		position = cp(position);
		num = ft_get_char_from_int(pc, one - 1);
		f(un, position, num);
		un->map[cp(position)].color = un->map[pc->curr_position].color;
		un->map[cp(position + 1)].color = un->map[pc->curr_position].color;
		un->map[cp(position + 2)].color = un->map[pc->curr_position].color;
		un->map[cp(position + 3)].color = un->map[pc->curr_position].color;
	}
	pc->curr_position += 5;
}

void		ft_sti_dir_reg(t_pc *pc, t_union *un)
{
	int		one;
	int		two;
	int		three;
	int		position;
	uint8_t	*num;

	one = un->map[cp(pc->curr_position + 2)].value;
	three = un->map[cp(pc->curr_position + 5)].value;
	if (one <= 16 && one > 0 && three <= 16 && three > 0)
	{
		two = (short)ft_get_int(un, cp(pc->curr_position + 3), 2);
		position = (two +
			(int)pc->reg[three - 1]) % IDX_MOD + pc->curr_position;
		position = cp(position);
		num = ft_get_char_from_int(pc, one - 1);
		f(un, position, num);
		un->map[cp(position)].color = un->map[pc->curr_position].color;
		un->map[cp(position + 1)].color = un->map[pc->curr_position].color;
		un->map[cp(position + 2)].color = un->map[pc->curr_position].color;
		un->map[cp(position + 3)].color = un->map[pc->curr_position].color;
	}
	pc->curr_position = pc->curr_position + 6;
}

void		ft_sti_ind_reg(t_pc *pc, t_union *un)
{
	int		one;
	int		two;
	int		three;
	int		position;
	uint8_t	*num;

	one = un->map[cp(pc->curr_position + 2)].value;
	three = un->map[cp(pc->curr_position + 5)].value;
	if (one <= 16 && one > 0 && three <= 16 && three > 0)
	{
		two = ft_get_int(un, cp(pc->curr_position +
		((short)ft_get_int(un, cp(pc->curr_position + 3), 2) % IDX_MOD)), 4);
		position = (two + (int)pc->reg[three - 1]) % IDX_MOD
		+ pc->curr_position;
		position = cp(position);
		num = ft_get_char_from_int(pc, one - 1);
		f(un, position, num);
		un->map[cp(position)].color = un->map[pc->curr_position].color;
		un->map[cp(position + 1)].color = un->map[pc->curr_position].color;
		un->map[cp(position + 2)].color = un->map[pc->curr_position].color;
		un->map[cp(position + 3)].color = un->map[pc->curr_position].color;
	}
	pc->curr_position += 6;
}

void		ft_sti(t_pc *pc, t_union *un)
{
	ft_check_codage(un->map[cp(pc->curr_position + 1)].value, un);
	if (STI(un->map[cp(pc->curr_position + 1)].value >> 2) &&
		STI_COD(un->map[cp(pc->curr_position + 1)].value >> 2))
	{
		pc->curr_position += ft_move_wrong_codage(un, pc->curr_command);
		return ;
	}
	if (un->arg[1] == REG_CODE && un->arg[2] == REG_CODE)
		ft_sti_reg_reg(pc, un);
	if (un->arg[1] == DIR_CODE && un->arg[2] == REG_CODE)
		ft_sti_dir_reg(pc, un);
	if (un->arg[1] == IND_CODE && un->arg[2] == REG_CODE)
		ft_sti_ind_reg(pc, un);
	if (un->arg[1] == REG_CODE && un->arg[2] == DIR_CODE)
		ft_sti_reg_dir(pc, un);
	if (un->arg[1] == DIR_CODE && un->arg[2] == DIR_CODE)
		ft_sti_dir_dir(pc, un);
	if (un->arg[1] == IND_CODE && un->arg[2] == DIR_CODE)
		ft_sti_ind_dir(pc, un);
}
