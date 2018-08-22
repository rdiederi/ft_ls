/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fmt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <rdiederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 07:08:59 by rdiederi          #+#    #+#             */
/*   Updated: 2018/07/31 02:36:29 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flag	ft_init_lst(t_flag lst)
{
	lst.flagzero = 0;
	lst.flagplus = 0;
	lst.flagminus = 0;
	lst.flagspace = 0;
	lst.flaghtag = 0;
	lst.flagh = 0;
	lst.flaghh = 0;
	lst.flagll = 0;
	lst.flagl = 0;
	lst.flagj = 0;
	lst.flagz = 0;
	lst.min = 0;
	lst.prec = 0;
	lst.prec1 = 0;
	lst.error = -1;
	lst.type = 0;
	lst.ret = 0;
	lst.print = 0;
	return (lst);
}

static int		ft_check_valid(char *tmp, const char *fmt, int j)
{
	int i;

	i = 0;
	while (i < j)
	{
		if (!ft_strchr(tmp, fmt[i]))
			return (i);
		i++;
	}
	return (-1);
}

static t_flag	ft_find_flag(const char *fmt, t_flag lst, int j)
{
	int		i;
	char	*tmp;

	tmp = ft_strdup("#0-+ hljz123456789.");
	if ((i = ft_check_valid(tmp, fmt, j)) != -1)
	{
		lst = ft_print_error(tmp, lst, fmt);
		lst.print += lst.ret;
		free(tmp);
		lst.error = i;
		return (lst);
	}
	lst = ft_find_flag2(lst, j, fmt);
	free(tmp);
	return (lst);
}

t_flag			ft_check_fmt(const char *fmt, va_list ap)
{
	t_flag	lst;
	int		i;
	char	*tmp;

	tmp = ft_strdup("sSpdDioOuUxXcC%");
	i = 0;
	lst.flagl = 0;
	lst = ft_init_lst(lst);
	while (fmt[i] && !ft_strchr(tmp, fmt[i]))
		i++;
	free(tmp);
	lst.type = fmt[i];
	lst.ret = i;
	if (fmt[i])
		lst.ret++;
	lst = ft_find_flag(fmt, lst, i);
	if (lst.error != -1)
	{
		lst.ret = lst.error;
		return (lst);
	}
	lst = ft_type(ap, lst);
	return (lst);
}
