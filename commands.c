#include "vm.h"


void ft_live(t_pc *pc, t_union *un)
{
    int num_player;
    t_bot *tmp;
    
    pc->alive = 1;
    tmp = un->bot;
    num_player = ft_get_int(un, pc->curr_position + 1, 4);
    while (tmp != NULL)
    {
        if (tmp->id == num_player)
           tmp->last_live = un->cycle;
        if (pc->creator_id == tmp->id)
             tmp->num_live += 1;
       tmp = tmp->next;
    }
    pc->curr_position = pc->curr_position + 5;
}

void ft_load(t_pc *pc, t_union *un)
{
    unsigned int n;
    int plus;
    ft_check_codage(un->map[pc->curr_position + 1].value, un);
    if (un->arg[0] == DIR_CODE)
    {
        plus = 6;
        n = (unsigned int)ft_get_int(un, pc->curr_position + 2, 4);
    }
    if (un->arg[0] == IND_CODE)
    {
        plus = 4;
        n = (unsigned int)ft_get_int(un, (pc->curr_position + ((short)ft_get_int(un, pc->curr_position + 2, 2) % IDX_MOD)), 4);
    }
    if (un->map[pc->curr_position + plus].value > 16)
        return ;
    pc->reg[un->map[pc->curr_position + plus].value - 1] = n;
    if (n == 0)
        pc->carry = 1;
    else
        pc->carry = 0;
    pc->curr_position = pc->curr_position + plus + 1;
}


void ft_st(t_pc *pc, t_union *un)
{
    int position;
    int plus;
    uint8_t *num;
    uint8_t one;
    uint8_t two;
    
    
    one = un->map[pc->curr_position + 2].value;
    if (one > 16)
        return ;
    ft_check_codage(un->map[pc->curr_position + 1].value, un);
    if (un->arg[1] == REG_CODE)
    {
        two = un->map[pc->curr_position + 3].value;
        if (two > 16)
            return ;
        pc->reg[two] = pc->reg[one];
        plus = 4;
    }
    if (un->arg[1] == IND_CODE)
    {
        position = pc->curr_position + ((short)ft_get_int(un, pc->curr_position + 3, 2) % IDX_MOD);
        num = ft_get_char_from_int(pc, one - 1);
        un->map[position].value = num[0];
        un->map[position + 1].value = num[1];
        un->map[position + 2].value = num[2];
        un->map[position + 3].value = num[3];
        plus = 5;
    }
    pc->curr_position = pc->curr_position + plus;
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
        n = pc->reg[one - 1] + pc->reg[two - 1];
        pc->reg[three - 1] = n;
        
        if (n == 0)
            pc->carry = 1;
        else
            pc->carry = 0;
    }
    pc->curr_position = pc->curr_position + 5;
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
        n = pc->reg[one - 1] - pc->reg[two - 1];
        pc->reg[three - 1] = n;
        
        if (n == 0)
            pc->carry = 1;
        else
            pc->carry = 0;
    }
    pc->curr_position = pc->curr_position + 5;
}

void ft_and(t_pc *pc, t_union *un)
{
    unsigned int one;
    unsigned int two;
    int plus;
    ft_check_codage(un->map[pc->curr_position + 1].value, un);
    if (un->arg[0] == REG_CODE)
    {
        one = pc->reg[un->map[pc->curr_position + 2].value - 1];
        plus = 3;
    }
    if (un->arg[0] == DIR_CODE)
    {
        one = (unsigned int)ft_get_int(un, pc->curr_position + 2, 4);
        plus = 6;
    }
    if (un->arg[0] == IND_CODE)
    {
        one = (unsigned int)ft_get_int(un, (pc->curr_position + ((short)ft_get_int(un, pc->curr_position + 2, 2) % IDX_MOD)), 4);
        plus = 4;
    }
    if (un->arg[1] == REG_CODE)
    {
        two = pc->reg[un->map[pc->curr_position + plus].value - 1];
        plus += 1;
    }
    if (un->arg[1] == DIR_CODE)
    {
        two = (unsigned int)ft_get_int(un, pc->curr_position + plus, 4);
        plus += 4;
    }
    if (un->arg[1] == IND_CODE)
    {
        two = (unsigned int)ft_get_int(un, (pc->curr_position + ((short)ft_get_int(un, pc->curr_position + plus, 2) % IDX_MOD)), 4);
        plus += 2;
    }
    pc->reg[un->map[pc->curr_position + plus].value - 1] = one & two;
    if ( pc->reg[un->map[pc->curr_position + plus].value - 1] == 0)
        pc->carry = 1;
    else
        pc->carry = 0;
    pc->curr_position = pc->curr_position + plus + 1;
}





