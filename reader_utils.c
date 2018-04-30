/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 18:25:18 by ddenkin           #+#    #+#             */
/*   Updated: 2018/03/21 18:46:12 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void		get_help(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx, mlx->hwindow, 10, 10, 0xFFFFFF, "Scroll up/down to"
			" zoom in/out");
	mlx_string_put(mlx->mlx, mlx->hwindow, 10, 40, 0xFFFFFF, "Scroll right to "
			"rotate object clockwise");
	mlx_string_put(mlx->mlx, mlx->hwindow, 10, 70, 0xFFFFFF, "Scroll left to "
			"rotate object counter-clockwise");
	mlx_string_put(mlx->mlx, mlx->hwindow, 10, 100, 0xFFFFFF, "Press right/left"
			" arrows to rotate object in y-plane");
	mlx_string_put(mlx->mlx, mlx->hwindow, 10, 130, 0xFFFFFF, "Press up/down "
			"arrows to rotate object in x-plane");
	mlx_string_put(mlx->mlx, mlx->hwindow, 10, 160, 0xFFFFFF, "Press 'C' to "
			"change color to blue/green/red. Hold for DISCO");
	mlx_string_put(mlx->mlx, mlx->hwindow, 10, 190, 0xFFFFFF, "Press Esc to "
			"exit");
}

void		count_f(char *fname, int *lines, int *lsize)
{
	int		fd;
	char	*tmp;
	int		l;

	fd = open(fname, O_RDONLY);
	*lines = 0;
	*lsize = 0;
	l = 0;
	while (get_next_line(fd, &tmp) > 0)
	{
		l++;
		(*lines)++;
		if (*lines == 1)
			*lsize = get_lsize(tmp);
		else if (*lsize != get_lsize(tmp))
		{
			*lines = -1;
			*lsize = -1;
			free(tmp);
			return ;
		}
		free(tmp);
	}
	if (l == 0)
		*lines = -1;
}

int			get_lsize(char *tmp)
{
	int		res;

	res = 0;
	while (*tmp)
	{
		if (ft_isdigit(*tmp))
		{
			res++;
			tmp++;
			while (*tmp && *tmp != ' ')
				tmp++;
		}
		else
			tmp++;
	}
	return (res);
}

void		fill_map(char **map, t_map *tm)
{
	int		i;
	int		j;
	char	*lstart;

	i = -1;
	tm->zmax = (int)INT_MIN;
	while (map[++i] && i < tm->height)
	{
		lstart = map[i];
		tm->points[i] = (t_point **)malloc(sizeof(t_point *) * (tm->width + 1));
		j = -1;
		while (++j > -1 && *(map[i]) && has_num(map[i]))
		{
			tm->points[i][j] = (t_point *)malloc(sizeof(t_point) * 1);
			tm->points[i][j]->x = j;
			tm->points[i][j]->y = i;
			tm->points[i][j]->z = ft_get_number(&map[i]);
			tm->zmax = fmax(tm->points[i][j]->z, tm->zmax);
			tm->points[i][j]->color = (*map[i] == ',' && map[i]++) ?
									ft_get_color(&map[i]) : 0xFFFFFF;
		}
		tm->points[i][j] = NULL;
		free(lstart);
	}
}
