/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:57:09 by malavaud          #+#    #+#             */
/*   Updated: 2026/02/20 12:24:36 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_game *game)
{
	if (game->map)
		free_map(game->map);
	if (game->mlx)
	{
		if (game->wall)
			mlx_destroy_image(game->mlx, game->wall);
		if (game->floor)
			mlx_destroy_image(game->mlx, game->floor);
		if (game->player)
			mlx_destroy_image(game->mlx, game->player);
		if (game->exit)
			mlx_destroy_image(game->mlx, game->exit);
		if (game->collectible)
			mlx_destroy_image(game->mlx, game->collectible);
		if (game->window)
			mlx_destroy_window(game->mlx, game->window);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
}

int	key_handler(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game);
	else if (keycode == KEY_W)
		move_player(game, 0, -1);
	else if (keycode == KEY_S)
		move_player(game, 0, 1);
	else if (keycode == KEY_A)
		move_player(game, -1, 0);
	else if (keycode == KEY_D)
		move_player(game, 1, 0);
	return (0);
}

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
			exit_game(game);
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
