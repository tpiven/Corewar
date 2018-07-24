/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 14:39:07 by vmiachko          #+#    #+#             */
/*   Updated: 2018/07/05 14:39:10 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "../../inc/vm.h"

static int is_number(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		++i;
	}
	return (1);
}

static int if_file(t_union *un, char *num, char *filename)
{
	int id;
	if (un->count.c >= 4)
		return (0);
	close(un->count.fd);
	if (num)
		id = ft_atoi(num);
	else
		id = 0;
	un->bot = bot_push_back(un->bot, filename, id);

	++un->count.c;
	++un->count.i;
	return (1);
}

static void	visualisation(int *i, t_union *un)
{
	un->visual = 1;
	++*i;
}

static int flag_n(t_union *un, char **argv)
{
	if (un->count.i + 2 >= un->argc || !is_number(argv[un->count.i + 1]))
		return (0);
	un->count.i += 2;
	if ((un->count.fd = open(argv[un->count.i], O_RDONLY)) < 0)
		return (0);
	else
	{
		if (!if_file(un, argv[un->count.i - 1], argv[un->count.i]))
			return (-1);
	}
	return (1);
}


int		check_if_input_correct(char **argv, t_union *un)
{

	while (un->count.i < un->argc)
	{

		if (!ft_strcmp(argv[un->count.i], "-dump"))
		{
			if (un->count.i + 1 >= un->argc || !is_number(argv[un->count.i + 1])
					|| ft_atoi(argv[un->count.i + 1]) < 0)
				return (0);
			un->dump = ft_atoi(argv[un->count.i + 1]);
			un->count.i += 2;
		}
		else if (!ft_strcmp(argv[un->count.i], "-n"))
		{
			if (!flag_n(un, argv))
				return (0);
		}
		else if ((un->count.fd = open(argv[un->count.i], O_RDONLY)) > 0)
		{
			if (!if_file(un, NULL, argv[un->count.i]))
				return (-1);
		}
		else if (!ft_strcmp("-v", argv[un->count.i]))
			visualisation(&un->count.i, un);
		else
			return (0);
	}
	return (un->count.c == 0 ? 0 : 1);
}
