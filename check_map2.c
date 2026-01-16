/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:04:41 by malavaud          #+#    #+#             */
/*   Updated: 2026/01/16 11:05:08 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(char **map)
{
	int	i;
	int	j;
	int	lines;
	int	cols;

	lines = 0;
	while (map[lines] != NULL)
		lines++;
	if (lines < 3)
		return (0);
	cols = 0;
	while (map[0][cols] != '\0')
		cols++;
	j = 0;
	while (j < cols)
		if (map[0][j] != '1' || map[lines - 1][j++] != '1')
			return (0);
	i = 1;
	while (i < lines - 1)
	{
		if (map[i][0] != '1')
			return (0);
		j = 0;
		while (map[i][j])
			j++;
		if (map[i][j - 1] != '1')
			return (0);
		i++;
	}
	return (1);
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