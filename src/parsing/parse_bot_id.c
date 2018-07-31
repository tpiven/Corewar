/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bot_id.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:48:38 by vmiachko          #+#    #+#             */
/*   Updated: 2018/07/27 16:20:36 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"

static int		identical(const int *arr, int n)
{
	int			i;

	i = 0;
	while (i < n - 1)
	{
		if (arr[i] == arr[i + 1] && arr[i] != 0)
			return (0);
		++i;
	}
	return (1);
}

static int		first_check(t_union *un)
{
	t_bot		*tmp;
	int			a[4];
	int			i;
	int			*arr;

	i = 0;
	tmp = un->bot;
	while (tmp)
	{
		a[i] = tmp->id;
		++i;
		tmp = tmp->next;
	}
	arr = ft_bubble_sort(a, i + 1);
	return (identical(arr, i + 1));
}

int				set_bot_id(t_union *un, t_bot *tmp, t_bot *tmp1)
{
	static int	id = -1;

	if (id == -1 && !first_check(un))
		return (-1);
	tmp = un->bot;
	while (tmp)
	{
		if (tmp->id == 0)
		{
			tmp1 = un->bot;
			while (tmp1)
			{
				if (tmp1->id == id)
				{
					--id;
					return (0);
				}
				tmp1 = tmp1->next;
			}
			tmp->id = id;
			--id;
		}
		tmp = tmp->next;
	}
	return (1);
}
