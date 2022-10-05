/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:43:57 by jraivio           #+#    #+#             */
/*   Updated: 2022/10/05 21:25:34 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		max(int x, int y)
{
	if (x < y)
		return (y);
	return (x);
}

void	add_pixel(t_img *img, long x, long y, int color)
{
	char	*dst;

	dst = img->addr + (\
		y * img->line_length + \
		x * (img->bits_per_pixel / 8) \
		);
	*(unsigned int *)dst = color;
}

void	add_line(t_img *img, t_coord start, t_coord end, int color)
{
	float	cur_x;
	float	cur_y;
	float	step_x;
	float	step_y;
	int		steps;

	steps = max(abs(start.x - end.x), abs(start.y - end.y));
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

void	render(void *mlx, void *window, t_map *map)
{
	t_img	img;

	//init_img
	img.img = mlx_new_image(mlx, SCREEN_W, SCREEN_H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	//draw_image
	add_pixel(&img, 100, 100, 0x00FFFFFF);
	add_pixel(&img, 200, 200, 0x00FFFFFF);
	add_line(&img, (t_coord){100,100}, (t_coord){400, 235}, 0x00FF0000);
	mlx_put_image_to_window(mlx, window, img.img, 0, 0);
	//destroy_img
	(void)map;
}
