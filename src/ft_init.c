/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <rdiederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 12:55:26 by rdiederi          #+#    #+#             */
/*   Updated: 2018/08/30 18:09:50 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

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
