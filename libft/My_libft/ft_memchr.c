/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 11:28:30 by rdiederi          #+#    #+#             */
/*   Updated: 2018/06/15 11:28:32 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp_s;
	size_t			count;

	tmp_s = (unsigned char *)s;
	count = 0;
	while (count < n)
	{
		if (*tmp_s == (unsigned char)c)
			return (tmp_s);
		++tmp_s;
		++count;
	}
	return (NULL);
}
