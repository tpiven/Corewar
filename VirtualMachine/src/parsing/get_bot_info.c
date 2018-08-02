/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bot_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 15:41:03 by vmiachko          #+#    #+#             */
/*   Updated: 2018/07/30 14:58:55 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"
#include "../../inc/parsing.h"

int					get_bot_name(const int fd, t_bot **tmp)
{
	int				r;

	r = (int)read(fd, &(*tmp)->name, 128);
	if (r < 128)
	{
		ft_printf(RED"Wrong bot name.\n"RESET);
		return (0);
	}
	return (1);
}

int					get_bot_size(const int fd, t_bot **tmp)
{
	int				r;
	unsigned char	buf[8];

	r = (int)read(fd, &buf, 4);
	if (r < 4)
	{
		ft_printf(RED"Wrong bot size.\n"RESET);
		return (0);
	}
	(*tmp)->size = 0;
	(*tmp)->size += buf[3] +
		(buf[2] << 8) +
			(buf[1] << 16) +
				(buf[0] << 24);
	return (1);
}

int					get_bot_comment(const int fd, t_bot **tmp)
{
	int				r;

	r = (int)read(fd, &(*tmp)->comment, 2048);
	if (r < 2048)
	{
		ft_printf(RED"Wrong bot comment.\n"RESET);
		return (0);
	}
	return (1);
}

int					get_bot_code(const int fd, t_bot **tmp)
{
	unsigned char	buf[2];
	int				ret;
	int				flag;
	int				all;

	flag = 0;
	all = 0;
	while ((ret = (int)read(fd, buf, 1)) > 0)
	{
		if (buf[0] != '\0' || flag)
		{
			buf[ret] = '\0';
			(*tmp)->code[all] = buf[0];
			flag = 1;
			if (++all > CHAMP_MAX_SIZE)
			{
				error_length(tmp, fd, buf, all);
				ft_printf(RED"Wrong bot code.\n"RESET);
				return (0);
			}
		}
	}
	(*tmp)->code_length = all;
	return (1);
}

int					check_size_is_true(t_bot bot)
{
	if (bot.code_length != bot.size)
	{
		ft_printf(RED"Wrong real code size!\n"RESET);
		return (0);
	}
	return (1);
}
