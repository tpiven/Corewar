//
//  ft_get_int.c
//  corewar
//
//  Created by Tetiana PIVEN on 7/18/18.
//  Copyright © 2018 Tetiana PIVEN. All rights reserved.
//

#include "../../inc/vm.h"

int ft_move_wrong_codage(t_union *un, int command)
{
    int plus;
    int i;
	int j;

	if (command == 2 || command == 3 || command == 13)
		j = 2;
	else if (command == 16)
		j = 1;
	else
		j = 3;
    i = 0;
    plus = 2;
    while (i < j)
    {
        if (un->arg[i] == REG_CODE)
            plus += 1;
        else if (un->arg[i] == DIR_CODE)
		{
			if (command == 10 || command == 11 || command == 14)
				plus += 2;
			else
				plus += 4;
		}
        else if (un->arg[i] == IND_CODE)
            plus += 2;
        i++;
    }
    return (plus);
}


int ft_check_position(int position)
{
	if (position >= MEM_SIZE)
		position %= MEM_SIZE;
	else if (position < 0)
		position += MEM_SIZE;
	return (position);
}


int ft_get_int(t_union *un, int start, int lenght)
{
    int ar;

    ar = 0;
    if (lenght == 4)
    {
        ar = (un->map[ft_check_position(start)].value << 24);
        ar = ar | (un->map[ft_check_position(start+1)].value << 16);
        ar = ar | (un->map[ft_check_position(start+2)].value << 8);
        ar = ar | (un->map[ft_check_position(start+3)].value);

    }
    if (lenght == 2)
    {
        ar = (un->map[start].value << 8);
        ar = ar | (un->map[ft_check_position(start+1)].value);
    }
    return (ar);
}

uint8_t* ft_get_char_from_int(t_pc *pc, unsigned int num)
{
    uint8_t *arg;
    int k;
    
    arg = malloc(sizeof(unsigned char) * 4);
    k = pc->reg[num];
    arg[0] = k >> 24;
    arg[1] = (k & 0xFF0000) >> 16;
    arg[2] = (k & 0xFF00) >> 8;
    arg[3] = k & 0xFF;
    return (arg);
}


void ft_check_codage(uint8_t codage, t_union *un)
{
    un->arg[0] = codage >> 6;
    un->arg[1] = (codage & 0x30) >> 4;
    un->arg[2] = (codage & 0xC) >> 2;
}
