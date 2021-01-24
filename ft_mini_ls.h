/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 01:59:44 by dogata            #+#    #+#             */
/*   Updated: 2020/12/04 01:18:00 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINI_LS_H
# define FT_MINI_LS_H

# include <unistd.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <dirent.h>
# include <stdio.h>
# include <time.h>

# include "libft/libft.h"

# define ERROR -1

typedef struct		s_lst
{
	struct s_lst	*prev;
	char			*name;
	long			tv_sec;
	long			tv_nsec;
	struct s_lst	*next;
}					t_lst;

t_lst				*ft_lstnew_ls(char *name, long tv_sec, long tv_nsec);
void				ft_lstadd_back_ls(t_lst ***lst,
								t_lst **new, int **lst_count);
void				ft_lstclear_ls(t_lst **lst);
void				ft_lstsort(t_lst **lst, int lst_count);

#endif
