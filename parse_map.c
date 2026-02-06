/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 14:04:07 by malavaud          #+#    #+#             */
/*   Updated: 2026/02/02 15:36:06 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(char *error)
{
	write(2, "Error\n", 6);
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
	return (0);
}

int	parse_map(char *path, t_game *game)
{
	int	fd;

	if (!file_exist(path))
		return (ft_error("File does not exist"));
	fd = open(path, O_RDONLY);
	if (!is_rectangular(fd))
		return (ft_error("Map is not rectangular"));
	close(fd);
	game->map = read_map(path);
	if (!game->map || !game->map[0])
		return (ft_error("Map is empty"));
	if (!check_walls(game->map))
		return (ft_error("Map not closed by walls"));
	if (!one_player(game->map))
		return (ft_error("Wrong number of players"));
	if (!one_exit(game->map))
		return (ft_error("Wrong numbers of exits"));
	if (!count_collectibles(game->map))
		return (ft_error("No collectibles"));
	game->map_height = map_lines(game->map);
	game->map_width = ft_strlen(game->map[0]);
	return (1);
}
