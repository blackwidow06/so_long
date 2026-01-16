/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:10:45 by malavaud          #+#    #+#             */
/*   Updated: 2026/01/16 13:16:15 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//int main(void)
//{
//    void *mlx = mlx_init();
//    void *win = mlx_new_window(mlx, 640, 480, "test fenetre");
//	mlx_hook(win, 2, 1L << 0, key_handler, NULL);
//	mlx_hook(win, 17, 0, exit_game, NULL);
//	(void)win;
//    mlx_loop(mlx);
//}

//int main(void)
//{
//    void *mlx;
//    void *win;

//    mlx = mlx_init();
//    win = mlx_new_window(mlx, 640, 480, "test");

//    mlx_pixel_put(mlx, win, 100, 100, 0x00FF00); // pixel vert
//    mlx_pixel_put(mlx, win, 320, 240, 0xFF0000); // pixel rouge

//    mlx_key_hook(win, key_handler, NULL);
//    mlx_hook(win, 17, 0, exit_game, NULL);

//    mlx_loop(mlx);
//}

int	main(void)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		size;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 640, 480, "so_long");

	size = 50;
	y = 100;
	while (y < 100 + size)
	{
		x = 100;
		while (x < 100 + size)
		{
			mlx_pixel_put(mlx, win, x, y, 0xFFC0CB);
			x++;
		}
		y++;
	}
	mlx_key_hook(win, key_handler, NULL);
    mlx_hook(win, 17, 0, exit_game, NULL);
	mlx_loop(mlx);
	return (0);
}
