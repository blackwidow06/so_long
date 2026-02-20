/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:47:41 by malavaud          #+#    #+#             */
/*   Updated: 2026/02/20 12:24:17 by malavaud         ###   ########.fr       */
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

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100

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
int		valid_chars(char **map);

/* map_utils.c */
int		map_lines(char **map);
int		map_char(char **map);
void	free_map(char **map);

/* map_utils2.c*/
void	ft_putnbr_fd(int n, int fd);
int		ft_strlen(char *str);
void	ft_bzero(void *s, size_t n);

/* check_map1.c */
int		file_exist(char *map);
int		is_rectangular(int fd);

/* check_map2.c */
int		check_walls(char **map);
int		one_player(char **map);
int		one_exit(char **map);
int		count_collectibles(char **map);

/* parse_map.c */
int		parse_map(char *path, t_game *game);

/* playable_map1.c*/
char	**copy_map(char **map);
void	find_player_and_c(t_game *game);
void	flood_fill(char **map, int i, int j);
int		validate_map(char **map, int player_y, int player_x);
void	find_player(char **map, int *x, int *y);

/* playable_map2.c*/
int		playable(char **map);

/* display.c */
void	display_map(t_game *game);
int		load_textures(t_game *game);

/* key_handler.c */
int		key_handler(int keycode, t_game *game);
int		exit_game(t_game *game);
void	move_player(t_game *game, int dx, int dy);

/* init.c*/
void	init_game(t_game *game, char *map_path);

#endif