/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 11:36:39 by rdiederi          #+#    #+#             */
/*   Updated: 2018/06/15 12:13:05 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		count;
	int		count2;

	count = ft_strlen(s1);
	count2 = 0;
	while (n-- > 0 && s2[count2] != '\0')
	{
		s1[count++] = s2[count2++];
	}
	s1[count] = '\0';
	return (s1);
}
