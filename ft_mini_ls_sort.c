/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 01:13:57 by dogata            #+#    #+#             */
/*   Updated: 2020/12/04 01:28:00 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

static void	swap(t_lst ***current)
{
	char	*tmp1;
	long	tmp2;

	tmp1 = (**current)->name;
	(**current)->name = (**current)->next->name;
	(**current)->next->name = tmp1;
	tmp2 = (**current)->tv_sec;
	(**current)->tv_sec = (**current)->next->tv_sec;
	(**current)->next->tv_sec = tmp2;
	tmp2 = (**current)->tv_nsec;
	(**current)->tv_nsec = (**current)->next->tv_nsec;
	(**current)->next->tv_nsec = tmp2;
	(**current) = (**current)->next;
}

static void	bubble_sort(t_lst **current)
{
	if ((*current)->tv_sec > (*current)->next->tv_sec)
		swap(&current);
	else if ((*current)->tv_sec < (*current)->next->tv_sec)
		(*current) = (*current)->next;
	else if ((*current)->tv_nsec > (*current)->next->tv_nsec)
		swap(&current);
	else if ((*current)->tv_nsec < (*current)->next->tv_nsec)
		(*current) = (*current)->next;
	else if (ft_memcmp((*current)->name, (*current)->next->name,
				ft_strlen((*current)->name) + 1) < 0)
		swap(&current);
	else
		(*current) = (*current)->next;
}

void		ft_lstsort(t_lst **lst, int lst_count)
{
	int		i;
	int		j;
	t_lst	*current;

	i = 0;
	j = 0;
	while (i++ < lst_count - 1)
	{
		current = *lst;
		while (j++ < lst_count - 1)
			bubble_sort(&current);
		j = 0 + i;
	}
}
