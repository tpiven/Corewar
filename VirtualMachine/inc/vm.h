/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 12:25:51 by vmiachko          #+#    #+#             */
/*   Updated: 2018/07/31 14:49:46 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H

# define VM_H

# include "../../libft/libft.h"
# include "op.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <ncurses.h>
# include <time.h>

typedef struct		s_bot
{
	int				code_length;
	char			*filename;
	char			name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
	int				last_live;
	int				num_live;
	int				size;
	unsigned char	*code;
	int				id;
	struct s_bot	*next;
}					t_bot;

typedef	struct		s_pc
{
	int				curr_position;
	int				id;
	int				carry;
	int				creator_id;
	unsigned int	reg[16];
	int				alive;
	int				curr_command;
	int				number_cycles_to_wait;
	struct s_pc		*next;
	struct s_pc		*prev;
}					t_pc;

typedef struct		s_counter
{
	int i;
	int c;
	int fd;
}					t_counter;

typedef struct		s_map
{
	int				color;
	unsigned char	value;
	int				cursor;
}					t_map;

typedef struct		s_union
{
	t_bot			*bot;
	t_pc			*pc;
	t_map			*map;
	int				dump;
	int				a;
	int				argc;
	t_counter		count;
	int				cycle;
	int				cycle_to_die;
	int				checks;
	int				visual;
	uint8_t			arg[3];
	int				bots_number;
	int				procces_number;
	int				k;
	useconds_t		speed;
	int				speed_v;
	int				p;
	int				c;
	int				num_plives;
	int				finish;
	uint8_t			ab[4];
	int				winner;
}					t_union;

t_bot				*bot_push_back(t_bot *head, char *filename, int id);
void				bot_clear_list(t_bot *head);
int					parse_bot(t_union *un);
t_pc				*pc_push_back(t_pc *head, int pos, int bot_num);
t_pc				*pc_push_front(t_pc *head, t_pc *new, t_union *un);
t_pc				*delete_pc(t_pc *head, t_pc *to_del, t_union *un);
void				display_map(t_union *un);
void				corewar(t_union *un);
t_pc				*pc_new(int pos, int bot_num);
void				move_code_to_map(t_union *un, int color);
void				update_pc(t_union *un);
void				initialize_map(t_union *un);
void				move_code_to_map(t_union *un, int color);
void				initialize_map(t_union *un);
void				check_if_pc_alive(t_union *un);
void				decrease_cycle_to_die(t_union *un);
void				clear_num_live(t_union *un);
void				pc_clear_list(t_pc *head);
void				pc_sort_ascending(t_union *un);
int					choose_winner(t_union *un);
void				without_visual(t_union *un);
void				print_winner(t_union *un);
void				without_visual(t_union *un);
void				print_players_info(t_union *un);

#endif
