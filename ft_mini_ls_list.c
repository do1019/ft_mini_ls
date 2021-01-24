/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 20:51:55 by dogata            #+#    #+#             */
/*   Updated: 2021/01/24 19:19:20 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

t_lst	*ft_lstnew_ls(char *name, long tv_sec, long tv_nsec)
{
	t_lst *lst;

	if (!(lst = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	lst->prev = NULL;
	lst->name = ft_strdup(name);
	lst->tv_sec = tv_sec;
	lst->tv_nsec = tv_nsec;
	lst->next = NULL;
	return (lst);
}

void	ft_lstadd_back_ls(t_lst ***lst, t_lst **new, int **lst_count)
{
	t_lst *current;

	if (*new == NULL)
		return ;
	(**lst_count)++;
	if (**lst == NULL)
	{
		**lst = *new;
		(**lst)->next = NULL;
	}
	current = **lst;
	while (current->next != NULL)
		current = current->next;
	current->next = *new;
	(*new)->prev = current;
	(*new)->next = NULL;
}

void	ft_lstclear_ls(t_lst **lst)
{
	t_lst *current;
	t_lst *next;

	if (!lst)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		free(current->name);
		free(current);
		current = next;
	}
	*lst = NULL;
}
