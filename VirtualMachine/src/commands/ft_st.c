/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 16:31:20 by vmiachko          #+#    #+#             */
/*   Updated: 2018/07/30 16:33:16 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"
#include "../../inc/commands.h"

void		ft_st_reg(t_pc *pc, t_union *un)
{
	uint8_t	one;
	uint8_t	two;

	one = un->map[cp(pc->curr_position + 2)].value;
	two = un->map[cp(pc->curr_position + 3)].value;
	if (two > 16 || two == 0 || one > 16 || one == 0)
	{
		pc->curr_position = pc->curr_position + 4;
		return ;
	}
	pc->reg[two - 1] = pc->reg[one - 1];
	pc->curr_position = pc->curr_position + 4;
}

void		ft_st_ind(t_pc *pc, t_union *un)
{
	int		position;
	uint8_t	one;

	one = un->map[cp(pc->curr_position + 2)].value;
	if (one > 16 || one == 0)
	{
		pc->curr_position = pc->curr_position + 5;
		return ;
	}
	position = pc->curr_position + ((short)ft_get_int(un,
		cp(pc->curr_position + 3), 2) % IDX_MOD);
	position = cp(position);
	ft_get_char_from_int(pc, one - 1, un);
	un->map[position].value = un->ab[0];
	un->map[position].color = un->map[pc->curr_position].color;
	un->map[cp(position + 1)].value = un->ab[1];
	un->map[cp(position + 1)].color = un->map[pc->curr_position].color;
	un->map[cp(position + 2)].value = un->ab[2];
	un->map[cp(position + 2)].color = un->map[pc->curr_position].color;
	un->map[cp(position + 3)].color = un->map[pc->curr_position].color;
	un->map[cp(position + 3)].value = un->ab[3];
	pc->curr_position = pc->curr_position + 5;
}

void		ft_st(t_pc *pc, t_union *un)
{
	ft_check_codage(un->map[cp(pc->curr_position + 1)].value, un);
	if (ST_COD(un->map[cp(pc->curr_position + 1)].value >> 2))
	{
		pc->curr_position += ft_move_wrong_codage(un, pc->curr_command);
		return ;
	}
	if (un->arg[1] == REG_CODE)
		ft_st_reg(pc, un);
	if (un->arg[1] == IND_CODE)
		ft_st_ind(pc, un);
}
