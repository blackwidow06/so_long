/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:47:41 by malavaud          #+#    #+#             */
/*   Updated: 2026/01/07 12:50:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "gnl/get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
//#include <mlx.h>

#define MAX_LINE 1024

// checkfiles
int		file_exist(char *map);
int		map_not_empty(char *map);
int		is_rectangular(int fd);

// parsingmap
int		check_walls(char **map);
int		one_exit(char **map);
int		one_player(char **map);
int		count_collectibles(char **map);

// readmap
int			count_lines(char *file);
void		remove_line(char *line);
char		**read_map(char *file);
int 		map_line(char **map);
int 		map_char(char **map);
int 		valid_chars(char **map);
void		free_map(char **map);

// mapverif
char 	**copy_map(char **map);
void	player_position(char **map, int *player_x, int *player_y);
void	flood_fill(char **map, int i, int j);

#endif
