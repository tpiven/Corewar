/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_pc_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 10:39:18 by vmiachko          #+#    #+#             */
/*   Updated: 2018/07/30 14:53:38 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"

static t_pc			*clear_arr(t_pc *pc)
{
	int			i;

	i = 1;
	while (i < 16)
	{
		pc->reg[i] = 0;
		++i;
	}
	return (pc);
}

t_pc				*pc_new(int pos, int bot_num)
{
	t_pc			*res;

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

t_pc				*pc_copy(t_pc *prev, int position)
{
	int				i;
	t_pc			*res;

	i = 0;
	if (!(res = (t_pc *)malloc(sizeof(t_pc))))
		return (NULL);
	res->curr_position = position;
	res->carry = prev->carry;
	res->creator_id = prev->creator_id;
	while (i < 16)
	{
		res->reg[i] = prev->reg[i];
		++i;
	}
	res->alive = prev->alive;
	res->curr_command = 0;
	res->number_cycles_to_wait = -1;
	res->next = NULL;
	res->prev = NULL;
	return (res);
}

t_pc				*pc_push_front(t_pc *head, t_pc *new, t_union *un)
{
	static clock_t	end = 0;
	static int		i = 0;
	clock_t			start;

	start = clock();
	if (un->visual && (start - end) > 10)
	{
		system("afplay music/new.mp3 &");
		end = clock();
	}
	new->next = head;
	new->id = i + 1;
	++i;
	if (un->p && un->cycle > 0)
		ft_printf("New process %d created\n", new->id);
	++un->procces_number;
	if (head != NULL)
		head->prev = new;
	return (new);
}

t_pc				*delete_pc(t_pc *head, t_pc *to_del, t_union *un)
{
	t_pc			*tmp;
	t_pc			*next;

	tmp = head;
	while (tmp)
	{
		if (tmp == to_del)
		{
			next = tmp->next;
			if (tmp == head)
			{
				next ? next->prev = NULL : 0;
				free(tmp);
				return (next);
			}
			--un->procces_number;
			tmp->prev ? tmp->prev->next = tmp->next : 0;
			tmp->next ? tmp->next->prev = tmp->prev : 0;
			free(tmp);
			un->procces_number == 0 ? head = NULL : 0;
			return (head);
		}
		tmp = tmp->next;
	}
	return (head);
}
