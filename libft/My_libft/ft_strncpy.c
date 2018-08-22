/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 12:12:24 by rdiederi          #+#    #+#             */
/*   Updated: 2018/06/15 12:12:26 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	fill;

	ft_memcpy(dst, src, len);
	if (ft_strlen(src) < (len))
	{
		fill = (len - 1) - ft_strlen(src);
		while (fill > 0)
		{
			dst[ft_strlen(src) + fill] = '\0';
			--fill;
		}
	}
	return (dst);
}
