/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:04:41 by malavaud          #+#    #+#             */
/*   Updated: 2026/02/13 09:32:05 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_line_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_walls(char **map)
{
	int	i;
	int	j;
	int	len;
	int	height;

	height = 0;
	while (map[height])
		height++;
	if (height < 3)
		return (0);
	len = 0;
	while (map[0][len])
		len++;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j != len || map[i][0] != '1' || map[i][len - 1] != '1'
			|| ((i == 0 || i == height - 1) && !is_line_wall(map[i])))
			return (0);
		i++;
	}
	return (1);
}

int	one_player(char **map)
{
	int	i;
	int	j;
	int	nbr_player;

	nbr_player = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				nbr_player++;
			j++;
		}
		i++;
	}
	return (nbr_player == 1);
}

int	one_exit(char **map)
{
	int	i;
	int	j;
	int	nbr_exit;

	nbr_exit = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				nbr_exit++;
			j++;
		}
		i++;
	}
	if (nbr_exit != 1)
		return (0);
	return (1);
}

int	count_collectibles(char **map)
{
	int	i;
	int	j;
	int	nbr_collectible;

	nbr_collectible = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				nbr_collectible++;
			j++;
		}
		i++;
	}
	return (nbr_collectible >= 1);
}
