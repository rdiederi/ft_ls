/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_detail.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <rdiederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 15:20:51 by rdiederi          #+#    #+#             */
/*   Updated: 2018/09/04 23:26:37 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char		*get_date(char *ret)
{
	char	*head;

	head = ret;
	head = head + 8;
	head[3] = '\0';
	return (head);
}

static char		*get_month(char *ret)
{
	char *temp;

	temp = ret;
	temp = temp + 4;
	temp[3] = '\0';
	return (temp);
}

static char		*get_time(char *ret)
{
	char *temp;

	temp = ret;
	temp = temp + (4 + 6);
	temp[6] = '\0';
	return (temp);
}

static char		*join_date(char *date, char *month, char *time_)
{
	char	*f_date;
	char	*s_date;

	f_date = ft_strjoin(date, month);
	s_date = ft_strjoin(f_date, time_);
	return (s_date);
}

char			*time_func(char *str, t_file *the_time)
{
	char	*ret;
	char	*date;
	char	*month;
	char	*time_;

	str = NULL;
	ret = ctime(&the_time->file->ntime);
	time_ = ft_strdup(get_time(ret));
	date = get_date(ret);
	month = get_month(ret);
	return (join_date(date, month, time_));
}
