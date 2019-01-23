/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_insert_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:58:58 by edraugr-          #+#    #+#             */
/*   Updated: 2019/01/23 18:05:46 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	comp_dirs(void *d1, void *d2)
{
	char	*d1n;
	char	*d2n;

	d1n = ((t_finf *)d1)->name;
	d2n = ((t_finf *)d2)->name;
	while (*d1n == *d2n)
	{
		++d1n;
		++d2n;
	}
	return (*d2n - *d1n);
}

static int	comp_dirs_r(void *d1, void *d2)
{
	return (-(comp_dirs(d1, d2)));
}

static int	comp_dirs_t(void *d1, void *d2)
{
	long	d1v;
	long	d2v;

	d1v = (((t_finf *)d1)->stat)->st_mtimespec.tv_sec;
	d2v = (((t_finf *)d2)->stat)->st_mtimespec.tv_sec;
	printf("file 1: %s whith %llu bytes\n", (((t_finf *)d1)->dir)->d_name, (((t_finf *)d1)->stat)->st_size);
	printf("file 2: %s whith %llu bytes\n", (((t_finf *)d2)->dir)->d_name, (((t_finf *)d2)->stat)->st_size);
	printf("|(%ld , %ld)|\n", d1v, d2v);
	printf("|(%d)|\n", (int)(d2v - d1v));
	printf("___________________________________________\n");
	if (d1v != d2v)
		return ((int)(d2v - d1v));
	d1v = (((t_finf *)d1)->stat)->st_mtimespec.tv_nsec;
	d2v = (((t_finf *)d2)->stat)->st_mtimespec.tv_nsec;
	return ((int)(d2v - d1v));
	//return (comp_dirs(d1, d2));
}

static int	comp_dirs_rt(void *d1, void *d2)
{
	return (-(comp_dirs_t(d1, d2)));
}

void		lst_insert_new(char const *fn, int const flags, const t_dir *dir, t_list **root)
{
	t_list	*new;

	new = ft_lstnew((void *)init_finf(fn, dir, flags), sizeof(t_finf));
	if (flags & FLAG_r)
	{
		if (flags & FLAG_t)
			ft_lstinsert(root, new, &comp_dirs_rt);
		else
			ft_lstinsert(root, new, &comp_dirs_r);
	}
	else
	{
		if (flags & FLAG_t)
			ft_lstinsert(root, new, &comp_dirs_t);
		else
			ft_lstinsert(root, new, &comp_dirs);
	}
}
