/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:43:57 by jraivio           #+#    #+#             */
/*   Updated: 2022/10/07 10:25:17 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	add_pixel(t_img *img, long x, long y, int color)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_W || y < 0 || y >= SCREEN_H)
		return ;
	dst = img->addr + (\
		y * img->line_length + \
		x * (img->bits_per_pixel / 8) \
		);
	*(unsigned int *)dst = color;
}

void	add_line(t_img *img, t_coord start, t_coord end, int color)
{
	float		cur_x;
	float		cur_y;
	float		step_x;
	float		step_y;
	int64_t		steps;

	steps = ft_intmax(abs(start.x - end.x), abs(start.y - end.y));
	cur_x = start.x;
	cur_y = start.y;
	step_x = ((float)end.x - (float)start.x) / steps;
	step_y = ((float)end.y - (float)start.y) / steps;
	while (0 <= steps--)
	{
		add_pixel(img, round(cur_x), round(cur_y), color);
		cur_x += step_x;
		cur_y += step_y;
	}
}

t_coord	get_point_coords(int x, int y, t_map *map)
{
	float	zoomscalar;
	float	rx;
	float	ry;
	float	offset_x;
	float	offset_y;

	(void)map;
	zoomscalar = (float)SCREEN_H / \
				(float)ft_intmax((map->size.x + map->size.y), \
			(map->max_z - map->min_z));
	offset_x = ((map->size.x - map->size.y) * zoomscalar / 2);
	offset_y = ((map->size.x + map->size.y) * zoomscalar / 2);
	rx = x - y;
	ry = x + y;
	ry -= HEIGHTSCALAR * map->map[y][x];
	return ((t_coord){round(rx * zoomscalar + SCREEN_W / 2 - offset_x), \
			round(ry * zoomscalar - offset_y + SCREEN_H / 2)});
}

void	draw_grid(t_img *img, t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->size.y)
	{
		while (x < map->size.x)
		{
			if (x + 1 < map->size.x)
				add_line(img, get_point_coords(x, y, map), \
						get_point_coords(x + 1, y, map), COLOR);
			if (y + 1 < map->size.y)
				add_line(img, get_point_coords(x, y, map), \
						get_point_coords(x, y + 1, map), COLOR);
			x++;
		}
		y++;
		x = 0;
	}
}

void	render(void *mlx, void *window, t_map *map)
{
	t_img	img;

	img.img = mlx_new_image(mlx, SCREEN_W, SCREEN_H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
			&img.line_length, &img.endian);
	draw_grid(&img, map);
	mlx_put_image_to_window(mlx, window, img.img, 0, 0);
	mlx_destroy_image(mlx, img.img);
	(void)map;
}
