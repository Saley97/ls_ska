/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 20:56:59 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/23 17:17:50 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <dirent.h>
# include <stdio.h>
# include <sys/stat.h>
# include <time.h>

# define FLAG_l			(1 << 0)
# define FLAG_R			(1 << 1)
# define FLAG_a			(1 << 2)
# define FLAG_r			(1 << 3)
# define FLAG_t			(1 << 4)

# define FLAG_mult		(1 << 12)

# define FT_LS			"./ft_ls: "
# define ILLOPT			"illegal option -- "
# define USAGE			"usage: ./ft_ls [-lRart] [file ...]"
# define NOFILE			"No such file or directory"

typedef struct dirent	t_dir;
typedef struct stat		t_stat;
typedef struct			s_finfo
{
	char				*name;
	char				*path;
	t_stat				*stat;
	t_dir				*dir;
}						t_finf;

int						ft_ls(char const *fn, int flags);
int						read_dirs(void);
t_finf					*init_finf(const char *path, const t_dir *dir, const int flags);
void					lst_insert_new(char const *fn, int const flags, const t_dir *dir, t_list **root);

void					print4(char const *s1, char const *s2,
							char const *s3, char const *s4);


#endif
