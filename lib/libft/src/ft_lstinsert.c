/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 00:52:06 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/23 17:31:35 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <dirent.h>
#include <stdio.h>

/*
 *	1	n1 > n2
 *	0	n1 == n2
 *	-1	n1 < n2
 */

static void	kostil_for_la_norme(t_list **a, t_list *n)
{
	n->next = *a;
	*a = n;
}

void	ft_lstinsert(t_list **alst, t_list *node,
	int (*comp)(void *n1, void *n2))
{
	t_list	*cur;
	t_list	*prev;

	if (!alst || !comp)
		return ;
	if (!*alst)
		*alst = node;
	else if (comp((*alst)->content, node->content) >= 0)
	{
		cur = *alst;
		prev = NULL;
		while (cur && comp(cur->content, node->content) >= 0)
		{
			prev = cur;
			cur = cur->next;
		}
		node->next = cur;
		if (prev)
			prev->next = node;
		else
			(*alst) = node;
	}
	else
		kostil_for_la_norme(alst, node);
}
