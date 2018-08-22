/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 12:24:00 by rdiederi          #+#    #+#             */
/*   Updated: 2018/06/15 12:24:02 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			index;
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;

	tmp_s1 = (unsigned char *)s1;
	tmp_s2 = (unsigned char *)s2;
	index = 0;
	while (n > 0 && tmp_s1[index] != '\0' && tmp_s1[index] == tmp_s2[index])
	{
		++index;
		--n;
	}
	if (n == 0)
		return (0);
	return (tmp_s1[index] - tmp_s2[index]);
}
