/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 17:38:33 by ddenkin           #+#    #+#             */
/*   Updated: 2018/03/21 17:43:22 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int		ft_get_color(char **s)
{
	int res;

	res = 0;
	if ((*s)[0] == '0' && (*s)[1] == 'x')
		*s += 2;
	while (**s && **s != ' ')
	{
		if (ft_isdigit(**s))
		{
			res *= 16;
			res += **s - 48;
		}
		else if (ft_tolower(**s) >= 'a' && ft_tolower(**s) <= 'f')
		{
			res *= 16;
			res += ft_tolower(**s) - 'a' + 10;
		}
		(*s)++;
	}
	return (res);
}

double	to_deg(double rad)
{
	return (rad * (180.0 / M_PI));
}

double	to_rad(double deg)
{
	return (deg * (M_PI / 180.0));
}

int		has_num(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (ft_isdigit(*s))
			return (1);
		s++;
	}
	return (0);
}

void	apply_v(t_point *p, t_viewer *v)
{
	p->x *= v->scale;
	p->y *= v->scale;
	p->x += v->off_x;
	p->y += v->off_y;
}
