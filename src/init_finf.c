/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_finf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:24:59 by edraugr-          #+#    #+#             */
/*   Updated: 2019/01/23 18:18:14 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_finf	*init_finf(const char *path, const t_dir *dir, const int flags)
{
	t_finf	*res;
	char 	*full_path;
	t_stat	*stat;

	if (!(res = (t_finf *)malloc(sizeof(t_finf))))
		return (NULL);
	res->dir = (t_dir *)dir;
	res->path = (char *)path;
	if (flags & (FLAG_l | FLAG_t))
	{
		if((stat = (t_stat *)malloc(sizeof(t_stat))))
		{
			full_path = ft_strjoin("/", path);
			lstat(full_path, stat) ? 0 : printf("q"); // (if != 0) => exeption
			res->stat = stat;
			free(full_path);
		}
	}
	else
		res->stat = NULL;
	res->name = (char *)dir->d_name;
	return (res);
}
