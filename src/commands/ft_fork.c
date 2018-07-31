/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 15:56:27 by vmiachko          #+#    #+#             */
/*   Updated: 2018/07/30 15:57:07 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"
#include "../../inc/commands.h"

void		ft_fork(t_pc *pc, t_union *un)
{
	int		position;
	t_pc	*new;

	position = pc->curr_position +
		((short)ft_get_int(un, pc->curr_position + 1, 2) % IDX_MOD);
	position = cp(position);
	new = pc_copy(pc, position);
	un->pc = pc_push_front(un->pc, new, un);
	pc->curr_position = pc->curr_position + 3;
}

void		ft_lfork(t_pc *pc, t_union *un)
{
	int		position;
	t_pc	*new;

	position = pc->curr_position +
		((short)ft_get_int(un, pc->curr_position + 1, 2));
	position = cp(position);
	new = pc_copy(pc, position);
	un->pc = pc_push_front(un->pc, new, un);
	pc->curr_position = pc->curr_position + 3;
}
