/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 20:36:40 by vmiachko          #+#    #+#             */
/*   Updated: 2018/04/23 18:19:57 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_abs(double v)
{
	if (v < 0)
		v *= -1;
	return (v);
}
