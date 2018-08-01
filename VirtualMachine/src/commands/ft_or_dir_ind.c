/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_or_dir_ind.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 16:28:46 by vmiachko          #+#    #+#             */
/*   Updated: 2018/07/30 16:30:52 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"
#include "../../inc/commands.h"

void				ft_or_reg_dir(t_pc *pc, t_union *un)
{
	unsigned int	one;
	unsigned int	two;
	unsigned int	three;

	one = un->map[cp(pc->curr_position + 2)].value;
	two = (unsigned int)ft_get_int(un, cp(pc->curr_position + 3), 4);
	three = un->map[cp(pc->curr_position + 7)].value;
	if (one <= 16 && one > 0 && three <= 16 && three > 0)
	{
		pc->reg[three - 1] = pc->reg[one - 1] | two;
		if (pc->reg[three - 1] == 0)
			pc->carry = 1;
		else
			pc->carry = 0;
	}
	pc->curr_position = pc->curr_position + 8;
}

void				ft_or_dir_dir(t_pc *pc, t_union *un)
{
	unsigned int	one;
	unsigned int	two;
	unsigned int	three;

	one = (unsigned int)ft_get_int(un, cp(pc->curr_position + 2), 4);
	two = (unsigned int)ft_get_int(un, cp(pc->curr_position + 6), 4);
	three = un->map[cp(pc->curr_position + 10)].value;
	if (three <= 16 && three > 0)
	{
		pc->reg[three - 1] = one | two;
		if (pc->reg[three - 1] == 0)
			pc->carry = 1;
		else
			pc->carry = 0;
	}
	pc->curr_position = pc->curr_position + 11;
}

void				ft_or_ind_dir(t_pc *pc, t_union *un)
{
	unsigned int	one;
	unsigned int	two;
	unsigned int	three;

	one = (unsigned int)ft_get_int(un, cp(pc->curr_position +
		((short)ft_get_int(un, cp(pc->curr_position + 2), 2) % IDX_MOD)), 4);
	two = (unsigned int)ft_get_int(un, cp(pc->curr_position + 4), 4);
	three = un->map[cp(pc->curr_position + 8)].value;
	if (three <= 16 && three > 0)
	{
		pc->reg[three - 1] = one | two;
		if (pc->reg[three - 1] == 0)
			pc->carry = 1;
		else
			pc->carry = 0;
	}
	pc->curr_position = pc->curr_position + 9;
}

void				ft_or_reg_ind(t_pc *pc, t_union *un)
{
	unsigned int	one;
	unsigned int	two;
	unsigned int	three;

	one = un->map[cp(pc->curr_position + 2)].value;
	two = (unsigned int)ft_get_int(un, cp(pc->curr_position +
		((short)ft_get_int(un, cp(pc->curr_position + 3), 2) % IDX_MOD)), 4);
	three = un->map[cp(pc->curr_position + 5)].value;
	if (one <= 16 && one > 0 && three <= 16 && three > 0)
	{
		pc->reg[three - 1] = pc->reg[one - 1] | two;
		if (pc->reg[three - 1] == 0)
			pc->carry = 1;
		else
			pc->carry = 0;
	}
	pc->curr_position = pc->curr_position + 6;
}

void				ft_or_dir_ind(t_pc *pc, t_union *un)
{
	unsigned int	one;
	unsigned int	two;
	unsigned int	three;

	one = (unsigned int)ft_get_int(un, cp(pc->curr_position + 2), 4);
	two = (unsigned int)ft_get_int(un, cp(pc->curr_position +
		((short)ft_get_int(un, cp(pc->curr_position + 6), 2) % IDX_MOD)), 4);
	three = un->map[cp(pc->curr_position + 8)].value;
	if (three <= 16 && three > 0)
	{
		pc->reg[three - 1] = one | two;
		if (pc->reg[three - 1] == 0)
			pc->carry = 1;
		else
			pc->carry = 0;
	}
	pc->curr_position = pc->curr_position + 9;
}
