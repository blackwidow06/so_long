/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:47:41 by malavaud          #+#    #+#             */
/*   Updated: 2026/01/28 16:42:00 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <unistd.h>
# include <fcntl.h>

# define MAX_LINE 1024
# define SQUARE_SIZE 64

typedef struct s_game
{
	void	*mlx;
	void	*window;

	void	*wall;
	void	*floor;
	void	*player;
	void	*exit;
	void	*collectible;

	char	**map;
	int		map_width;
	int		map_height;

	int		player_x;
	int		player_y;
	int		collectibles;
	int		moves;
}	t_game;

/* map_read.c */
char	**read_map(char *file);
int		count_lines(char *file);
void	remove_line(char *line);
int		valid_chars(char **map);

/* map_utils.c */
int		map_lines(char **map);
int		map_char(char **map);
void	free_map(char **map);
void	ft_putnbr_fd(int n, int fd);

/* check_map1.c */
int		file_exist(char *map);
int		is_rectangular(int fd);
int		map_not_empty(char *map);

/* check_map2.c */
int		check_walls(char **map);
int		one_player(char **map);
int		one_exit(char **map);
int		count_collectibles(char **map);

/* parse_map.c */
int		ft_strlen(char *str);
int		parse_map(char *path, t_game *game);

/* playable_map.c*/
char	**copy_map(char **map);
void	find_player_and_c(t_game *game);
void	flood_fill(char **map, int i, int j);
int		playable(char **map);
void	find_player(char **map, int *x, int *y);

/* display.c */
void	display_map(t_game *game);
void	draw_tile(t_game *game, char tile, int x, int y);
int		load_textures(t_game *game);

/* move.c */
void	move_player(t_game *game, int dx, int dy);

/* key_handler.c */
int		key_handler(int keycode, t_game *game);
int		exit_game(t_game *game);

/* init.c*/
void	init_game(t_game *game, char *map_path);

#endif