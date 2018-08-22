/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 11:30:12 by rdiederi          #+#    #+#             */
/*   Updated: 2018/06/15 11:30:15 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp_b;
	size_t			index;

	if (len == 0)
		return (b);
	temp_b = (unsigned char *)b;
	index = 0;
	while (index < len)
	{
		temp_b[index] = c;
		++index;
	}
	return (b);
}
