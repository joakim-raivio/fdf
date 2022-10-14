/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 22:00:36 by jraivio           #+#    #+#             */
/*   Updated: 2022/10/11 19:56:43 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <math.h>

void	check_z_extremity(t_map *map, t_coord pos)
{
	int	z;

	z = (float)(pos.y + pos.x) - (float)map->map[pos.y][pos.x] * HEIGHTSCALAR;
	if (z < map->min_z)
		map->min_z = z;
	else if (z > map->max_z)
		map->max_z = z;
}

void	parse_map_line(char *line, t_map *map)
{
	int		line_size;
	char	**line_coords;

	line_size = ft_countwords(line, ' ');
	if (map->size.x == -1)
		map->size.x = line_size;
	if (line_size != map->size.x || line_size == 0)
	{
		panic("Line size mismatched.");
	}
	line_coords = ft_strsplit(line, ' ');
	while (line_size-- > 0)
	{
		map->map[map->size.y - 1][line_size] = \
			ft_clampint(ft_atoi(line_coords[line_size]), \
			MIN_HEIGHT, MAX_HEIGHT);
		check_z_extremity(map, (t_coord){line_size, map->size.y - 1});
	}
	ft_freearray(&line_coords, map->size.x);
}

void	init_map(char *file, t_map *map)
{
	int		fd;
	char	*line;

	ft_bzero(map, sizeof(t_map));
	map->size.x = -1;
	map->size.y = 0;
	map->min_z = 0;
	map->max_z = 0;
	fd = open(file, O_RDONLY);
	if (!fd || fd < 0)
		panic("Error opening file");
	while (get_next_line(fd, &line))
	{
		if (map->size.y++ >= MAX_MAP_Y)
			panic("Map input Y too large.");
		parse_map_line(line, map);
		free(line);
	}
	free(line);
	if (map->size.x <= 0 || map->size.y <= 0)
		panic("Map null after reading.");
}
