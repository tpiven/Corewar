/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_pc_list2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 14:53:40 by vmiachko          #+#    #+#             */
/*   Updated: 2018/07/27 17:33:32 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"

void		pc_clear_list(t_pc *head)
{
	t_pc	*tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

static void	my_swap(t_pc *tmp)
{
	int		id;
	int		curr_pos;

	id = (tmp)->creator_id;
	(tmp)->creator_id = (tmp)->next->creator_id;
	(tmp)->next->creator_id = id;
	(tmp)->reg[0] = (tmp)->creator_id;
	(tmp)->next->reg[0] = (tmp)->next->creator_id;
	curr_pos = (tmp)->curr_position;
	(tmp)->curr_position = (tmp)->next->curr_position;
	(tmp)->next->curr_position = curr_pos;
}

void		pc_sort_ascending(t_union *un)
{
	t_pc	*tmp1;
	t_pc	*tmp2;

	tmp1 = un->pc;
	while (tmp1)
	{
		tmp2 = un->pc;
		while (tmp2->next)
		{
			if (tmp2->creator_id > tmp2->next->creator_id)
			{
				my_swap(tmp2);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}
