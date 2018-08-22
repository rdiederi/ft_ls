/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 07:08:59 by rdiederi          #+#    #+#             */
/*   Updated: 2018/07/25 18:52:47 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_conv_nb(uintmax_t *nb, t_flag lst)
{
	if (lst.flagll)
		*nb = (unsigned long long int)*nb;
	else if (lst.flagl)
		*nb = (unsigned long int)*nb;
	else if (lst.flagj)
		*nb = (uintmax_t)*nb;
	else if (lst.flagz)
		*nb = (size_t)*nb;
	else if (lst.flagh)
		*nb = (unsigned short int)*nb;
	else if (lst.flaghh)
		*nb = (unsigned char)*nb;
	else
		*nb = (unsigned int)*nb;
}

static char	*ft_create_base(t_flag lst)
{
	if (lst.type == 'o' || lst.type == 'O')
		return (ft_strdup("01234567"));
	else if (lst.type == 'u' || lst.type == 'U')
		return (ft_strdup("0123456789"));
	else if (lst.type == 'x' || lst.type == 'p')
		return (ft_strdup("0123456789abcdef"));
	else if (lst.type == 'X')
		return (ft_strdup("0123456789ABCDEF"));
	return (NULL);
}

static int	ft_base_len(uintmax_t nb, char *base)
{
	int baselen;
	int len;

	baselen = ft_strlen(base);
	len = 1;
	while ((nb /= baselen) != 0)
		len++;
	return (len);
}

static void	ft_print_base(uintmax_t n, char *base)
{
	int		tmp;
	int		len;
	char	c;

	len = ft_strlen(base);
	if (n > (uintmax_t)len - 1)
		ft_print_base(n / len, base);
	tmp = n % len;
	c = base[tmp];
	ft_buffer(&c, 1, 0);
}

void		ft_printf_base(va_list ap, t_flag lst)
{
	uintmax_t	nb;
	int			len;
	int			lenn;

	if (lst.type == 'O' || lst.type == 'U' || lst.type == 'p')
		lst.flagl = 1;
	if (!(lst.base = ft_create_base(lst)))
		exit(-1);
	nb = va_arg(ap, uintmax_t);
	ft_conv_nb(&nb, lst);
	len = ft_base_len(nb, lst.base);
	lenn = len;
	if (len < lst.prec)
		len = lst.prec;
	if ((lst.type == 'X' || lst.type == 'x') && lst.flaghtag && nb != 0)
		lenn += 2;
	if (lst.prec1 && nb == 0 && !lst.prec)
		len = 0;
	lst = left_margingbase(lst, len, nb, ft_base_len(nb, lst.base));
	left_signbase(lst, ft_base_len(nb, lst.base), nb, len);
	if (!(lst.prec1 && nb == 0 && !lst.prec))
		ft_print_base(nb, lst.base);
	right_margingbase(lst, len);
	free(lst.base);
}
