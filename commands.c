/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpiven <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 17:55:40 by tpiven            #+#    #+#             */
/*   Updated: 2018/07/19 17:55:41 by tpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"


void ft_live(t_pc *pc, t_union *un)
{
    pc->alive = 1;
    int num_player = ft_get_int(un, pc->curr_position + 1, 4);
    while (un->bot->next != NULL)
    {
        if (un->bot->id == num_player)
           un->bot->last_live = un->cycle;
        if (pc->creator_id == un->bot->id)
             un->bot->num_live += 1;
       un->bot = un->bot->next;
    }
}

void ft_load(t_pc *pc, t_union *un)
{
    unsigned int n;
    ft_check_codage(un->map[pc->curr_position + 1].value, pc);
    if (pc->arg[0] == DIR_CODE)
    {
        n = (unsigned int)ft_get_int(un, pc->curr_position, 4);
    }
    if (pc->arg[0] == IND_CODE)
    {
        n = (unsigned int)ft_get_int(un, (pc->curr_position + ((short)ft_get_int(un, pc->curr_position + 1, 2) % IDX_MOD)), 4);
    }
    pc->reg[un->map[pc->curr_position + 3].value] = n;
    if (n == 0)
        pc->carry = 1;
    else
        pc->carry = 0;
}
