/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 19:23:01 by vmiachko          #+#    #+#             */
/*   Updated: 2018/07/31 12:14:58 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H

# define COMMANDS_H

# include "vm.h"

# define ADD_SUB   21
# define AFF_COD  16
# define LD_COD(x)	(x != 36 && x != 52)
# define ST_COD(x)  (x != 20 && x != 28)
# define STI_COD(x) (x != 21 &&  x != 25 &&  x != 29 && x != 30)
# define STI(x)  (x != 22 && x != 26)

# define AND_OR(x) ( x != 21 && x != 37 &&  x != 53 && x !=  61 && x != 45)
# define AND_XOR(x) (x != 29 &&  x != 25 && x != 57 && x != 41)
# define LDI_COD(x) (x != 21 && x != 53 && x != 37 && x !=  41)
# define LLDI_COD(x) (x != 57 && x != 25)

int					ft_get_int(t_union *un, int start, int lenght);
uint8_t				*ft_get_char_from_int(t_pc *pc, unsigned int num);
void				ft_check_codage(uint8_t codage, t_union *un);
void				ft_live(t_pc *pc, t_union *un);
void				ft_load(t_pc *pc, t_union *un);
void				ft_st(t_pc *pc, t_union *un);
void				ft_add(t_pc *pc, t_union *un);
void				ft_sub(t_pc *pc, t_union *un);
void				ft_and(t_pc *pc, t_union *un);
void				ft_or(t_pc *pc, t_union *un);
void				ft_xor(t_pc *pc, t_union *un);
void				ft_zjmp(t_pc *pc, t_union *un);
void				ft_ldi(t_pc *pc, t_union *un);
void				ft_sti(t_pc *pc, t_union *un);
void				ft_fork(t_pc *pc, t_union *un);
void				ft_lld(t_pc *pc, t_union *un);
void				ft_lldi(t_pc *pc, t_union *un);
void				ft_lfork(t_pc *pc, t_union *un);
void				ft_aff(t_pc *pc, t_union *un);
t_pc				*pc_copy(t_pc *prev, int position);
void				choose_number_cycles_to_wait(t_pc *pc, t_union *un);
void				choose_commands(t_pc *pc, t_union *un);
int					cp(int position);
void				ft_sti_ind_reg(t_pc *pc, t_union *un);
void				ft_sti_dir_reg(t_pc *pc, t_union *un);
void				ft_sti_reg_dir(t_pc *pc, t_union *un);
void				ft_sti_dir_dir(t_pc *pc, t_union *un);
void				ft_sti_ind_dir(t_pc *pc, t_union *un);
void				ft_and_ind_dir(t_pc *pc, t_union *un);
void				ft_and_reg_dir(t_pc *pc, t_union *un);
void				ft_and_dir_dir(t_pc *pc, t_union *un);
void				ft_and_dir_ind(t_pc *pc, t_union *un);
void				ft_and_reg_ind(t_pc *pc, t_union *un);
void				ft_or_reg_dir(t_pc *pc, t_union *un);
void				ft_or_dir_dir(t_pc *pc, t_union *un);
void				ft_or_ind_dir(t_pc *pc, t_union *un);
void				ft_or_reg_ind(t_pc *pc, t_union *un);
void				ft_or_dir_ind(t_pc *pc, t_union *un);
void				ft_xor_reg_dir(t_pc *pc, t_union *un);
void				ft_xor_dir_dir(t_pc *pc, t_union *un);
void				ft_xor_ind_dir(t_pc *pc, t_union *un);
void				ft_xor_reg_ind(t_pc *pc, t_union *un);
void				ft_xor_dir_ind(t_pc *pc, t_union *un);
int					ft_move_wrong_codage(t_union *un, int command);

#endif
