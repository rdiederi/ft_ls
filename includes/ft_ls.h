/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <rdiederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 15:46:12 by rdiederi          #+#    #+#             */
/*   Updated: 2018/09/03 16:40:25 by rdiederi         ###   ########.fr       */
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

# define PATH_MAX 225

typedef struct			s_flagtype_ls
{
	int					flag_a;
	int					flag_t;
	int					flag_l;
	int					flag_r;
	int					flag_br;
	int					total;
}						t_flag_ls;

typedef struct			s_fileinfo
{
	quad_t				st_blocks;
	nlink_t				st_nlink;
	off_t				size;
	mode_t				st_mode;
	char				*st_uid;
	char				*st_gid;
	time_t				time;
	long				ntime;
	char				*name;
}						t_fileinfo;

typedef struct			s_file
{
	struct s_fileinfo	*file;
	struct s_file		*next;
}						t_file;

int						main(int argv, char **argc);
t_flag_ls				get_flags(char *str, t_flag_ls	flags);
void					print_list(t_file *list, t_flag_ls flags, char *s);
t_flag_ls				ft_init(void);
t_file					*sort_list(t_file *lst, t_flag_ls flags);
t_file					*rsort_list(t_file *lst);
t_file					*tsort_list(t_file *lst);
t_file					*lst_swap(t_file *lst1, t_file *lst2);
char					*time_func(char *str, struct stat the_time);

#endif
