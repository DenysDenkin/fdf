/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 17:46:40 by ddenkin           #+#    #+#             */
/*   Updated: 2018/03/21 17:49:55 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int			pick_color(t_line l, t_point *cur)
{
	int		red;
	int		green;
	int		blue;
	double	distance;

	if (fabs(l.end->x - l.start->x) > 0.1)
		distance = fabs(cur->x - l.start->x) / fabs(l.end->x - l.start->x);
	else if (fabs(l.end->y - l.start->y) > 0.1)
		distance = fabs(cur->y - l.start->y) / fabs(l.end->y - l.start->y);
	else
		distance = 0;
	red = ((int)l.start->color >> 16) + (double)(((int)l.end->color >> 16)
									- ((int)l.start->color >> 16)) * distance;
	green = ((int)l.start->color % 65536 >> 8) +
	(double)(((int)l.end->color % 65536 >> 8) - ((int)l.start->color % 65536
					>> 8)) * distance;
	blue = ((int)l.start->color % 256) + (double)(((int)l.end->color %
			256) - ((int)l.start->color % 256)) * distance;
	return ((red << 16) + (green << 8) + blue);
}

double		get_h(t_map *map, t_mlx *mlx)
{
	double	min;
	double	max;
	int		i;
	int		j;

	i = 0;
	min = 0;
	max = 0;
	while (i < map->height)
	{
		j = 0;
		(i == 0) ? min = map->points[i][j]->y : 1;
		(i == 0) ? max = map->points[i][j]->y : 1;
		while (j < map->width)
		{
			min = fmin(min, map->points[i][j]->y);
			max = fmax(max, map->points[i][j]->y);
			j++;
		}
		i++;
	}
	mlx->viewer->off_y -= (min < 0) ? min - 1 : min;
	map->miny = min;
	return (max - min);
}

double		get_w(t_map *map, t_mlx *mlx)
{
	double	min;
	double	max;
	int		i;
	int		j;

	i = 0;
	min = 0;
	max = 0;
	while (i < map->height)
	{
		j = 0;
		(i == 0) ? min = map->points[i][j]->x : 1;
		(i == 0) ? max = map->points[i][j]->x : 1;
		while (j < map->width)
		{
			min = fmin(min, map->points[i][j]->x);
			max = fmax(max, map->points[i][j]->x);
			j++;
		}
		i++;
	}
	mlx->viewer->off_x -= (min < 0) ? min - 1 : min;
	map->minx = min;
	return (max - min);
}

int			count_scale(double h, double w, t_mlx *mlx)
{
	int		res;

	if (mlx->viewer->scale != 0)
		return (mlx->viewer->scale);
	res = (int)fmin(WIN_H / h, WIN_W / w) - 1;
	if (res <= 0)
		return (1);
	return (res);
}

int			count_stuff(t_mlx *m, int *i, int *js, int *opi)
{
	double	x;
	double	y;
	int		opj;

	x = m->viewer->x;
	y = m->viewer->y;
	*i = (sin(x) * cos(y) > 0) ? m->map->height - 1 : 0;
	*opi = (*i > 0) ? -1 : 1;
	*js = ((sin(x) * cos(y) > 0 && cos(x) < 0)
		|| (sin(x) < 0 && cos(y) > 0)) ? 0 : m->map->width - 1;
	opj = (*js > 0) ? -1 : 1;
	if (fabs(sin(x)) < 0.01)
	{
		*i = 0;
		*opi = 1;
		(sin(y) < 0) ? *js = 0 : 1;
		(sin(y) < 0) ? opj = 1 : 1;
		(sin(y) > 0) ? *js = m->map->width - 1 : 1;
		(sin(y) > 0) ? opj = -1 : 1;
	}
	return (opj);
}
