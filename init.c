/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 10:24:31 by malavaud          #+#    #+#             */
/*   Updated: 2026/02/06 10:27:52 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game, char *map_path)
{
	if (!parse_map(map_path, game))
		exit_game(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		exit(1);
	game->window = mlx_new_window(
			game->mlx,
			game->map_width * SQUARE_SIZE,
			game->map_height * SQUARE_SIZE,
			"so_long"
			);
	if (!game->window)
		exit(1);
	if (!load_textures(game))
		exit(1);
	game->moves = 0;
	find_player_and_c(game);
	display_map(game);
	mlx_hook(game->window, 2, 1L << 0, key_handler, game);
	mlx_hook(game->window, 17, 0, exit_game, game);
}
