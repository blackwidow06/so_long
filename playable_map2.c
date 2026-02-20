/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playable_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 09:53:44 by malavaud          #+#    #+#             */
/*   Updated: 2026/02/13 09:50:21 by malavaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	playable_check(char **copy)
{
	int	i;
	int	j;

	i = 0;
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
		{
			if (copy[i][j] == 'C' || copy[i][j] == 'E')
			{
				free_map(copy);
				return (0);
			}
			j++;
		}
		i++;
	}
	free_map(copy);
	return (1);
}

int	playable(char **map)
{
	char	**copy;
	int		player_x;
	int		player_y;

	copy = copy_map(map);
	if (!copy)
		return (0);
	find_player(copy, &player_x, &player_y);
	flood_fill(copy, player_y, player_x);
	if (!playable_check(copy))
	{
		free_map(copy);
		return (0);
	}
	free_map(copy);
	return (1);
}
