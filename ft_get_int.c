/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpiven <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 17:02:04 by tpiven            #+#    #+#             */
/*   Updated: 2018/07/16 17:02:12 by tpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int ft_get_int(t_union *un, int start, int lenght)
{
    int ar;
    
    if (lenght == 4)
    {
        ar = (un->map[start].value << 24);
        ar = ar | (un->map[start+1].value << 16);
        ar = ar | (un->map[start+2].value << 8);
        ar = ar | (un->map[start+3].value);
    }
    if (lenght == 2)
    {
        ar = (un->map[start].value << 8);
        ar = ar | (un->map[start+1].value);
    }
    return (ar);
}