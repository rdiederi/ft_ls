/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_stringuni.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 07:09:36 by rdiederi          #+#    #+#             */
/*   Updated: 2018/07/27 13:56:07 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			ft_bit_len(wchar_t c)
{
	size_t len;

	if (c < 128)
		len = 1;
	else if (c < 2048)
		len = 2;
	else if (c < 65536)
		len = 3;
	else
		len = 4;
	return (len);
}

static size_t	ft_struni_len(wchar_t *s, t_flag lst, int k, int i)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		len += ft_bit_len(s[i]);
		i++;
	}
	i = 0;
	if ((int)len > lst.prec && lst.prec1)
	{
		len = lst.prec;
		while (s[i])
		{
			if (k + ft_bit_len(s[i]) <= len)
				k += ft_bit_len(s[i]);
			else
				return ((size_t)k);
			i++;
		}
	}
	return (len);
}

static void		ft_margin(t_flag lst)
{
	int i;

	i = 0;
	if (lst.flagzero && !lst.flagminus)
		while (i < lst.min - 1)
		{
			ft_buffer("0", 1, 0);
			i++;
		}
	else
		while (i < lst.min - 1)
		{
			ft_buffer(" ", 1, 0);
			i++;
		}
}

void			ft_printf_stringuni(wchar_t *s, t_flag lst)
{
	int len;
	int l;

	len = ft_struni_len(s, lst, 0, 0);
	l = len;
	if (lst.prec1 && !lst.prec)
	{
		len = 0;
		lst.min++;
	}
	while (len - 1 != 0 && len != 0)
	{
		lst.min--;
		len--;
	}
	if (!s && lst.min)
		lst.min -= 5;
	if (!lst.flagminus)
		ft_margin(lst);
	if (len != 0 && s)
		ft_putstr_uni(s, lst, l);
	else if (!s)
		ft_buffer("(null)", 6, 0);
	if (lst.flagminus)
		ft_margin(lst);
}
