/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matr_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 17:44:11 by ddenkin           #+#    #+#             */
/*   Updated: 2018/03/21 17:47:20 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

t_point		*transform_iso(t_point p, t_viewer *v)
{
	t_point	*res;
	double	x;
	double	y;
	double	z;

	x = p.x;
	y = p.y;
	z = p.z;
	res = (t_point *)malloc(sizeof(t_point));
	res->y = cos(v->x) * y + sin(v->x) * z;
	res->z = -sin(v->x) * y + cos(v->x) * z;
	z = res->z;
	res->x = cos(v->y) * x + sin(v->y) * z;
	res->z = -sin(v->y) * x + cos(v->y) * z;
	res->color = p.color;
	return (res);
}

t_point		*transform_ort(t_point p)
{
	t_point *res;

	res = (t_point *)malloc(sizeof(t_point));
	res->x = p.x;
	res->y = p.y;
	res->z = 0;
	res->color = p.color;
	return (res);
}

void		transform_clock(t_point *p, t_viewer *v)
{
	double	x;
	double	y;

	x = p->x;
	y = p->y;
	p->x = cos(v->a) * x - sin(v->a) * y;
	p->y = sin(v->a) * x + cos(v->a) * y;
}

t_point		*copy_point(t_point *p)
{
	t_point *res;

	res = (t_point *)malloc(sizeof(t_point));
	res->x = p->x;
	res->y = p->y;
	res->z = p->z;
	res->color = p->color;
	return (res);
}

t_map		*copy_map(t_map *m, t_viewer *v)
{
	int		i;
	int		j;
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->height = m->height;
	map->width = m->width;
	map->points = malloc(sizeof(t_point **) * (m->height + 1));
	i = 0;
	while (i < m->height)
	{
		map->points[i] = (t_point **)malloc(sizeof(t_point *) * (m->width + 1));
		j = 0;
		while (j < m->width)
		{
			map->points[i][j] = transform_iso(*m->points[i][j], v);
			transform_clock(map->points[i][j], v);
			j++;
		}
		map->points[i][j] = NULL;
		i++;
	}
	map->points[i] = NULL;
	return (map);
}
