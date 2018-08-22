/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tolower.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 18:33:45 by rdiederi          #+#    #+#             */
/*   Updated: 2018/07/12 18:39:05 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_str_tolower(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (ft_isupper(str[i]))
			ft_tolower(str[i]);
		i++;
	}
	return (str);
}
