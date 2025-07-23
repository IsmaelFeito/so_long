/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:23:59 by ifeito-m          #+#    #+#             */
/*   Updated: 2025/07/23 03:26:46 by ifeito-m         ###   ########.fr       */
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

void	save_location(t_game *game, char c, int y, int x)
{
	if (c == 'C')
		return ;
	else if (c == 'P')
	{
		game->p_pos_y = y;
		game->p_pos_x = x;
	}
	else if (c == 'E')
	{
		game->e_pos_y = y;
		game->e_pos_x = x;
	}
}

int	floodfill_map(t_game *game)
{
	game->total_coins = 0;
	return (0);
}
