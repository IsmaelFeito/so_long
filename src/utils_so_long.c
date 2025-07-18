/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_so_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:23:59 by ifeito-m          #+#    #+#             */
/*   Updated: 2025/07/18 02:36:45 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	validate_extension(const char *map_name)
{
	size_t	len;

	if (!map_name)
		return (ft_error("Map name is NULL"), 1);
	len = ft_strlen(map_name);
	if (len < 5)
		return (ft_error("Map name too short"), 1);
	if (ft_strncmp(map_name + len - 4, ".ber", 4) != 0)
		return (ft_error("Map must have .ber extension"), 1);
	if (map_name[len - 5] == '.')
		return (ft_error("Invalid map name format"), 1);
	return (0);
}

void	clean_game(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
	{
		ft_double_freedom(&game->map, game->height);
		game->map = NULL;
	}
	game->height = 0;
	game->wide = 0;
}

int	validate_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (!game)
		return (1);
	if (game->map[y][x] != '1')
		return (0);
	return (0);
}

int	floodfill_map(t_game *game)
{
	game->total_coins = 0;
	return (0);
}

int	check_wide_n_asignation(char **map)
{
	size_t	temp;

	temp = ft_strlen(*map++);
	while (*map)
	{
		// printf("%li\n", temp);
		if (ft_strlen(*map) != temp)
			return (1);
		temp = ft_strlen(*map++);
	}
	// printf("%li\n", temp);
	
	return (0);
}
