/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 17:38:26 by ddenkin           #+#    #+#             */
/*   Updated: 2018/03/21 17:39:10 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void		free_map(t_map **map)
{
	int		i;
	int		j;

	i = -1;
	while (++i < (*map)->height)
	{
		j = -1;
		while (++j <= (*map)->width)
			free((*map)->points[i][j]);
		free((*map)->points[i]);
	}
	free((*map)->points);
	free(*map);
}
