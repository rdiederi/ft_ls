/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <rdiederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 17:42:40 by rdiederi          #+#    #+#             */
/*   Updated: 2018/08/30 18:53:27 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_file	*lst_swap(t_file *lst1, t_file *lst2)
{
	lst1->next = lst2->next;
	lst2->next = lst1;
	return (lst2);
}

t_file	*sort_list(t_file *lst, t_flag_ls flags)
{
	char	*overflow;
	t_file	*tmp;

	tmp = lst;
	while (lst->next != NULL)
	{
		if (ft_strcmp(lst->file->name, lst->next->file->name) > 0)
		{
			overflow = lst->file->name;
			lst->file->name = lst->next->file->name;
			lst->next->file->name = overflow;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	if (flags.flag_r && !flags.flag_t)
		lst = rsort_list(lst);
	return (lst);
}

t_file	*rsort_list(t_file *lst)
{
	char	*overflow;
	t_file	*tmp;

	tmp = lst;
	while (lst->next != NULL)
	{
		if (ft_strcmp(lst->file->name, lst->next->file->name) < 0)
		{
			overflow = lst->file->name;
			lst->file->name = lst->next->file->name;
			lst->next->file->name = overflow;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}

t_file	*tsort_list(t_file *lst)
{
	if (!lst)
		return (NULL);
	if (lst->next && (lst->file->time < lst->next->file->time))
		lst = lst_swap(lst, lst->next);
	else if (lst->next && lst->file->time == lst->next->file->time)
		if (lst->next && (lst->file->ntime < lst->next->file->ntime))
			lst = lst_swap(lst, lst->next);
	lst->next = tsort_list(lst->next);
	if (lst->next && (lst->file->time < lst->next->file->time))
	{
		lst = lst_swap(lst, lst->next);
		lst->next = tsort_list(lst->next);
	}
	else if (lst->next && lst->file->time == lst->next->file->time)
	{
		if (lst->next && (lst->file->ntime < lst->next->file->ntime))
		{
			lst = lst_swap(lst, lst->next);
			lst->next = tsort_list(lst->next);
		}
	}
	return (lst);
}

t_file	*rtsort_list(t_file *lst)
{
	if (!lst)
		return (NULL);
	if (lst->next && (lst->file->time > lst->next->file->time))
		lst = lst_swap(lst, lst->next);
	else if (lst->next && lst->file->time == lst->next->file->time)
		if (lst->next && (lst->file->ntime > lst->next->file->ntime))
			lst = lst_swap(lst, lst->next);
	lst->next = tsort_list(lst->next);
	if (lst->next && (lst->file->time > lst->next->file->time))
	{
		lst = lst_swap(lst, lst->next);
		lst->next = tsort_list(lst->next);
	}
	else if (lst->next && lst->file->time == lst->next->file->time)
	{
		if (lst->next && (lst->file->ntime > lst->next->file->ntime))
		{
			lst = lst_swap(lst, lst->next);
			lst->next = tsort_list(lst->next);
		}
	}
	return (lst);
}
