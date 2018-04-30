/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:09:20 by ddenkin           #+#    #+#             */
/*   Updated: 2018/03/21 18:33:06 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# define WIN_W  1280
# define WIN_H  720
# define INT_MIN 2147483648

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
	double		color;
}				t_point;

typedef struct	s_map
{
	int			width;
	int			height;
	double		minx;
	double		miny;
	t_point		***points;
	double		zmax;
}				t_map;

typedef struct	s_line
{
	t_point		*start;
	t_point		*end;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			err2;
}				t_line;

typedef struct	s_viewer
{
	double		off_x;
	double		off_y;
	double		add_x;
	double		add_y;
	double		x;
	double		y;
	double		a;
	int			scale;
	double		**matrix;
}				t_viewer;

typedef	struct	s_mlx
{
	void		*mlx;
	void		*window;
	void		*hwindow;
	void		*img;
	t_map		*map;
	t_viewer	*viewer;
	int			colormode;
}				t_mlx;

typedef struct	s_addr
{
	int			*addr;
	int			a;
	int			b;
	int			c;
}				t_addr;

void			count_f(char *fname, int *lines, int *lsize);
void			get_help(t_mlx *mlx);
int				get_lsize(char *tmp);
void			fill_map(char **map, t_map *tm);
void			draw_line(t_mlx *mlx, t_point *p1, t_point *p2);
int				ft_get_color(char **s);
t_point			*transform_iso(t_point p, t_viewer *v);
void			transform_clock(t_point *p, t_viewer *v);
t_point			*transform_ort(t_point p);
void			apply_v(t_point *p, t_viewer *v);
void			draw_map(t_mlx *mlx);
double			to_deg(double rad);
double			to_rad(double deg);
int				has_num(char *s);
void			free_map(t_map **map);
t_map			*copy_map(t_map *m, t_viewer *v);
t_point			*copy_point(t_point *p);
int				pick_color(t_line l, t_point *cur);
double			get_h(t_map *map, t_mlx *mlx);
double			get_w(t_map *map, t_mlx *mlx);
int				count_scale(double h, double w, t_mlx *mlx);
int				count_stuff(t_mlx *m, int *i, int *js, int *opi);

int				hook_keypress(int key, t_mlx *mlx);
int				hook_mousepress(int button, int x, int y, t_mlx *mlx);
#endif
