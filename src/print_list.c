/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <rdiederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 21:53:28 by rdiederi          #+#    #+#             */
/*   Updated: 2018/08/30 18:12:07 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

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

static char		*ft_strmode(t_file *list)
{
	size_t		i;
	const char	*chars;
	mode_t		combs[1];
	int			res;
	char		*permsize;

	res = list->file->st_mode;
	combs[0] = res;
	chars = "rwxrwxrwx";
	if (res >= 16384 && res <= 16895)
		ft_printf("d");
	else if (res >= 40960 && res <= 41471)
		ft_printf("l");
	else
		ft_printf("-");
	permsize = (char *)malloc(sizeof(char) * 10);
	i = -1;
	while (++i < 9)
		permsize[i] = (combs[0] & (1 << (8 - i))) ? chars[i] : '-';
	permsize[9] = '\0';
	return (permsize);
}

static char		*time_func(char *str, struct stat the_time)
{
	char *ret;

	stat(str, &the_time);
	ret = ctime(&the_time.st_mtime);
	ret = ret + 4;
	ret[12] = '\0';
	return (ret);
}

void			print_list(t_file *list, t_flag_ls flags, char *path)
{
	struct stat		tt;
	char			*permsize;

	permsize = NULL;
	if (flags.flag_l)
		ft_printf("total %d\n", get_block_size(path, flags));
	while (list)
	{
		if (flags.flag_l == 1)
		{
			stat(list->file->name, &tt);
			permsize = ft_strmode(list);
			ft_printf("%s % -d %s  %s %6llu %s ",
			permsize,
			list->file->st_nlink,
			list->file->st_uid,
			list->file->st_gid,
			list->file->size,
			time_func(list->file->name, tt));
		}
		ft_printf("%s\n", list->file->name);
		list = list->next;
	}
}
