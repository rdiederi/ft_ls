/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <rdiederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 13:50:20 by rdiederi          #+#    #+#             */
/*   Updated: 2018/08/20 16:36:36 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*static void	display_flags(t_flag_ls flags)
{
	ft_putstr("\n-------------------------------------------------\n");
	ft_putstr("");
	ft_putstr("flags = \n");
	ft_putstr("flags.flag_a = ");
	ft_putnbr(flags.flag_a);
	ft_putstr("\n");
	ft_putstr("flags.flag_l = ");
	ft_putnbr(flags.flag_l);
	ft_putstr("\n");
	ft_putstr("flags.flag_r = ");
	ft_putnbr(flags.flag_r);
	ft_putstr("\n");
	ft_putstr("flags.flag_t = ");
	ft_putnbr(flags.flag_t);
	ft_putstr("\n");
	ft_putstr("flags.flag_br = ");
	ft_putnbr(flags.flag_br);
	ft_putstr("\n-------------------------------------------------\n");
}*/

t_flag_ls	get_flags(char *str, t_flag_ls	flags)
{
	int		i;
	int		len;

	/*if (!str)
		return (NULL);*/
	len = ft_strlen(str) + 1;
	i = 1;
/*	if ((flags.flag_l >= 1 && flags.flag_l <= 0) &&
		(flags.flag_t >= 1 && flags.flag_t <= 0) &&
		(flags.flag_r >= 1 && flags.flag_r <= 0) &&
		(flags.flag_br >= 1 && flags.flag_br <= 0) &&
		(flags.flag_a >= 1 && flags.flag_a <= 0))
		flags = ft_init();*/
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
	//display_flags(flags);
	return (flags);
}