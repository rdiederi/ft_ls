/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 07:08:59 by rdiederi          #+#    #+#             */
/*   Updated: 2018/07/13 13:36:47 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			ft_putbuffer(char *s, int c, int init)
{
	static int	i;
	int			j;

	if (init)
		i = 0;
	if (c)
	{
		i += c;
		return (i);
	}
	if (!s)
		return (i);
	j = ft_strlen(s);
	write(1, s, j);
	i += j;
	return (i);
}

static size_t	ft_check_ret(char *s, int i, char c)
{
	if (c == '\n' || c == '\0')
	{
		ft_putbuffer(s, 0, 0);
		ft_bzero(s, 4096);
		return (0);
	}
	return (i);
}

static size_t	ft_special(char *s)
{
	size_t len;

	len = ft_putbuffer(s, 0, 0);
	ft_bzero(s, 4096);
	return (len);
}

size_t			ft_buffer(char *s, size_t len, int c)
{
	static char *buffer;
	int			i;
	int			j;

	if (buffer == NULL)
		if (!(buffer = ft_strnew(4096)))
			exit(-1);
	if (c)
		return (ft_special(buffer));
	j = -1;
	i = ft_strlen(buffer);
	while (++j < (int)len && i < 4096 && s[j])
	{
		buffer[i] = s[j];
		i++;
		i = ft_check_ret(buffer, i, s[j]);
	}
	buffer[i] = '\0';
	if (i == 4096)
	{
		ft_putbuffer(buffer, 0, 0);
		ft_bzero(buffer, 4096);
		return (ft_buffer(s + j, ft_strlen(s + j), 0));
	}
	return (0);
}
