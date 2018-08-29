/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <rdiederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 21:53:28 by rdiederi          #+#    #+#             */
/*   Updated: 2018/08/29 16:27:30 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <stdio.h>

#define PATH_MAX 225

int getBlockSize(char* directory) {
   int size = 0;

   DIR *d;
   struct dirent *dir;
   struct stat fileStat;
   d = opendir(directory);
   if (d) {
       while ((dir = readdir(d)) != NULL) {
           if (dir->d_name[0] != '.') { // Ignore hidden files
               // Create the path to stat
               char info_path[PATH_MAX + 1];
               strcpy(info_path, directory);
               if (directory[strlen(directory) - 1] != '/')
                   strcat(info_path, "/");
               strcat(info_path, dir->d_name);

               stat(info_path, &fileStat);

               size += fileStat.st_blocks;
           }
       }
   }

   return size;
}

static char *ft_strmode(t_file *list)
{
	size_t i;
	const char *chars;
	mode_t combs[1];
	int res;
	char *permsize;

	res = list->file->s_stat->st_mode;
	combs[0] = res;
	chars = "rwxrwxrwx";
	if (res >= 16384 && res <= 16895) //octal to decimal converted
		ft_printf("d");
	else if (res >= 40960 && res <= 41471)//otod
		ft_printf("l");
	else
		ft_printf("-");
	permsize = (char *)malloc(sizeof(char) * 10);
	i = -1;
	while (++i < 9)
	{
		permsize[i] = (combs[0] & (1 << (8 - i))) ? chars[i] : '-';
	}
	permsize[9] = '\0';
	return (permsize);
}

char *time_func(char *str, struct stat the_time)
{
	char *ret;

	stat(str, &the_time);
	ret = ctime(&the_time.st_mtime);
	ret = ret + 4;
	ret[12] = '\0';
	return (ret);
}

/*void	print_list(t_file *list, t_flag_ls flags, char *path)
{
	struct stat tt;
	
	char *permsize;
	permsize = NULL;
	if (flags.flag_l)
		ft_printf("total %d\n", getBlockSize(path));
	while (list)
	{
		if (flags.flag_l == 1)
		{

			stat(list->file->name, &tt);
			permsize = ft_strmode(list);
			ft_printf("%s % -d %s %s %6zu %s ",
			permsize, list->file->s_stat->st_nlink,
			list->file->s_stat->st_uid, 
			list->file->s_stat->st_gid, 
			list->file->s_stat->st_size,
			time_func(list->file->name, tt));
		}
		ft_printf("%s\n", list->file->name);
		// if (flags.flag_br && permsize[0] == 'd')
		// {
			// /print_list(list, flags);
		// }
		list = list->next;
	}
}
*/
void	print_list(t_file *list, t_flag_ls flags, char *path)
{
	struct	stat 	tt;
	char 			*permsize;
	
	permsize = NULL;
	if (flags.flag_l)
		ft_printf("total %d\n", getBlockSize(path));
	
	while (list)
	{
		if (flags.flag_l == 1)
		{
			stat(list->file->name, &tt);
			permsize = ft_strmode(list);
			ft_printf("%s % -d %s  %s %6llu %s ",
			permsize,
			list->file->s_stat->st_nlink,
			list->file->s_stat->st_uid,
			list->file->s_stat->st_gid,
			list->file->s_stat->size,
			time_func(list->file->name, tt));
		}
		ft_printf("%s\n", list->file->name);
		list = list->next;
	}
}