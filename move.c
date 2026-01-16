/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:33:10 by malavaud          #+#    #+#             */
/*   Updated: 2026/01/16 10:51:18 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	move_player(t_game *game, int dx, int dy)
{
	int	nx;
	int	ny;

	nx = game->player_x + dx;
	ny = game->player_y + dy;

	if (game->map[ny][nx] == '1')
		return ;

	if (game->map[ny][nx] == 'C')
		game->collectibles--;

	if (game->map[ny][nx] == 'E')
	{
		if (game->collectibles == 0)
			exit(0);
		return ;
	}

	game->map[game->player_y][game->player_x] = '0';
	game->map[ny][nx] = 'P';

	game->player_x = nx;
	game->player_y = ny;
	game->moves++;

	printf("Moves: %d\n", game->moves);
	display_map(game);
}