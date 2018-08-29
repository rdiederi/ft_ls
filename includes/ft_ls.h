/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <rdiederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 15:46:12 by rdiederi          #+#    #+#             */
/*   Updated: 2018/08/29 19:28:55 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include <dirent.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <time.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>

typedef struct			s_flagtype_ls
{
	int flag_a;
	int flag_t;
	int flag_l;
	int flag_r;
	int flag_br;
	int total;
}						t_flag_ls;

typedef struct			s_fileinfo
{
	quad_t				st_blocks;	/*number of blocks the file takes up;*/
	nlink_t				st_nlink;	/* mode / system links*/
	off_t				size;		/*size of file in bytes // before date*/
	mode_t				st_mode;	/*get chmod (permissions)*/
	char				*st_uid;		/* owner name*/
	char				*st_gid;		/* owner group*/
	time_t				time;
	long				ntime;
	// struct timespec 	st_time;	/*last modification*/
	char 				*name;
}						t_fileinfo;

typedef struct			s_file
{
	struct s_fileinfo	*file;
	struct s_file		*next;
}						t_file;

int			main(int argv, char **argc);
t_flag_ls	get_flags(char *str, t_flag_ls	flags);
void		print_list(t_file *list, t_flag_ls flags, char *s);
t_flag_ls	ft_init();
t_file		*sort_list(t_file* lst, t_flag_ls flags);
t_file		*rsort_list(t_file* lst);
t_file		*tsort_list(t_file* lst);
	
#endif
