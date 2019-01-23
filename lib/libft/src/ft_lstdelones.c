/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelones.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 23:35:56 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/22 03:35:31 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	ft_lstdelones(t_list **alst)
{
	if (!alst || !*alst)
		return ;
	free((*alst)->content);
	free(*alst);
	*alst = NULL;
}
