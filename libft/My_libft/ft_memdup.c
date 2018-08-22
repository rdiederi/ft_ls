/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 17:52:59 by rdiederi          #+#    #+#             */
/*   Updated: 2018/07/12 17:55:47 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *src, size_t n)
{
	void	*ret;

	if (!src)
		return (NULL);
	ret = (void *)malloc(n);
	if (!ret)
		return (NULL);
	ret = ft_memcpy(ret, src, n);
	return (ret);
}
