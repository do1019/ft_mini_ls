/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 01:59:16 by dogata            #+#    #+#             */
/*   Updated: 2021/01/24 19:14:53 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

static int	putstr_err(char *s)
{
	ft_putstr_fd("ERROR\n", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\n", 2);
	return (ERROR);
}

static int	get_lst(t_lst **lst, t_lst **lst_tmp, int *lst_count, DIR *dirp)
{
	char			*tmp;
	struct dirent	*entry;
	struct stat		buf;

	(*lst_count) = 0;
	*lst = NULL;
	while ((entry = readdir(dirp)))
	{
		if ((ft_memcmp(entry->d_name, ".", 1)))
		{
			if (!(tmp = ft_strjoin("./", entry->d_name)))
				return (ERROR);
			if (lstat(tmp, &buf) == ERROR)
			{
				free(tmp);
				return (ERROR);
			}
			free(tmp);
			if (!(*lst_tmp = ft_lstnew_ls(entry->d_name,
				buf.st_mtimespec.tv_sec, buf.st_mtimespec.tv_nsec)))
				return (ERROR);
			ft_lstadd_back_ls(&lst, lst_tmp, &lst_count);
		}
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_lst	*lst;
	t_lst	*lst_tmp;
	DIR		*dirp;
	int		lst_count;

	if (argc > 1)
		return (putstr_err("Specified command line argument"));
	else
	{
		dirp = opendir("./");
		if ((get_lst(&lst, &lst_tmp, &lst_count, dirp) == ERROR))
			return (ERROR);
		ft_lstsort(&lst, lst_count);
		lst_tmp = lst;
		while (lst_count--)
		{
			ft_putstr_fd(lst->name, 1);
			ft_putstr_fd("\n", 1);
			lst = lst->next;
		}
		ft_lstclear_ls(&lst_tmp);
		closedir(dirp);
	}
	(void)argv;
	return (0);
}
