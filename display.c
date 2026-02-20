/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:56:27 by malavaud          #+#    #+#             */
/*   Updated: 2026/02/17 09:41:47 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_tile(t_game *game, char tile, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window,
		game->floor, x * SQUARE_SIZE, y * SQUARE_SIZE);
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->window,
			game->wall, x * SQUARE_SIZE, y * SQUARE_SIZE);
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx, game->window,
			game->player, x * SQUARE_SIZE, y * SQUARE_SIZE);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->window,
			game->collectible, x * SQUARE_SIZE, y * SQUARE_SIZE);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->window,
			game->exit, x * SQUARE_SIZE, y * SQUARE_SIZE);
}

void	display_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			draw_tile(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
}

int	load_textures(t_game *game)
{
	int	w;
	int	h;

	game->wall = mlx_xpm_file_to_image(
			game->mlx, "textures/wall.xpm", &w, &h);
	game->floor = mlx_xpm_file_to_image(
			game->mlx, "textures/floor.xpm", &w, &h);
	game->player = mlx_xpm_file_to_image(
			game->mlx, "textures/player.xpm", &w, &h);
	game->exit = mlx_xpm_file_to_image(
			game->mlx, "textures/exit.xpm", &w, &h);
	game->collectible = mlx_xpm_file_to_image(
			game->mlx, "textures/collectible.xpm", &w, &h);
	if (!game->wall || !game->floor
		|| !game->player || !game->exit
		|| !game->collectible)
		return (0);
	return (1);
}
