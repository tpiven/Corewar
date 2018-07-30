#include "../../inc/vm.h"
#include "../../inc/commands.h"


void ft_live(t_pc *pc, t_union *un)
{
	int num_player;
	t_bot *tmp;

	pc->alive = 1;
	tmp = un->bot;
	num_player = ft_get_int(un, ft_check_position(pc->curr_position + 1), 4);
	while (tmp)
	{
		if (tmp->id == num_player)
			tmp->last_live = un->cycle;
		if (pc->creator_id == tmp->id)
			++tmp->num_live;
		tmp = tmp->next;
	}
	pc->curr_position = pc->curr_position + 5;
}

void ft_add(t_pc *pc, t_union *un)
{
	uint8_t one;
	uint8_t two;
	uint8_t three;
	unsigned int n;

	ft_check_codage(un->map[ft_check_position(pc->curr_position + 1)].value, un);
	if ((un->map[ft_check_position(pc->curr_position + 1)].value >> 2) != ADD_SUB)
	{
		pc->curr_position += ft_move_wrong_codage(un, pc->curr_command);
		return ;
	}
	one = un->map[ft_check_position(pc->curr_position + 2)].value;
	two = un->map[ft_check_position(pc->curr_position + 3)].value;
	three = un->map[ft_check_position(pc->curr_position + 4)].value;
	if (one <= 16 && one > 0 && two <= 16 && two > 0 && three <= 16 && three > 0)
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

	ft_check_codage(un->map[ft_check_position(pc->curr_position + 1)].value, un);
	if ((un->map[ft_check_position(pc->curr_position + 1)].value >> 2) != ADD_SUB)
	{
		pc->curr_position += ft_move_wrong_codage(un, pc->curr_command);
		return ;
	}
	one = un->map[ft_check_position(pc->curr_position + 2)].value;
	two = un->map[ft_check_position(pc->curr_position + 3)].value;
	three = un->map[ft_check_position(pc->curr_position + 4)].value;
	if (one <= 16 && one > 0 && two <= 16 && two > 0 && three <= 16 && three > 0)
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


void ft_zjmp(t_pc *pc, t_union *un)
{
	if (pc->carry == 1)
	{
		pc->curr_position = pc->curr_position + ((short)ft_get_int(un, ft_check_position(pc->curr_position + 1), 2) % IDX_MOD);
	}
	else
		pc->curr_position += 3;
}



void ft_aff(t_pc *pc, t_union *un)
{
	unsigned char symbol;

	ft_check_codage(un->map[ft_check_position(pc->curr_position + 1)].value, un);
	if ((un->map[ft_check_position(pc->curr_position + 1)].value >> 2) != AFF_COD)
	{
		pc->curr_position += ft_move_wrong_codage(un, pc->curr_command);
		return ;
	}
	if (un->a)
	{
		symbol = pc->reg[un->map[ft_check_position(pc->curr_position + 2)].value] % 256;
		ft_putchar(symbol);
		ft_putchar('\n');
	}
	pc->curr_position = pc->curr_position + 3;
}