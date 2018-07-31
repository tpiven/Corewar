/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 16:50:49 by vmiachko          #+#    #+#             */
/*   Updated: 2018/07/30 16:54:27 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"
#include "../../inc/commands.h"

void		ft_sti_reg_dir(t_pc *pc, t_union *un)
{
	int		one;
	int		two;
	int		three;
	int		position;
	uint8_t	*num;

	one = un->map[cp(pc->curr_position + 2)].value;
	two = un->map[cp(pc->curr_position + 3)].value;
	if (one <= 16 && one > 0 && two <= 16 && two > 0)
	{
		three = (short)ft_get_int(un, cp(pc->curr_position + 4), 2);
		position = ((int)pc->reg[two - 1] + three) % IDX_MOD
			+ pc->curr_position;
		position = cp(position);
		num = ft_get_char_from_int(pc, one - 1);
		un->map[cp(position)].value = num[0];
		un->map[cp(position + 1)].value = num[1];
		un->map[cp(position + 2)].value = num[2];
		un->map[cp(position + 3)].value = num[3];
		un->map[cp(position)].color = un->map[pc->curr_position].color;
		un->map[cp(position + 1)].color = un->map[pc->curr_position].color;
		un->map[cp(position + 2)].color = un->map[pc->curr_position].color;
		un->map[cp(position + 3)].color = un->map[pc->curr_position].color;
	}
	pc->curr_position += 6;
}

void		ft_sti_dir_dir(t_pc *pc, t_union *un)
{
	int		one;
	int		two;
	int		three;
	int		position;
	uint8_t	*num;

	one = un->map[cp(pc->curr_position + 2)].value;
	if (one <= 16 && one > 0)
	{
		two = (short)ft_get_int(un, cp(pc->curr_position + 3), 2);
		three = (short)ft_get_int(un, cp(pc->curr_position + 5), 2);
		position = (two + three) % IDX_MOD + pc->curr_position;
		position = cp(position);
		num = ft_get_char_from_int(pc, one - 1);
		un->map[cp(position)].value = num[0];
		un->map[cp(position + 1)].value = num[1];
		un->map[cp(position + 2)].value = num[2];
		un->map[cp(position + 3)].value = num[3];
		un->map[cp(position)].color = un->map[pc->curr_position].color;
		un->map[cp(position + 1)].color = un->map[pc->curr_position].color;
		un->map[cp(position + 2)].color = un->map[pc->curr_position].color;
		un->map[cp(position + 3)].color = un->map[pc->curr_position].color;
	}
	pc->curr_position += 7;
}

static void	f(t_union *un, int position, uint8_t *num)
{
	un->map[cp(position)].value = num[0];
	un->map[cp(position + 1)].value = num[1];
	un->map[cp(position + 2)].value = num[2];
	un->map[cp(position + 3)].value = num[3];
}

void		ft_sti_ind_dir(t_pc *pc, t_union *un)
{
	int		one;
	int		two;
	int		three;
	int		position;
	uint8_t	*num;

	one = un->map[cp(pc->curr_position + 2)].value;
	if (one <= 16 && one > 0)
	{
		two = ft_get_int(un, cp(pc->curr_position + ((short)ft_get_int(un,
			cp(pc->curr_position + 3), 2) % IDX_MOD)), 4);
		three = (short)ft_get_int(un, cp(pc->curr_position + 5), 2);
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
	pc->curr_position += 7;
}
