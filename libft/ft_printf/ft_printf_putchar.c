/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 10:14:15 by rdiederi          #+#    #+#             */
/*   Updated: 2018/07/30 10:14:17 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flag	ft_margin(t_flag lst, int x)
{
	int i;

	i = 0;
	if (lst.flagzero)
		while (i < lst.min - x)
		{
			ft_buffer("0", 1, 0);
			lst.print++;
			i++;
		}
	else
		while (i < lst.min - x)
		{
			ft_buffer(" ", 1, 0);
			lst.print++;
			i++;
		}
	return (lst);
}

static void		conv_c(wchar_t *nb, t_flag lst)
{
	if (lst.type == 'C')
		lst.flagl = 1;
	if (lst.flagl)
		*nb = (long int)*nb;
	else if (lst.flagll)
		*nb = (long long int)*nb;
	else if (lst.flagh)
		*nb = (short int)*nb;
	else if (lst.flaghh)
		*nb = (char)*nb;
	else if (lst.flagz)
		*nb = (size_t)*nb;
	else if (lst.flagj)
		*nb = (long)*nb;
	else
		*nb = (char)*nb;
}

static t_flag	ft_special(t_flag lst, wchar_t c)
{
	if (!lst.flagminus && lst.type == 'C')
		lst = ft_margin(lst, 1);
	ft_buffer(NULL, 0, 1);
	ft_putbuffer(NULL, 1, 0);
	write(1, &c, 1);
	if (lst.flagminus)
		lst = ft_margin(lst, 1);
	return (lst);
}

t_flag			ft_printf_putchar(va_list ap, t_flag lst)
{
	wchar_t	c;

	c = va_arg(ap, wchar_t);
	conv_c(&c, lst);
	if (lst.flagl == 1 && lst.type == 'c')
		lst.type = 'C';
	if (!lst.flagminus && lst.type == 'c')
		lst = ft_margin(lst, 1);
	if (c == 0)
		return (ft_special(lst, c));
	else if (lst.type == 'c')
		ft_buffer((char*)&c, 1, 0);
	else
		lst = ft_putchar_uni(c, lst);
	if (lst.flagminus && lst.type == 'c')
		lst = ft_margin(lst, 1);
	return (lst);
}
