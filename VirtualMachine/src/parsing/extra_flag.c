/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 13:18:08 by vmiachko          #+#    #+#             */
/*   Updated: 2018/07/31 13:24:20 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"
#include "../../inc/parsing.h"

int			flag_a(int *i, t_union *un)
{
	if (!un->visual)
		un->a = 1;
	++*i;
	return (1);
}

int			flag_c(int *i, t_union *un)
{
	if (!un->visual)
		un->c = 1;
	++*i;
	return (1);
}

int			flag_p(int *i, t_union *un)
{
	if (!un->visual)
		un->p = 1;
	++*i;
	return (1);
}
