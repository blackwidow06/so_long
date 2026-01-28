/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 10:24:31 by malavaud          #+#    #+#             */
/*   Updated: 2026/01/28 16:31:19 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//void	init_game(t_game *game, char *map_path)
//{
//	game->mlx = mlx_init();
//	if (!game->mlx)
//		exit(1);

//	game->map = read_map(map_path);
//	if (!game->map)
//		exit(1);

//	game->map_height = map_lines(game->map);
//	game->map_width = map_char(game->map);

//	find_player_and_c(game);

//	if (!load_textures(game))
//		exit(1);

//	game->window = mlx_new_window(
//		game->mlx,
//		game->map_width * SQUARE_SIZE,
//		game->map_height * SQUARE_SIZE,
//		"so_long"
//	);
//	if (!game->window)
//	{
//		write(2, "Error: mlx_new_window failed\n", 30);
//		exit(1);
//	}

//	game->moves = 0;

//	display_map(game);

//	mlx_key_hook(game->window, key_handler, game);
//	mlx_hook(game->window, 17, 0, exit_game, game);
//}

void	init_game(t_game *game, char *map_path)
{
	if (!parse_map(map_path, game))
		exit(1);
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
