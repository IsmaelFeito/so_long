/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_so_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:23:59 by ifeito-m          #+#    #+#             */
/*   Updated: 2025/07/11 22:33:04 by ifeito-m         ###   ########.fr       */
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
	if (len == 4 || map_name[len - 5] != '.')
		return (ft_error("Invalid map name format"), 1);
	return (0);
}

void	init_game_data(t_game *game)
{
	ft_memset(game, 0, sizeof(t_game));
	game->map = NULL;
	game->count_coins = 0;
	game->is_colected = 0;
	game->steps = 0;
	game->total_coins = 0;
	game->height = 0;
	game->wide = 0;
}

void clean_game(t_game *game)
{
	if (!game)
		return;
	if (game->map)
		ft_double_freedom(&game->map, game->height);
}