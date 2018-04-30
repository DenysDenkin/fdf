/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 17:38:31 by ddenkin           #+#    #+#             */
/*   Updated: 2018/03/21 18:59:12 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

static void	mlx_clear_image(t_mlx *mlx)
{
	int			*addr;
	int			a;
	int			b;
	int			c;

	addr = (int *)mlx_get_data_addr(mlx->img, &a, &b, &c);
	ft_bzero(addr, WIN_H * WIN_W * 4);
}

int			hook_mousepress(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (button == 4)
		mlx->viewer->scale = ft_max(mlx->viewer->scale + 1, mlx->viewer->scale
															* 1.1);
	else if (button == 5)
		(mlx->viewer->scale > 1) ? mlx->viewer->scale *= 0.9 : 1;
	else if (button == 6)
		mlx->viewer->a -= to_rad(10);
	else if (button == 7)
		mlx->viewer->a += to_rad(10);
	mlx_clear_image(mlx);
	draw_map(mlx);
	mlx_put_image_to_window(mlx, mlx->window, mlx->img, 0, 0);
	return (0);
}
