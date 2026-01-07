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

// checkmap
int		check_walls(char **map);
int		one_exit(char **map);
int		one_player(char **map);
int		count_collectibles(char **map);