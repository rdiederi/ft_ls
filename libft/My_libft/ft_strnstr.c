/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 11:37:03 by rdiederi          #+#    #+#             */
/*   Updated: 2018/06/15 12:23:31 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int count;
	int i;

	i = -1;
	if (needle[0] == '\0')
		return (char*)(haystack);
	while (haystack[++i] != '\0')
	{
		count = -1;
		while (needle[++count] != '\0')
		{
			if ((size_t)(i + count) >= len)
				break ;
			if (needle[count] != haystack[i + count])
				break ;
			if (needle[count + 1] == '\0')
				return (char*)(haystack + i);
		}
	}
	return (0);
}
