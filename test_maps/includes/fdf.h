/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:54:05 by jraivio           #+#    #+#             */
/*   Updated: 2022/10/11 17:49:25 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include <mlx.h>
# define SCREEN_W 1920
# define SCREEN_H 1080
# define PADDING 100
# define WINDOW_NAME "FDF"
# define COLOR 0x0000FF00
# define MAX_MAP_X 1000
# define MAX_MAP_Y 1000
# define HEIGHTSCALAR 1
# define MIN_HEIGHT -42
# define MAX_HEIGHT 42

typedef struct s_coord {
	int	x;
	int	y;
}				t_coord;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_map {
	int			map[MAX_MAP_Y][MAX_MAP_X];
	t_coord		size;
	float		min_z;
	float		max_z;
}				t_map;

typedef struct s_frame {
	void	*mlx;
	void	*window;
	t_map	map;
}			t_frame;

typedef enum e_projection {
	military,
	isometric
}	t_projection;

void	render(void *mlx, void *window, t_map *map, t_projection projection);
void	init_map(char *file, t_map *map);
void	panic(char *message);
int		key_hook(int key_code, t_frame *params);

#endif 
