/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <rdiederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 13:50:20 by rdiederi          #+#    #+#             */
/*   Updated: 2018/08/30 18:09:08 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_flag_ls	get_flags(char *str, t_flag_ls flags)
{
	int		i;
	int		len;

	len = ft_strlen(str) + 1;
	i = 1;
	while (i < len && str[i])
	{
		if (str[i] == 'l')
			flags.flag_l = 1;
		if (str[i] == 't')
			flags.flag_t = 1;
		if (str[i] == 'r')
			flags.flag_r = 1;
		if (str[i] == 'R')
			flags.flag_br = 1;
		if (str[i] == 'a')
			flags.flag_a = 1;
		i++;
	}
	return (flags);
}