void ft_or(t_pc *pc, t_union *un)
{
    unsigned int one;
    unsigned int two;
    int plus;
    ft_check_codage(un->map[pc->curr_position + 1].value, un);
    if (un->arg[0] == REG_CODE)
    {
        one = pc->reg[un->map[pc->curr_position + 2].value - 1];
        plus = 3;
    }
    if (un->arg[0] == DIR_CODE)
    {
        one = (unsigned int)ft_get_int(un, pc->curr_position + 2, 4);
        plus = 6;
    }
    if (un->arg[0] == IND_CODE)
    {
        one = (unsigned int)ft_get_int(un, (pc->curr_position + ((short)ft_get_int(un, pc->curr_position + 2, 2) % IDX_MOD)), 4);
        plus = 4;
    }
    if (un->arg[1] == REG_CODE)
    {
        two = pc->reg[un->map[pc->curr_position + plus].value - 1];
        plus += 1;
    }
    if (un->arg[1] == DIR_CODE)
    {
        two = (unsigned int)ft_get_int(un, pc->curr_position + plus, 4);
        plus += 4;
    }
    if (un->arg[1] == IND_CODE)
    {
        two = (unsigned int)ft_get_int(un, (pc->curr_position + ((short)ft_get_int(un, pc->curr_position + plus, 2) % IDX_MOD)), 4);
        plus += 2;
    }
    pc->reg[un->map[pc->curr_position + plus].value - 1] = one | two;
    if ( pc->reg[un->map[pc->curr_position + plus].value - 1] == 0)
        pc->carry = 1;
    else
        pc->carry = 0;
    pc->curr_position = pc->curr_position + plus + 1;
}

void ft_xor(t_pc *pc, t_union *un)
{
    unsigned int one;
    unsigned int two;
    int plus;
    ft_check_codage(un->map[pc->curr_position + 1].value, un);
    if (un->arg[0] == REG_CODE)
    {
        one = pc->reg[un->map[pc->curr_position + 2].value - 1];
        plus = 3;
    }
    if (un->arg[0] == DIR_CODE)
    {
        one = (unsigned int)ft_get_int(un, pc->curr_position + 2, 4);
        plus = 6;
    }
    if (un->arg[0] == IND_CODE)
    {
        one = (unsigned int)ft_get_int(un, (pc->curr_position + ((short)ft_get_int(un, pc->curr_position + 2, 2) % IDX_MOD)), 4);
        plus = 4;
    }
    if (un->arg[1] == REG_CODE)
    {
        two = pc->reg[un->map[pc->curr_position + plus].value - 1];
        plus += 1;
    }
    if (un->arg[1] == DIR_CODE)
    {
        two = (unsigned int)ft_get_int(un, pc->curr_position + plus, 4);
        plus += 4;
    }
    if (un->arg[1] == IND_CODE)
    {
        two = (unsigned int)ft_get_int(un, (pc->curr_position + ((short)ft_get_int(un, pc->curr_position + plus, 2) % IDX_MOD)), 4);
        plus += 2;
    }
    pc->reg[un->map[pc->curr_position + plus].value - 1] = one ^ two;
    if (pc->reg[un->map[pc->curr_position + plus].value - 1] == 0)
        pc->carry = 1;
    else
        pc->carry = 0;
    pc->curr_position = pc->curr_position + plus + 1;
}

void ft_zjmp(t_pc *pc, t_union *un)
{
    if (pc->carry == 1)
    {
        pc->curr_position = pc->curr_position + ((short)ft_get_int(un, pc->curr_position + 2, 2) % IDX_MOD);
    }
    else
        pc->curr_position = pc->curr_position + 3;
}

void ft_ldi(t_pc *pc, t_union *un)
{
    int plus;
    int one;
    int two;
    ft_check_codage(un->map[pc->curr_position + 1].value, un);
    if (un->arg[0] == REG_CODE)
    {
        one = pc->reg[un->map[pc->curr_position + 2].value - 1];
        plus = 3;
    }
    if (un->arg[0] == DIR_CODE)
    {
        one = (short)ft_get_int(un, pc->curr_position + 2, 2);
        plus = 4;
    }
    if (un->arg[0] == IND_CODE)
    {
        one = (unsigned int)ft_get_int(un, (pc->curr_position + ((short)ft_get_int(un, pc->curr_position + 2, 2) % IDX_MOD)), 4);
        plus = 4;
    }
    if (un->arg[1] == REG_CODE)
    {
        two = pc->reg[un->map[pc->curr_position + plus].value - 1];
        plus += 1;
    }
    if (un->arg[1] == DIR_CODE)
    {
        two = (short)ft_get_int(un, pc->curr_position + plus, 2);
        plus += 2;
    }
    pc->reg[un->map[pc->curr_position + plus].value - 1] = (unsigned int)ft_get_int(un, (one + two) % IDX_MOD + pc->curr_position, 4);
    pc->curr_position = pc->curr_position + plus + 1;
}

