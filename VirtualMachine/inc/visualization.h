/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 14:17:38 by vmiachko          #+#    #+#             */
/*   Updated: 2018/07/28 17:10:27 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZATION_H

# define VISUALIZATION_H

# include "vm.h"

# define XMAX 200
# define YMAX 200

typedef struct	s_vis
{
	int			key;
	int			i;
	int			k;
	int			x;
	int			y;
	WINDOW		*win;
}				t_vis;

void			print_border(WINDOW *win);
void			print_to_right_window(t_union *un);
void			print_pause(t_vis vis);
void			print_winner_v(t_union *un);
void			change_speed(int key, t_union *un);
WINDOW			*init_colors(int *key);
void			print_help();
void			split_print(int b, int c, t_bot *bot);

#endif
