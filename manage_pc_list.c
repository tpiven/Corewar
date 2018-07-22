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

#include "vm.h"


static t_pc	*pc_new(int pos, int bot_num, t_pc *prev)
{
	t_pc	*res;

	if (!(res = (t_pc *)malloc(sizeof(t_pc))))
		return (NULL);
	res->curr_position = pos;
	res->carry = 0;
	res->creator_id = bot_num;
	res->reg[0] = '\0';
	res->alive = 0;
	res->curr_command = NULL;
	res->number_cycles_to_wait = 0;
	res->next = NULL;
	res->prev = NULL;
	return (res);
}

static t_pc    *pc_copy(t_pc *prev, int position)
{
    t_pc    *res;
    
    if (!(res = (t_pc *)malloc(sizeof(t_pc))))
        return (NULL);
    res->curr_position = position;
    res->carry = 0; //перевірити
    res->creator_id = prev->creator_id;
    res->reg[0] = prev->reg[0];
    res->alive = 0;
    res->curr_command = NULL;
    res->number_cycles_to_wait = 0;
    res->next = NULL;
    res->prev = NULL;
    return (res);
}


void		*pc_push_front(t_pc *head, t_pc *new)
{
    new->next = head;
    if (head != NULL)
        head->prev = new;
    head = new;
}

t_pc		*pc_push_back(t_pc *head, int pos, int bot_num)
{
	t_pc	*tmp;
	t_pc	*new;
	t_pc	*prev;

	prev = NULL;
	tmp = head;
	if (!tmp)
		return (pc_new(pos, bot_num, prev));
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	new = pc_new(pos, bot_num, prev);
	tmp->next = new;
	return (head);
}

void		delete_pc(t_pc *head, t_pc *to_del)
{
	t_pc	*tmp;
	t_pc	*prev;
	t_pc	*next;

	prev = NULL;
	tmp = head;
	while (tmp)
	{
		next = tmp->next;
		if (tmp == to_del)
		{
			free(tmp->curr_command);
			free(tmp);
			if (prev)
				prev->next = next;
			if (next)
				next->prev = prev;
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}
