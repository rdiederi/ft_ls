t_dlist		*add_environ(t_dlist *env, char *str, char *str2)
{
	t_dlist	*tmp;
	int		i;
	int		z;

	z = 0;
	i = 0;
	tmp = create_node();
	if ((tmp->data = malloc(ft_strlen(str) + ft_strlen(str2) + 2)) == NULL)
		ft_puterror("Problem with a memory allocation\n");
	while (str2 && str2[i] != '\0')
		tmp->data[z++] = str2[i++];
	i = 0;
	tmp->data[z++] = '=';
	while (str && str[i] != '\0')
		tmp->data[z++] = str[i++];
	tmp->data[z] = '\0';

	tmp->prev = env->prev;
	tmp->next = env;
	env->prev->next = tmp;
	env->prev = tmp;
	return (env);
}

t_dlist        *init_listenv(char **env)
{
    t_dlist    *tmp;
    t_dlist    *tmp2;
    int        i;
    int        j;

    tmp = create_node();
    i = 0;
    j = 0;
    while (env[i] != NULL)
    {
        j = -1;
        tmp2 = create_node();
        if ((tmp2->data = malloc(ft_strlen(env[i]) + 1)) == NULL)
            ft_puterror("Error with a memory allocation");
        while (env[i][++j] != '\0')
            tmp2->data[j] = env[i][j];
        tmp2->data[j] = '\0';

        tmp2->prev = tmp->prev;
        tmp2->next = tmp;
		tmp->prev->next = tmp2;
        tmp->prev = tmp2;
        i++;
    }
    return (tmp);
}

void    movelinkbackbyone(t_dir *dir, t_statinfo *b, t_statinfo *c)
{
    t_statinfo    *a;
    t_statinfo    *tmpb;
    t_statinfo    *tmpc;
    int            flag;

    a = dir->files;
    tmpb = b;
    tmpc = c;
    flag = 0;
    if (ft_strcmp(a->name, b->name) != 0)
    {
        flag = 1;
        while (ft_strcmp(a->next->name, b->name) != 0)
            a = a->next;
    }
    if (flag == 1)
        a->next = tmpc;
    else
        dir->files = tmpc;
    tmpb->next = tmpc->next;
    tmpc->next = tmpb;
}


void    alphasortfile(t_dir *tmp)
{
    t_statinfo    *file;

    file = tmp->files;
    while (file)
    {
        if (file->next != NULL && stringcomp(file->name, file->next->name) == 1)
        {
            movelinkbackbyone(tmp, file, file->next);
            file = tmp->files;
        }
        else
            file = file->next;
    }
}