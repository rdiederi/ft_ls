/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 10:14:29 by rdiederi          #+#    #+#             */
/*   Updated: 2018/07/30 10:14:31 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		conv_nb(intmax_t *nb, t_flag lst)
{
	if (lst.type == 'D')
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
		*nb = (intmax_t)*nb;
	else
		*nb = (int)*nb;
}

static void		ft_print_nb2(intmax_t n)
{
	char		c;

	if (n > 9 || n < -9)
		ft_print_nb2(n / 10);
	if (n > 0)
		c = n % 10 + '0';
	else
		c = -1 * (n % 10) + '0';
	ft_buffer(&c, 1, 0);
}

static size_t	ft_nbr_len(intmax_t n)
{
	size_t len;

	len = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void			ft_printf_nbr(va_list ap, t_flag lst)
{
	intmax_t	nb;
	int			len;
	int			lenn;

	nb = va_arg(ap, intmax_t);
	conv_nb(&nb, lst);
	len = ft_nbr_len(nb);
	lenn = len;
	if (nb < 0)
		lenn--;
	if (len < lst.prec && nb >= 0)
		len = lst.prec;
	if (len <= lst.prec && nb < 0)
		len = lst.prec + 1;
	if (lst.prec1 && nb == 0 && !lst.prec)
		len = 0;
	if (nb < 0 && lst.flagzero && !lst.prec1)
		ft_buffer("-", 1, 0);
	lst = left_marging(lst, len, nb);
	left_sign(lst, lenn, nb);
	if (!(lst.prec1 && nb == 0 && !lst.prec))
		ft_print_nb2(nb);
	right_marging(lst, len);
}
