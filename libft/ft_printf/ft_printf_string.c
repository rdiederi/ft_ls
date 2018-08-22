/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 10:14:50 by rdiederi          #+#    #+#             */
/*   Updated: 2018/07/30 10:14:52 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_margin(t_flag lst, int len)
{
	int i;

	i = 0;
	if (lst.flagzero && !lst.flagminus)
		while (i < lst.min - len)
		{
			ft_buffer("0", 1, 0);
			i++;
		}
	else
		while (i < lst.min - len)
		{
			ft_buffer(" ", 1, 0);
			i++;
		}
}

static int		ft_strpreclen(char *s, t_flag lst)
{
	int len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	if (lst.prec)
		if (len > lst.prec)
			len = lst.prec;
	return (len);
}

static void		ft_printf_string2(char *s, wchar_t *uni, t_flag lst)
{
	int len;

	if (lst.type == 'S')
	{
		ft_printf_stringuni(uni, lst);
		return ;
	}
	len = ft_strpreclen(s, lst);
	if (lst.prec1 && !lst.prec)
		len = 0;
	if (!s && lst.min && !(lst.prec1 && !lst.prec))
		lst.min -= 6;
	if (!lst.flagminus && lst.type == 's')
		ft_margin(lst, len);
	if (lst.type == 's' && len && s)
		ft_buffer(s, ft_strpreclen(s, lst), 0);
	else if (!s && !(lst.prec1 && !lst.prec))
		ft_buffer("(null)", 6, 0);
	if (lst.flagminus && lst.type == 's')
		ft_margin(lst, len);
}

static int		ft_null(t_flag lst)
{
	if (!lst.prec1)
	{
		ft_buffer("(null)", 6, 0);
		return (1);
	}
	return (0);
}

void			ft_printf_string(va_list ap, t_flag lst)
{
	char	*str;
	wchar_t	*struni;

	str = NULL;
	struni = NULL;
	if (lst.type == 's' && !lst.flagl)
	{
		if (!(str = va_arg(ap, char *)))
			if (ft_null(lst))
				return ;
	}
	if (lst.type == 'S' || lst.flagl)
	{
		if (!(struni = va_arg(ap, wchar_t *)))
			if (ft_null(lst))
				return ;
		lst.type = 'S';
		lst.flagl = 1;
	}
	ft_printf_string2(str, struni, lst);
}
