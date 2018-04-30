/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 17:38:41 by ddenkin           #+#    #+#             */
/*   Updated: 2018/03/21 17:42:15 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void			change_colors(t_mlx *mlx)
{
	int			i;
	int			j;
	static int	iter = 0;

	i = -1;
	while (mlx->map->points[++i])
	{
		j = -1;
		while (mlx->map->points[i][++j])
			mlx->map->points[i][j]->color = (int)(0x000066 + 0x000099 *
				mlx->map->points[i][j]->z / mlx->map->zmax) << 8 * (iter % 3);
	}
	iter++;
}

static void		mlx_clear_image(t_mlx *mlx)
{
	int			*addr;
	int			a;
	int			b;
	int			c;

	addr = (int *)mlx_get_data_addr(mlx->img, &a, &b, &c);
	ft_bzero(addr, WIN_H * WIN_W * 4);
}

int				hook_keypress(int key, t_mlx *mlx)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == 123)
		mlx->viewer->y -= to_rad(10);
	else if (key == 124)
		mlx->viewer->y += to_rad(10);
	else if (key == 125)
		mlx->viewer->x -= to_rad(10);
	else if (key == 126)
		mlx->viewer->x += to_rad(10);
	else if (key == 0)
		mlx->viewer->add_x -= 10;
	else if (key == 1)
		mlx->viewer->add_y += 10;
	else if (key == 2)
		mlx->viewer->add_x += 10;
	else if (key == 13)
		mlx->viewer->add_y -= 10;
	else if (key == 8)
		change_colors(mlx);
	mlx_clear_image(mlx);
	draw_map(mlx);
	mlx_put_image_to_window(mlx, mlx->window, mlx->img, 0, 0);
	return (0);
}