void ft_sti(t_pc *pc, t_union *un)
{
    int plus;
    int one;
    int two;
    int position;
    uint8_t *num;
    ft_check_codage(un->map[pc->curr_position + 1].value, un);
    if (un->arg[1] == REG_CODE)
    {
        one = pc->reg[un->map[pc->curr_position + 3].value - 1];
        plus = 4;
    }
    if (un->arg[1] == DIR_CODE)
    {
        one = (short)ft_get_int(un, pc->curr_position + 3, 2);
        plus = 5;
    }
    if (un->arg[1] == IND_CODE)
    {
        one = (unsigned int)ft_get_int(un, (pc->curr_position + ((short)ft_get_int(un, pc->curr_position + 3, 2) % IDX_MOD)), 4);
        plus = 5;
    }
    if (un->arg[2] == REG_CODE)
    {
        two = pc->reg[un->map[pc->curr_position + plus].value - 1];
        plus += 1;
    }
    if (un->arg[2] == DIR_CODE)
    {
        two = (short)ft_get_int(un, pc->curr_position + plus, 2);
        plus += 2;
    }
    position = (one + two) % IDX_MOD + pc->curr_position;
    num = ft_get_char_from_int(pc, un->map[pc->curr_position + 2].value - 1);
    un->map[position].value = num[0];
    un->map[position + 1].value = num[1];
    un->map[position + 2].value = num[2];
    un->map[position + 3].value = num[3];
    pc->curr_position = pc->curr_position + plus;
}



void ft_fork(t_pc *pc, t_union *un)
{
    int position;
    t_pc *new;
    
    position = pc->curr_position + ((short)ft_get_int(un, pc->curr_position + 1, 2) % IDX_MOD);
    new = pc_copy(pc, position);
    un->pc = pc_push_front(un->pc, new);
    pc->curr_position = pc->curr_position + 3;
}

void ft_lld(t_pc *pc, t_union *un)
{
    unsigned int n;
    int plus;
    ft_check_codage(un->map[pc->curr_position + 1].value, un);
    if (un->arg[0] == DIR_CODE)
    {
        plus = 5;
        n = (unsigned int)ft_get_int(un, pc->curr_position, 4);
    }
    if (un->arg[0] == IND_CODE)
    {
        plus = 3;
        n = (unsigned int)ft_get_int(un, (pc->curr_position + ((short)ft_get_int(un, pc->curr_position + 1, 2))), 4);
    }
    if (un->map[pc->curr_position + plus].value > 16)
        return ;
    pc->reg[un->map[pc->curr_position + plus].value - 1] = n;
    if (n == 0)
        pc->carry = 1;
    else
        pc->carry = 0;
    pc->curr_position = pc->curr_position + plus + 1;
}

void ft_lldi(t_pc *pc, t_union *un)
{
    int plus;
    int one;
    int two;
    ft_check_codage(un->map[pc->curr_position + 1].value, un);
    if (un->arg[0] == REG_CODE)
    {
        one = pc->reg[un->map[pc->curr_position + 2].value - 1];
        plus = 3;
    }
    if (un->arg[0] == DIR_CODE)
    {
        one = (short)ft_get_int(un, pc->curr_position + 2, 2);
        plus = 4;
    }
    if (un->arg[0] == IND_CODE)
    {
        one = (unsigned int)ft_get_int(un, (pc->curr_position + ((short)ft_get_int(un, pc->curr_position + 2, 2) % IDX_MOD)), 4);
        plus = 4;
    }
    if (un->arg[1] == REG_CODE)
    {
        two = pc->reg[un->map[pc->curr_position + plus].value - 1];
        plus += 1;
    }
    if (un->arg[1] == DIR_CODE)
    {
        two = (short)ft_get_int(un, pc->curr_position + plus, 2);
        plus += 2;
    }
    pc->reg[un->map[pc->curr_position + plus].value - 1] = (unsigned int)ft_get_int(un, (one + two) + pc->curr_position, 4);
    if (pc->reg[un->map[pc->curr_position + plus].value - 1] == 0)
        pc->carry = 1;
    else
        pc->carry = 0;
    pc->curr_position = pc->curr_position + plus + 1;
}

void ft_lfork(t_pc *pc, t_union *un)
{
    int position;
    t_pc *new;
    
    position = pc->curr_position + ((short)ft_get_int(un, pc->curr_position + 1, 2));
    new = pc_copy(pc, position);
    un->pc = pc_push_front(un->pc, new);
    pc->curr_position = pc->curr_position + 3;
}

void ft_aff(t_pc *pc, t_union *un)
{
    unsigned char symbol;
    
    symbol = pc->reg[un->map[pc->curr_position + 2].value] % 256;
    ft_putchar(symbol);
    pc->curr_position = pc->curr_position + 3;
}
