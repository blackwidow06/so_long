/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:33:10 by malavaud          #+#    #+#             */
/*   Updated: 2026/01/26 16:26:18 by malavaud         ###   ########.fr       */
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
	write(1, "Moves: ", 7);
	ft_putnbr_fd(game->moves, 1);
	write(1, "\n", 1);
	mlx_clear_window(game->mlx, game->window);
	display_map(game);
}
