/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:56:27 by malavaud          #+#    #+#             */
/*   Updated: 2026/01/16 10:56:49 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_square(t_game *game, char square, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, game->floor, x * SQUARE_SIZE, y * SQUARE_SIZE);
	if (square == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->wall, x * SQUARE_SIZE, y * SQUARE_SIZE);
}
//Parcourt la map et affiche par carre 
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
			draw_square(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
}
int	load_textures(t_game *game)
{
	int	w;
	int	h;

	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &w, &h);
	game->floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &w, &h);
	if (!game->wall || !game->floor)
		return (0);
	return (1);
}
