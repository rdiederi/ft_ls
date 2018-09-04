/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <rdiederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 13:50:20 by rdiederi          #+#    #+#             */
/*   Updated: 2018/09/04 19:15:18 by rdiederi         ###   ########.fr       */
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

t_flag_ls	ft_init(void)
{
	t_flag_ls	list;

	list.flag_a = 0;
	list.flag_l = 0;
	list.flag_r = 0;
	list.flag_br = 0;
	list.flag_t = 0;
	return (list);
}
