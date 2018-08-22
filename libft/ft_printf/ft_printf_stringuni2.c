/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_stringuni2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 07:09:38 by rdiederi          #+#    #+#             */
/*   Updated: 2018/06/11 07:09:54 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned char	*len2(wchar_t c, unsigned char *t)
{
	if (c < 128)
	{
		t[0] = c;
		t[1] = 0;
		return (t);
	}
	t[1] = c % 64;
	t[1] += 0x80;
	c = c >> 6;
	t[0] = c;
	t[0] += 0xC0;
	t[2] = 0;
	return (t);
}

static unsigned char	*len3(wchar_t c, unsigned char *t)
{
	t[2] = c % 64;
	t[2] += 0x80;
	c = c >> 6;
	t[1] = c % 64;
	t[1] += 0x80;
	c = c >> 6;
	t[0] = c;
	t[0] += 0xE0;
	t[3] = 0;
	return (t);
}

static unsigned char	*len4(wchar_t c, unsigned char *t)
{
	t[3] = c % 64;
	t[3] += 0x80;
	c = c >> 6;
	t[2] = c % 64;
	t[2] += 0x80;
	c = c >> 6;
	t[1] = c % 64;
	t[1] += 0x80;
	c = c >> 6;
	t[0] = c;
	t[0] += 0xF0;
	t[4] = 0;
	return (t);
}

static unsigned char	*fill_t(unsigned char *t, wchar_t c)
{
	if (c < 128)
		t = len2(c, t);
	else if (c < 2048)
		t = len2(c, t);
	else if (c < 65536)
		t = len3(c, t);
	else
		t = len4(c, t);
	return (t);
}

void					ft_putstr_uni(wchar_t *s, t_flag lst, int len)
{
	int				i;
	int				j;
	int				k;
	unsigned char	*t;

	k = 0;
	i = 0;
	if (!(t = (unsigned char*)malloc(sizeof(unsigned char) * 5)))
		exit(-1);
	if (lst.prec && len > lst.prec)
		len = lst.prec;
	while (s[i] && k < len)
	{
		t = fill_t(t, s[i]);
		j = 0;
		k += ft_bit_len(s[i]);
		while (t[j] && k <= len)
		{
			ft_buffer((char*)&t[j], 1, 0);
			j++;
		}
		i++;
	}
	free(t);
}
