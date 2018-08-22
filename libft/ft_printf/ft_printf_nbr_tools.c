/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 10:13:43 by rdiederi          #+#    #+#             */
/*   Updated: 2018/07/30 10:13:55 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag			left_marging(t_flag lst, int i, intmax_t nb)
{
	if ((lst.flagspace || lst.flagplus) && nb >= 0)
	{
		if (lst.min)
			lst.min--;
		if (lst.flagplus && lst.flagzero && !lst.prec1)
			ft_buffer("+", 1, 0);
		else if (lst.flagspace && !lst.flagplus)
			ft_buffer(" ", 1, 0);
	}
	if (lst.flagminus)
		return (lst);
	if (lst.flagzero && !lst.prec1)
		while (i < lst.min)
		{
			ft_buffer("0", 1, 0);
			i++;
		}
	else
		while (i < lst.min)
		{
			ft_buffer(" ", 1, 0);
			i++;
		}
	return (lst);
}

void			right_marging(t_flag lst, size_t len)
{
	int i;

	if (!lst.flagminus)
		return ;
	i = len;
	while (i < lst.min)
	{
		ft_buffer(" ", 1, 0);
		i++;
	}
}

void			left_sign(t_flag lst, int len, intmax_t nb)
{
	if ((nb < 0 && !lst.flagzero) || (nb < 0 && lst.prec1))
		ft_buffer("-", 1, 0);
	if (((lst.flagplus && !lst.flagzero) || (lst.flagplus && lst.prec1))
				&& nb >= 0)
		ft_buffer("+", 1, 0);
	while (len < lst.prec)
	{
		len++;
		ft_buffer("0", 1, 0);
	}
}
