/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 07:08:59 by rdiederi          #+#    #+#             */
/*   Updated: 2018/07/25 18:55:57 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_error3(t_flag lst, int i, const char *fmt)
{
	int j;

	j = 0;
	ft_buffer((char*)fmt + i, 1, 0);
	while (j < lst.min - 1)
	{
		ft_buffer(" ", 1, 0);
		j++;
	}
	return (j + 1);
}

static int	ft_print_error2(t_flag lst, int j, const char *fmt)
{
	int i;

	i = 0;
	if (lst.flagzero && !lst.flagminus)
		while (i < lst.min - 1)
		{
			ft_buffer("0", 1, 0);
			i++;
		}
	else if (!lst.flagminus)
		while (i < lst.min - 1)
		{
			ft_buffer(" ", 1, 0);
			i++;
		}
	else
		return (ft_print_error3(lst, j, fmt));
	return (i);
}

t_flag		ft_print_error(char *tmp, t_flag lst, const char *fmt)
{
	int i;

	i = 0;
	while (fmt[i])
	{
		if (!(ft_strchr(tmp, fmt[i])))
		{
			lst = ft_find_flag2(lst, i, fmt);
			lst.ret = ft_print_error2(lst, i, fmt);
			return (lst);
		}
		i++;
	}
	lst.ret = 0;
	return (lst);
}
