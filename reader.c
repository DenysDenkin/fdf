/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:25:39 by ddenkin           #+#    #+#             */
/*   Updated: 2018/03/29 18:55:27 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int				read_file(char *fname, t_map *tm)
{
	int		fd;
	int		i;
	char	**map;

	if ((fd = open(fname, O_RDONLY)) == -1)
		return (-1);
	i = 0;
	map = (char **)malloc(sizeof(char *) * (tm->height + 1));
	while (get_next_line(fd, map + i) > 0)
		i++;
	map[i] = NULL;
	tm->points = (t_point ***)malloc(sizeof(t_point**) * (tm->height + 1));
	tm->points[tm->height] = NULL;
	fill_map(map, tm);
	free(map);
	tm->points[i] = NULL;
	return (1);
}

void			draw(t_mlx *mlx) {
	mlx->viewer = (t_viewer *) malloc(sizeof(t_viewer));
	mlx->viewer->x = to_rad(-40);
	mlx->viewer->y = to_rad(-40);
	mlx->viewer->a = to_rad(0);
	mlx->viewer->scale = 0;
	mlx->viewer->off_x = 0;
	mlx->viewer->off_y = 0;
	mlx->viewer->add_x = 0;
	mlx->viewer->add_y = 0;
	draw_map(mlx);
	mlx_put_image_to_window(mlx, mlx->window, mlx->img, 0, 0);
}

int				main(int argc, char **argv)
{
	t_mlx	*mlx;
	char	*n;

	if (argc >= 2)
	{
		int i = -1;
		while (++i < argc - 2)
			if (fork() != 0)
				argv++;
			else
				break ;
		mlx = (t_mlx *)malloc(sizeof(t_mlx));
		mlx->mlx = mlx_init();
		n = (ft_strrchr(argv[0], '/')) ? ft_strrchr(argv[0], '/') + 1 : argv[0];
		mlx->window = mlx_new_window(mlx->mlx, WIN_W, WIN_H, n);
		mlx->img = mlx_new_image(mlx->mlx, WIN_W, WIN_H);
		mlx->hwindow = mlx_new_window(mlx->mlx, 600, 250, "Help");
		get_help(mlx);
		mlx->map = (t_map *)malloc(sizeof(t_map));
		count_f(argv[1], &(mlx->map->height), &(mlx->map->width));
		if (mlx->map->height == -1 || mlx->map->width == -1)
		{
			ft_putstr_fd("Map error\n", 2);
			return (-1);
		}
		read_file(argv[1], mlx->map);
		draw(mlx);
		mlx_hook(mlx->window, 2, 5, hook_keypress, mlx);
		mlx_mouse_hook(mlx->window, hook_mousepress, mlx);
		mlx_loop(mlx->mlx);
	}
}
