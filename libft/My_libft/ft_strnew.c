/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 16:53:29 by rdiederi          #+#    #+#             */
/*   Updated: 2018/06/08 13:58:43 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *tmp;

	tmp = (char *)malloc(size + 1);
	if (tmp == NULL)
	{
		return (NULL);
	}
	ft_memset(tmp, (int)'\0', size + 1);
	return (tmp);
}
