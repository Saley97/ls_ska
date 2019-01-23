/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 20:59:33 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/23 17:32:31 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	parse_flags(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] == '-' && i < 1)
		++i;
	while (str[i])
	{
		if (str[i] == 'l')
			res |= FLAG_l;
		else if (str[i] == 'R')
			res |= FLAG_R;
		else if (str[i] == 'a')
			res |= FLAG_a;
		else if (str[i] == 'r')
			res |= FLAG_r;
		else if (str[i] == 't')
			res |= FLAG_t;
		else
			return (-i);
		++i;
	}
	return (res);
}

static void inline	print_wrf(char const c)
{
	write(1, FT_LS, sizeof(FT_LS));
	write(1, ILLOPT, sizeof(ILLOPT));
	write(1, &c, 1);
	write(1, "\n", 1);
	write(1, USAGE, sizeof(USAGE));
}

static int			flag_reader(int argc, char **argv, int *flags)
{
	size_t	i;
	int		tmp;

	i = 0;
	*flags = 0;
	while (++i < argc)
	{
		if (argv[i][0] != '-')
			break ;
		tmp = parse_flags(argv[i]);
		if (tmp < 0)
			return (tmp); // if < 0 : illegal oper
		else
			*flags |= tmp;
	}
	if ((argc - i) == 0)
		ft_ls(".", *flags);
	else
	{
		*flags |= FLAG_mult;
		while (++i <= argc)
			ft_ls(argv[i - 1], *flags);
	}
	return (0);
}

int					main(int argc, char **argv)
{
	int	flags;

	if (argc > 1)
	{
		if (flag_reader(argc, argv, &flags) < 0)
		{
			printf("illigal option\n");
			//todo
		}
	}
	else
		ft_ls(".", 0);
	return (0);
}
