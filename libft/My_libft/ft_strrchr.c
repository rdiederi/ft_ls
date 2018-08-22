/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 11:37:32 by rdiederi          #+#    #+#             */
/*   Updated: 2018/06/15 12:23:10 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int index;

	index = ft_strlen(s);
	while (index >= 0)
	{
		if (s[index] == (unsigned char)c)
		{
			break ;
		}
		--index;
	}
	if (index == 0)
		return ((char *)s);
	while ((*s != '\0') && (index >= 0))
	{
		++s;
		--index;
		if (index == 0)
		{
			return ((char *)s);
		}
	}
	return (NULL);
}
