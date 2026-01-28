/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:57:09 by malavaud          #+#    #+#             */
/*   Updated: 2026/01/28 16:26:29 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

int	key_handler(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit_game(game);
	else if (keycode == 119)
		move_player(game, 0, -1);
	else if (keycode == 115)
		move_player(game, 0, 1);
	else if (keycode == 97)
		move_player(game, -1, 0);
	else if (keycode == 100)
		move_player(game, 1, 0);
	return (0);
}
