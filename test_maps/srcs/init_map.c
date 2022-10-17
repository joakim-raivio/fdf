/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 22:00:36 by jraivio           #+#    #+#             */
/*   Updated: 2022/10/17 13:06:19 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

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
	if (line_size != map->size.x || line_size == 0 || line_size > MAX_MAP_X)
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

/*
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
}*/

void    init_map(char *file, t_map *map)
{
    int        fd;
    char    *line;
    int        result;

    ft_bzero(map, sizeof(t_map));
    map->size.x = -1;
    fd = open(file, O_RDONLY);
    if (!fd || fd < 0)
        panic("Error opening file");
    result = get_next_line(fd, &line);
    while (result > 0)
    {
        if (map->size.y++ >= MAX_MAP_Y)
            panic("Map input Y too large.");
        parse_map_line(line, map);
        free(line);
        result = get_next_line(fd, &line);
    }
    free(line);
    if (result < 0)
        panic("get_next_line NULL.\n");
    if (map->size.x <= 0 || map->size.y <= 0)
        panic("Map null after reading.");
    close(fd);
}
