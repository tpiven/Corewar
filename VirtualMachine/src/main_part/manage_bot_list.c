/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_bot_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 10:39:11 by vmiachko          #+#    #+#             */
/*   Updated: 2018/07/27 17:27:49 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"

static t_bot		*bot_new(char *filename, int id)
{
	t_bot			*res;

	if (!(res = (t_bot *)malloc(sizeof(t_bot))))
		return (NULL);
	if (!(res->filename = (char *)ft_memalloc(ft_strlen(filename) + 1)))
		return (NULL);
	res->code = (unsigned char*)ft_memalloc(700 * sizeof(unsigned char) + 10);
	res->filename = ft_strcpy(res->filename, filename);
	res->size = 0;
	res->id = id;
	res->num_live = 0;
	res->last_live = 0;
	res->code_length = 0;
	res->next = NULL;
	return (res);
}

t_bot				*bot_push_back(t_bot *head, char *filename, int id)
{
	t_bot			*tmp;
	t_bot			*new;

	tmp = head;
	if (!tmp)
		return (bot_new(filename, id));
	while (tmp->next)
		tmp = tmp->next;
	new = bot_new(filename, id);
	tmp->next = new;
	return (head);
}

void				bot_clear_list(t_bot *head)
{
	t_bot		*tmp;

	while (head)
	{
		tmp = head->next;
		free(head->filename);
		free(head->code);
		free(head);
		head = tmp;
	}
}
