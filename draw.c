/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 17:25:52 by ddenkin           #+#    #+#             */
/*   Updated: 2018/03/27 17:08:07 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void		draw_line_h(t_mlx *mlx, t_line l)
{
	t_point		*cur;
	t_addr		ad;

	cur = copy_point(l.start);
	ad.addr = (int *)mlx_get_data_addr(mlx->img, &ad.a, &ad.b, &ad.c);
	while (1)
	{
		if (cur->x >= 0 && cur->x < WIN_W && cur->y >= 0 && cur->y < WIN_H)
			ad.addr[WIN_W * (int)cur->y + (int)cur->x] = pick_color(l, cur);
		if (fabs(cur->x - l.end->x) <= 1.0 && fabs(cur->y - l.end->y) <= 1.0)
			break ;
		l.err2 = l.err;
		if (l.err2 > -l.dx)
		{
			l.err -= l.dy;
			cur->x += l.sx;
		}
		if (l.err2 < l.dy)
		{
			l.err += l.dx;
			cur->y += l.sy;
		}
	}
	free(cur);
}

void		draw_line(t_mlx *mlx, t_point *p1, t_point *p2)
{
	t_line l;

	if (!p1 || !p2)
		return ;
	l.start = copy_point(p1);
	l.end = copy_point(p2);
	apply_v(l.start, mlx->viewer);
	apply_v(l.end, mlx->viewer);
	l.dx = (int)fabs(l.end->x - l.start->x);
	l.sx = (l.start->x < l.end->x) ? 1 : -1;
	l.dy = (int)fabs(l.end->y - l.start->y);
	l.sy = (l.start->y < l.end->y) ? 1 : -1;
	l.err = (int)((l.dx > l.dy) ? l.dx : -l.dy) / 2;
	draw_line_h(mlx, l);
	free(l.start);
	free(l.end);
}

void		epic_magic(t_mlx *m, t_map *map)
{
	int		i;
	int		j;
	int		opi;
	int		opj;
	int		js;

	opj = count_stuff(m, &i, &js, &opi);
	while (i >= 0 && map->points[i])
	{
		j = js;
		while (j >= 0 && map->points[i][j])
		{
			if (map->points[i][j + 1])
				draw_line(m, map->points[i][j], map->points[i][j + 1]);
			if (map->points[i + 1] && map->points[i + 1][j])
				draw_line(m, map->points[i][j], map->points[i + 1][j]);
			j += opj;
		}
		i += opi;
	}
}

void		apply_offset(t_mlx *mlx, t_map *map, t_viewer *v)
{
	double		h;
	double		w;

	h = get_h(map, mlx);
	w = get_w(map, mlx);
	v->scale = count_scale(h, w, mlx);
	v->off_x = -(map->minx) * v->scale;
	v->off_y = -(map->miny) * v->scale;
	v->off_x += (WIN_W - w * v->scale) / 2 + v->add_x;
	v->off_y += (WIN_H - h * v->scale) / 2 + v->add_y;
}

void		draw_map(t_mlx *mlx)
{
	t_map	*map;

	map = copy_map(mlx->map, mlx->viewer);
	apply_offset(mlx, map, mlx->viewer);
	epic_magic(mlx, map);
	free_map(&map);
}
