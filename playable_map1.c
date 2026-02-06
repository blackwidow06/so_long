/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playable_map1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:05:34 by malavaud          #+#    #+#             */
/*   Updated: 2026/02/03 09:54:17 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(char **map)
{
	int		i;
	char	**copy;

	i = 0;
	while (map[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	find_player_and_c(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->collectibles = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
			}
			if (game->map[i][j] == 'C')
				game->collectibles++;
			j++;
		}
		i++;
	}
}

void	flood_fill(char **map, int i, int j)
{
	if (i < 0 || j < 0 || !map[i] || !map[i][j])
		return ;
	if (map[i][j] == '1' || map[i][j] == 'V')
		return ;
	map[i][j] = 'V';
	flood_fill(map, i + 1, j);
	flood_fill(map, i - 1, j);
	flood_fill(map, i, j + 1);
	flood_fill(map, i, j - 1);
}

void	find_player(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}
