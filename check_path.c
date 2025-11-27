/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:18:54 by fsitter           #+#    #+#             */
/*   Updated: 2025/11/27 11:29:24 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		check_path(t_mapdata *data, char *mapfile);
int		fill_mapdata(t_mapdata *data, char *mapfile);
int		fill_count(t_mapdata *data, char **cpy_map, int x, int y);
void	restore_exit(t_mapdata *map);

int	check_path(t_mapdata *data, char *mapfile)
{
	char	**map_copy;

	map_copy = make_map(mapfile, data);
	if (fill_count(data, map_copy, data->playerposition_x,
			data->playerposition_y) == FALSE)
	{
		map_copy = free_map(map_copy);
		ft_printf("Error:\nInvalid path!\n");
		return (FALSE);
	}
	map_copy = free_map(map_copy);
	return (TRUE);
}

int	fill_mapdata(t_mapdata *data, char *mapfile)
{
	data->map = make_map(mapfile, data);
	if (!data->map)
		return (FALSE);
	if (check_map_all(data) == FALSE)
		return (FALSE);
	if (count_all(data) == FALSE)
		return (FALSE);
	find_all(data);
	return (TRUE);
}

int	fill_count(t_mapdata *data, char **cpy_map, int x, int y)
{
	static int	coin;
	static int	exit;

	if ((y < 0) || (x < 0) || (y > data->map_height_y - 1)
		|| (x > data->map_width_x - 1) || (cpy_map[y][x] == '1')
		|| (cpy_map[y][x] == '9'))
		return (0);
	if (cpy_map[y][x] == COIN)
		coin++;
	if (cpy_map[y][x] == EXIT)
		exit++;
	cpy_map[y][x] = '9';
	fill_count(data, cpy_map, x, y - 1);
	fill_count(data, cpy_map, x, y + 1);
	fill_count(data, cpy_map, x + 1, y);
	fill_count(data, cpy_map, x - 1, y);
	return (data->coin_c == coin && data->exit_c == exit);
}

void	restore_exit(t_mapdata *map)
{
	if (map->map[map->exitposition_x][map->exitposition_y] != PLAYER)
		map->map[map->exitposition_x][map->exitposition_y] = EXIT;
}
