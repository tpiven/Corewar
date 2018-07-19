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
    int num_player;
    
    pc->alive = 1;
    num_player = ft_get_int(un, pc->curr_position + 1, 4);
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
    
    if (un->map[pc->curr_position + 3].value > 16)
        return ;
    
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


void ft_st(t_pc *pc, t_union *un)
{
    int position;
    uint8_t *num;
    uint8_t one;
    uint8_t two;
    
    
    one = un->map[pc->curr_position + 2].value;
    if (one > 16)
        return ;
    ft_check_codage(un->map[pc->curr_position + 1].value, pc);
    if (pc->arg[1] == REG_CODE)
    {
        two = un->map[pc->curr_position + 3].value;
        if (two > 16)
            return ;
        pc->reg[two] = pc->reg[one];
    }
    if (pc->arg[1] == IND_CODE)
    {
        position = pc->curr_position + ((short)ft_get_int(un, pc->curr_position + 1, 2) % IDX_MOD);
        num = ft_get_char_from_int(pc, pc->reg[one]);
        un->map[position].value = num[0];
        un->map[position + 1].value = num[1];
        un->map[position + 2].value = num[2];
        un->map[position + 3].value = num[3];
    }
}

void ft_add(t_pc *pc, t_union *un)
{
    uint8_t one;
    uint8_t two;
    uint8_t three;
    unsigned int n;
    one = un->map[pc->curr_position + 2].value;
    two = un->map[pc->curr_position + 3].value;
    three = un->map[pc->curr_position + 4].value;
    if (one < 16 && two < 16 && three < 16)
    {
        n = pc->reg[one] + pc->reg[two];
        pc->reg[three] = n;
        
        if (n == 0)
            pc->carry = 1;
        else
            pc->carry = 0;
    }
}

void ft_sub(t_pc *pc, t_union *un)
{
    uint8_t one;
    uint8_t two;
    uint8_t three;
    unsigned int n;
    
    one = un->map[pc->curr_position + 2].value;
    two = un->map[pc->curr_position + 3].value;
    three = un->map[pc->curr_position + 4].value;
    if (one < 16 && two < 16 && three < 16)
    {
        n = pc->reg[one] - pc->reg[two];
        pc->reg[three] = n;
        
        if (n == 0)
            pc->carry = 1;
        else
            pc->carry = 0;
    }
}