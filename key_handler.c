/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:57:09 by malavaud          #+#    #+#             */
/*   Updated: 2026/01/16 10:10:56 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int 	exit_game(t_game *game)
{
	mlx_destroy_window(game->window, game->mlx);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);	
}
int 	key_handler(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit_game(game);	
	if (keycode == 41)
		exit_game(game);
	//if (keycode == 'W')
	//	move_up(game);
	//if (keycode == 'A')
	//	move_left(game);
	//if (keycode == 'S')
	//	move_down(game);
	//if (key_handler == 'D')
	//	move_right(game);
	return (0);
}
