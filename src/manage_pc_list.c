/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_pc_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 10:39:18 by vmiachko          #+#    #+#             */
/*   Updated: 2018/07/06 10:39:20 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vm.h"


static t_pc *clear_arr(t_pc *pc)
{
	int i;

	i = 1;
	while (i < 16)
	{
		pc->reg[i] = 0;
		++i;
	}
	return (pc);
}

t_pc	*pc_new(int pos, int bot_num)
{
	t_pc	*res;

	if (!(res = (t_pc *)malloc(sizeof(t_pc))))
		return (NULL);
	res->curr_position = pos;
	res->carry = 0;
	res->creator_id = bot_num;
	res->reg[0] = res->creator_id;
	res->alive = 0;
	res->curr_command = 0;
	res->number_cycles_to_wait = -1;
	res->next = NULL;
	res->prev = NULL;
	clear_arr(res);
	return (res);
}

t_pc    *pc_copy(t_pc *prev, int position)
{
    int i;
	t_pc    *res;
    i = 0;
	if (!(res = (t_pc *)malloc(sizeof(t_pc))))
		return (NULL);
	res->curr_position = position;
	res->carry = prev->carry; //перевірити
	res->creator_id = prev->creator_id;
    while (i < 16)
    {
        res->reg[i] = prev->reg[i];
        ++i;
    }
	res->alive = 0;
	res->curr_command = 0;
	res->number_cycles_to_wait = -1;
	res->next = NULL;
	res->prev = NULL;
	return (res);
}


t_pc		*pc_push_front(t_pc *head, t_pc *new, t_union *un)
{
	new->next = head;
	++un->procces_number;
	if (head != NULL)
		head->prev = new;
	return (new);
}


t_pc		*delete_pc(t_pc *head, t_pc *to_del, t_union *un)
{
	t_pc	*tmp;
	t_pc	*next;

	tmp = head;
	while (tmp)
	{
		if (tmp == to_del)
		{
			next = tmp->next;
			if (tmp == head)
			{
				--un->procces_number;
				if (next)
					next->prev = NULL;
				return (next);
			}
			if (tmp->prev)
				tmp->prev->next = tmp->next;
			if (tmp->next)
				tmp->next->prev = tmp->prev;
			free(tmp);
			if (un->procces_number == 0)
				head = NULL;
			return (head);
		}
		tmp = tmp->next;
	}
	return (head);
}
