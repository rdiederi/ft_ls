/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_uni2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 07:09:44 by rdiederi          #+#    #+#             */
/*   Updated: 2018/07/25 21:20:50 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		len1(wchar_t c)
{
	ft_buffer((char*)&c, 1, 0);
}

static void		len2(wchar_t c)
{
	unsigned char tmp[2];

	tmp[1] = c % 64;
	tmp[1] += 0x80;
	c = c >> 6;
	tmp[0] = c;
	tmp[0] += 0xC0;
	ft_buffer((char*)&tmp[0], 1, 0);
	ft_buffer((char*)&tmp[1], 1, 0);
}

static void		len3(wchar_t c)
{
	unsigned char tmp[3];

	tmp[2] = c % 64;
	tmp[2] += 0x80;
	c = c >> 6;
	tmp[1] = c % 64;
	tmp[1] += 0x80;
	c = c >> 6;
	tmp[0] = c;
	tmp[0] += 0xE0;
	ft_buffer((char*)&tmp[0], 1, 0);
	ft_buffer((char*)&tmp[1], 1, 0);
	ft_buffer((char*)&tmp[2], 1, 0);
}

static void		len4(wchar_t c)
{
	unsigned char tmp[4];

	tmp[3] = c % 64;
	tmp[3] += 0x80;
	c = c >> 6;
	tmp[2] = c % 64;
	tmp[2] += 0x80;
	c = c >> 6;
	tmp[1] = c % 64;
	tmp[1] += 0x80;
	c = c >> 6;
	tmp[0] = c;
	tmp[0] += 0xF0;
	ft_buffer((char*)&tmp[0], 1, 0);
	ft_buffer((char*)&tmp[1], 1, 0);
	ft_buffer((char*)&tmp[2], 1, 0);
	ft_buffer((char*)&tmp[3], 1, 0);
}

void			ft_putchar_uni2(wchar_t c)
{
	if (c < 128)
		len1(c);
	else if (c < 2048)
		len2(c);
	else if (c < 65536)
		len3(c);
	else
		len4(c);
}
