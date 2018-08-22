/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <rdiederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 11:03:20 by rdiederi          #+#    #+#             */
/*   Updated: 2018/08/22 01:40:02 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <string.h>

static int		lstcount(t_file *node)
{
	int i;

	i = 0;
	while (node && node->next != NULL)
	{
		i++;
		node = node->next;
	}
	return (i);
}

t_file			*sort_list(t_file *head, t_flag_ls f_list)
{
	int num_nodes;
	int counter;

	num_nodes = lstcount(head);
	// ft_putstr("\n-------------------------------------------------\n");
	// ft_putnbr(num_nodes);
	// ft_putstr("\n-------------------------------------------------\n");
	counter = 0;
    while (counter < num_nodes)
	{
		t_file	*current;
		current = head;
		t_file	*next;
		next = current->next;
		t_file	*previous;
		previous = NULL;
		while(next != NULL)
		{
			if (ft_strcmp(head->name, head->next->name))
			{
				if (current == head)
					head = next;
				else
                    previous->next = next;
                current->next = next->next;
                next->next = current; 
                previous = next;
                next = current->next;
				 ft_putstr("\n-------------------------------------------------\n");
				 print_list(head, f_list, ".");
				 ft_putstr("\n");
				 ft_putnbr(counter);
				 ft_putstr("\n-------------------------------------------------\n");
				}
				else
			{
				previous = current;
				current = current->next;
				next = current->next;
				}
		}
		counter++;
    }
    return head;
}

/*static t_file	*sort_list(t_file *head)
{
	t_file	*p1;
	t_file	*p2;

	p1 = head;
	p2 = head;
	while (head && head->next != NULL && p2->next != NULL)
	{
		if (ft_strcmp(head->name, head->next->name) > 0)
		{
			p1 = p2->next;
			p2->next = p1;
			head = p1;
		}
		else
			head = head->next;
	}
	head = p1;
	return (head);
}

static t_file	*sort_list(t_file *head)
{
	t_file	*prev;
	t_file	*p1;
	t_file	*p2;

	prev = head;
	p1 = prev->next;
	p2 = p1->next;
	while (p2->next != NULL && p1->next != NULL && head->next != NULL)
	{
		ft_putstr("\n-------------------------------------------------\n");
		ft_putstr("First\n");
		ft_putstr("p1->name = ");
		ft_putstr(p1->name);
		ft_putstr("\np2->name = ");
		ft_putstr(p2->name);
		ft_putstr("\n-------------------------------------------------\n");
		if (ft_strcmp(p1->name, p2->name) > 0)
		{
			p1->next = p2->next;
			p2->next = p1;
			prev->next = p2;
			//p2 = p1->next;

			ft_putstr("\n-------------------------------------------------\n");
			ft_putstr("Second\n");
			ft_putstr("p1->name = ");
			ft_putstr(p1->name);
			ft_putstr("\np2->name = ");
			ft_putstr(p2->name);
			ft_putstr("\n-------------------------------------------------\n");

			p1 = head;
			p2 = p1->next;
		}
		else
		{
			p2 = p2->next;
			p1 = p1->next;
		}
	}
	//head = p1;
	return (head);
}*/

static t_file	
*make_list(t_file *head, t_file *new, DIR *dir, t_flag_ls f_list, char *d)
{
	struct dirent	*sd;
	struct passwd	*uid;
	struct group 	*grp;
	struct stat		buf;

	while ((sd = readdir(dir)) != NULL)
	{
		if ((f_list.flag_a == 0) && sd->d_name[0] == '.')
				continue;
		if ((new = (t_file *)malloc(sizeof(t_file))) == NULL)
			return (NULL);
		new->name = sd->d_name;
		/*ft_putstr("\n-------------------------------------------------\n");
		temp = ft_strjoin("cat ","lol");
		ft_putstr(temp);
		ft_putstr("\n-------------------------------------------------\n");*/
		/*ft_putstr("\n-------------------------------------------------\n");
		ft_putstr("sd->name = ");
		ft_putstr(sd->d_name);
		ft_putstr("\nd = ");
		ft_putstr(d);
		ft_putstr("\n-------------------------------------------------\n");
		ft_putstr("\n-------------------------------------------------\n");
		ft_putstr("First append =");
		ft_putstr(ft_strjoin("/",sd->d_name));
		ft_putstr("\nSecond append =");
		ft_putstr(ft_strjoin(d,ft_strjoin("/",sd->d_name)));
		ft_putstr("\n-------------------------------------------------\n");*/
		stat(ft_strjoin(d,ft_strjoin("/",sd->d_name)), &buf);
		//ft_putstr("\n-------------------------------------------------\n");
		//ft_putnbr(f_list.total);
		//ft_putstr("\n-------------------------------------------------\n");
		f_list.total += buf.st_blocks;
		new->st_nlink = buf.st_nlink;
		new->size = buf.st_size;
		new->st_mode = buf.st_mode;

		uid = getpwuid(buf.st_uid);
		grp = getgrgid(buf.st_gid);

		new->st_uid = uid->pw_name;
		new->st_gid = grp->gr_name;
		/*new->st_uid = buf.st_uid;
		new->st_gid = buf.st_gid;*/
		//new->st_time, buf.st_mtimespec;
		new->next = head;
		head = new;
	}
	// print_list(head,f_list);
	head = sort_list(head, f_list);
	return (head);
}

static int		print_ls(char *d, t_flag_ls f_list)
{
	t_file			*new = NULL;
	t_file			*list;
	t_file			*head = NULL;
	DIR				*dir;
	
	if (!d)
		d = ".";
	if (!(dir = opendir(d)))
		return (0);
	
	f_list = get_flags(d, f_list);
	list = make_list(head, new, dir, f_list, d);
	print_list(list, f_list, d);
	closedir(dir);
	return (1);
}

int		main(int argc, char **argv)
{
	int 	i;
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