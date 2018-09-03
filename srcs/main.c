/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <rdiederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 11:03:20 by rdiederi          #+#    #+#             */
/*   Updated: 2018/09/03 15:11:55 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_file	*get_stats(char *dir, t_file *head, t_file *new)
{
	struct stat		buf;
	char			*half_name;
	char			*full_name;
	struct group	*grp;
	struct passwd	*uid;

	new = head;
	while (new)
	{
		half_name = ft_strjoin("/", new->file->name);
		full_name = ft_strjoin(dir, half_name);
		stat(full_name, &buf);
		new->file->st_nlink = buf.st_nlink;
		new->file->size = buf.st_size;
		new->file->st_mode = buf.st_mode;
		new->file->time = buf.st_mtimespec.tv_sec;
		new->file->ntime = buf.st_mtimespec.tv_nsec;
		uid = getpwuid(buf.st_uid);
		grp = getgrgid(buf.st_gid);
		new->file->st_uid = uid->pw_name;
		new->file->st_gid = grp->gr_name;
		new = new->next;
	}
	return (head);
}

static t_file	*make_list(t_file *head, t_flag_ls f_list, char *d)
{
	struct dirent	*sd;
	DIR				*dir;
	t_file			*new;

	new = NULL;
	if (!(dir = opendir(d)))
		return (0);
	while ((sd = readdir(dir)) != NULL)
	{
		if ((f_list.flag_a == 0) && sd->d_name[0] == '.')
			continue;
		if ((new = (t_file *)malloc(sizeof(t_file))) == NULL)
			return (NULL);
		if ((new->file = (t_fileinfo *)malloc(sizeof(t_fileinfo))) == NULL)
			return (NULL);
		new->file->name = sd->d_name;
		new->next = head;
		head = new;
	}
	head = sort_list(head, f_list);
	head = get_stats(d, head, new);
	return (head);
}

static int		print_ls(char *d, t_flag_ls f_list)
{
	t_file			*list;
	t_file			*head;
	DIR				*dir;

	head = NULL;
	if (!d)
		d = ".";
	if (!(dir = opendir(d)))
		return (0);
	f_list = get_flags(d, f_list);
	list = make_list(head, f_list, d);
	if (f_list.flag_r && f_list.flag_t)
	{
		list = tsort_list(list);
		list = rsort_list(list);
	}
	else if (f_list.flag_t)
		list = tsort_list(list);
	print_list(list, f_list, d);
	closedir(dir);
	return (1);
}

int				main(int argc, char **argv)
{
	int			i;
	t_flag_ls	flags;

	i = 1;
	flags = ft_init();
	if (!argv[i])
	{
		print_ls(".", flags);
		return (0);
	}
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			flags = get_flags(argv[i], flags);
			i++;
		}
		if (!(print_ls(argv[i], flags)))
			return (0);
		i++;
	}
	return (0);
}
