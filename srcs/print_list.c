/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <rdiederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 21:53:28 by rdiederi          #+#    #+#             */
/*   Updated: 2018/09/04 23:24:42 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <stdio.h>

static int		get_block_size(char *directory, t_flag_ls flags)
{
	int				size;
	DIR				*d;
	struct dirent	*dir;
	struct stat		file_stat;
	char			info_path[PATH_MAX + 1];

	d = opendir(directory);
	size = 0;
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			if ((flags.flag_a == 0) && dir->d_name[0] == '.')
				continue;
			ft_strcpy(info_path, directory);
			if (directory[ft_strlen(directory) - 1] != '/')
				ft_strcat(info_path, "/");
			ft_strcat(info_path, dir->d_name);
			stat(info_path, &file_stat);
			size += file_stat.st_blocks;
		}
	}
	return (size);
}

static char		get_file_type(int mode)
{
	mode = (mode & S_IFMT);
	if (S_ISREG(mode))
		return ('-');
	else if (S_ISDIR(mode))
		return ('d');
	else if (S_ISLNK(mode))
		return ('l');
	else if (S_ISBLK(mode))
		return ('b');
	else if (S_ISCHR(mode))
		return ('c');
	else if (S_ISSOCK(mode))
		return ('s');
	else if (S_ISFIFO(mode))
		return ('p');
	else
		return ('-');
}

static char		*display_chmod(int mode)
{
	char *chmod;

	chmod = (char *)malloc(sizeof(char) * 11);
	chmod[0] = get_file_type(mode);
	chmod[1] = (S_IRUSR & mode) ? 'r' : '-';
	chmod[2] = (S_IWUSR & mode) ? 'w' : '-';
	chmod[3] = (S_IXUSR & mode) ? 'x' : '-';
	chmod[4] = (S_IRGRP & mode) ? 'r' : '-';
	chmod[5] = (S_IWGRP & mode) ? 'w' : '-';
	chmod[6] = (S_IXGRP & mode) ? 'x' : '-';
	chmod[7] = (S_IROTH & mode) ? 'r' : '-';
	chmod[8] = (S_IWOTH & mode) ? 'w' : '-';
	chmod[9] = (S_IXOTH & mode) ? 'x' : '-';
	chmod[10] = '\0';
	return (chmod);
}

static	void	get_name(t_file *list, char *path)
{
	char			buf[PATH_MAX + 1];
	char			*str_1;
	char			*str_2;
	char			*str_3;

	str_1 = ft_strjoin(path, "/");
	str_2 = ft_strjoin(str_1, list->file->name);
	str_3 = ft_strjoin("/sgoinfre/rdiederi/ft_ls_F/ft_ls_C/", str_2);
	path = NULL;
	ft_bzero(buf, PATH_MAX + 1);
	readlink(str_3, buf, PATH_MAX);
	ft_printf("%s -> %s\n", list->file->name, buf);
	free(str_1);
	free(str_2);
	free(str_3);
}

void			print_list(t_file *list, t_flag_ls flags, char *path)
{
	struct stat		tt;
	char			*pms;
	char			*date;

	if (flags.flag_l)
		ft_printf("total %d\n", get_block_size(path, flags));
	while (list)
	{
		if (flags.flag_l == 1)
		{
			lstat(ft_strjoin(path, list->file->name), &tt);
			pms = display_chmod(list->file->st_mode);
			date = time_func(ft_strjoin(path, list->file->name), list);
			ft_printf("%s % -d %s  %s %6llu %s ", pms, list->file->st_nlink,
			list->file->st_uid, list->file->st_gid, list->file->size, date);
		}
		if (S_ISLNK(list->file->st_mode) && flags.flag_l)
			get_name(list, path);
		else
			ft_printf("%s\n", list->file->name);
		list = list->next;
		free(date);
	}
}
