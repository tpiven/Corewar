/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 12:31:47 by vmiachko          #+#    #+#             */
/*   Updated: 2018/07/31 12:15:40 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H

# define PARSING_H

# include "vm.h"

int					parsing(int argc, char **argv, t_union *un);
int					check_if_input_correct(char **argv, t_union *un);
int					set_bot_id(t_union *un, t_bot *tmp, t_bot *tmp1);
int					get_bot_name(const int fd, t_bot **tmp);
int					get_bot_size(const int fd, t_bot **tmp);
int					get_bot_comment(const int fd, t_bot **tmp);
int					get_bot_code(const int fd, t_bot **tmp);
int					check_size_is_true(t_bot bot);
int					flag_visualisation(int *i, t_union *un);
int					flag_a(int *i, t_union *un);
int					check_arg(t_union *un, char **argv);
void				error_length(t_bot **tmp, int fd,
	unsigned char buf[2], int all);
int					flag_c(int *i, t_union *un);
int					flag_p(int *i, t_union *un);

#endif
