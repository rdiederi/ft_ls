/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <rdiederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 15:46:12 by rdiederi          #+#    #+#             */
/*   Updated: 2018/08/29 15:59:50 by rdiederi         ###   ########.fr       */
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

typedef	struct			s_stat
{
	quad_t				st_blocks;	/*number of blocks the file takes up;*/
	nlink_t				st_nlink;	/* mode / system links*/
	off_t				size;		/*size of file in bytes // before date*/
	mode_t				st_mode;	/*get chmod (permissions)*/
	char				*st_uid;		/* owner name*/
	char				*st_gid;		/* owner group*/
	struct timespec 	st_time;	/*last modification*/
}						t_stat;

typedef struct			s_fileinfo
{
	struct s_stat		*s_stat;
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
	
#endif
