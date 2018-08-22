/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 07:09:16 by rdiederi          #+#    #+#             */
/*   Updated: 2018/07/27 14:04:10 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_putstring(const char *fmt)
{
	int i;

	i = 0;
	if (!fmt)
		return (0);
	while (fmt[i] && fmt[i] != '%')
		i++;
	ft_buffer((char*)fmt, i, 0);
	return (i);
}

static void		ft_read(const char *fmt, va_list ap, t_flag lst, int i)
{
	i = ft_putstring(fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			if (fmt[i + 1] != '%' && fmt[i + 1])
			{
				lst = ft_check_fmt(fmt + i + 1, ap);
				i += lst.ret;
				if (lst.error != -1 && lst.flagminus == 1)
					i++;
				i += ft_putstring((char*)fmt + i + 1);
			}
			else if (fmt[i + 1])
			{
				ft_buffer("%", 1, 0);
				i += 2;
				i += ft_putstring((char*)fmt + i);
			}
			else
				return ;
		}
		else
			i++;
	}
}

int				ft_printf(const char *format, ...)
{
	va_list	ap;
	t_flag	lst;

	if (!format)
		return (0);
	lst.print = 0;
	ft_putbuffer(NULL, 0, 1);
	va_start(ap, format);
	ft_read(format, ap, lst, 0);
	va_end(ap);
	return (ft_buffer(NULL, 0, 1));
}
