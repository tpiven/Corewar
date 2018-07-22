/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 12:25:51 by vmiachko          #+#    #+#             */
/*   Updated: 2018/07/05 12:26:36 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	VM_H

# define VM_H

#include "libftprintf/ft_printf/ft_printf.h"
# include "op.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ncurses.h>

typedef struct		s_bot
{
	int 			code_length;
	char 			*filename;
	char 			name[PROG_NAME_LENGTH + 1];
	char 			comment[COMMENT_LENGTH + 1];
	int 			size;
	unsigned char	*code; //не забыть занулить массивы
	int 			id;
    int num_live;
    int last_live;
	struct s_bot	*next;
}					t_bot;

typedef	struct		s_pc
{
	int 			curr_position;
	int 			carry;
	int 			creator_id;
	int 			reg[16];
    uint8_t arg[3];
	int 			alive;
	char 			*curr_command;
	int 			number_cycles_to_wait;
	struct s_pc		*next;
	struct s_pc		*prev;
}					t_pc;

typedef struct		s_counter
{
	int i;
	int c;
	int fd;
}					t_counter;

typedef struct 		s_map
{
	int 			color;
	unsigned char	value;
}					t_map;

typedef struct		s_union
{
	t_bot			*bot;
	t_pc			*pc;
	t_map			*map;
	int 			dump;
	int 			argc;
    int cycle;
	t_counter		count;
}					t_union;

t_bot				*bot_push_back(t_bot *head, char *filename, int id);
void				bot_clear_list(t_bot *head);
int 				parse_bot(t_union *un);
t_pc				*pc_push_back(t_pc *head, int pos, int bot_num);
void        *pc_push_front(t_pc *head, t_pc *new);
void				delete_pc(t_pc *head, t_pc *to_del);
void				display_map(t_union *un);
int ft_get_int(t_union *un, int start, int lenght);
uint8_t* ft_get_char_from_int(t_pc *pc, unsigned int num);
void ft_check_codage(uint8_t codage, t_pc *pc);
#endif
