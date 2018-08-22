/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 07:08:59 by rdiederi          #+#    #+#             */
/*   Updated: 2018/07/18 14:15:01 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flag	ft_find_flag3(t_flag lst, int i, const char *fmt)
{
	if (fmt[i] == '+')
		lst.flagplus = 1;
	if (fmt[i] == '-')
		lst.flagminus = 1;
	if (fmt[i] == ' ')
		lst.flagspace = 1;
	if (fmt[i] == '#')
		lst.flaghtag = 1;
	if (fmt[i] == 'h' && fmt[i + 1] != 'h' && fmt[i - 1] != 'h')
		lst.flagh = 1;
	else if (fmt[i] == 'h' && (fmt[i + 1] == 'h' || fmt[i - 1] == 'h'))
		lst.flaghh = 1;
	if (fmt[i] == 'l' && fmt[i + 1] != 'l' && fmt[i - 1] != 'l')
		lst.flagl = 1;
	else if (fmt[i] == 'l' && (fmt[i + 1] == 'l' || fmt[i - 1] == 'l'))
		lst.flagll = 1;
	if (fmt[i] == 'j')
		lst.flagj = 1;
	if (fmt[i] == 'z')
		lst.flagz = 1;
	return (lst);
}

static int		int_len(int i)
{
	int c;

	c = 0;
	while (i >= 10)
	{
		i = i / 10;
		c++;
	}
	return (c);
}

t_flag			ft_find_flag2(t_flag lst, int j, const char *fmt)
{
	int i;

	i = 0;
	while (i <= j && fmt[i])
	{
		if (fmt[i] == '0')
			lst.flagzero = 1;
		else if (fmt[i] >= '1' && fmt[i] <= '9')
		{
			lst.min = ft_atoi(fmt + i);
			i += int_len(lst.min);
		}
		else if (fmt[i] == '.')
		{
			i++;
			lst.prec = ft_atoi(fmt + i);
			lst.prec1 = 1;
			i += int_len(lst.prec);
		}
		else
			lst = ft_find_flag3(lst, i, fmt);
		i++;
	}
	return (lst);
}
