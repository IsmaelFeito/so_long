/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 01:22:36 by ifeito-m          #+#    #+#             */
/*   Updated: 2025/07/23 03:28:52 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_shape(t_game *game)
{
	int		y;
	char	*temp;
	
	temp = game->map[0];
	y = 1;
	while (game->map[y] !=  NULL)
	{
		if (ft_strlen(temp) != ft_strlen(game->map[y]))
			return (1);
		y++;
	}
	return (0);
}
int	check_walls(t_game *game)
{
    int x;
    int y;

    x = -1;
    while (++x < game->wide)
    {
        if (game->map[0][x] != '1' || game->map[game->height-1][x] != '1')
			return (1);
    }

    y = -1;
    while (++y < game->height)
    {
        if (game->map[y][0] != '1' || game->map[y][game->wide-1] != '1')
			return (1);
    }
	return (0);
}

int	check_components(t_game *game, char c)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	printf("%i  %i\n", game->height,game->wide);
	while (y < game->height)
	{
		x = 0;
		while (x < game->wide)
		{
			if (game->map[y][x] == c)
			{	
				save_location(game, c, y, x);
				count++;
			}
			x++;
		}
		y++;
	}
	printf("%c -> %i\n", c, count);
	return (count);
}

int	validate_map(t_game *game)
{
	if (check_shape(game) != 0)
		return (ft_error("Game's shape isn't rectangular"), 1);
	else if (check_walls(game) != 0)
		return (ft_error("Map must be surrounded by walls"), 1);
	else if ((check_components(game, 'P') != 1) || (check_components(game, 'E') != 1) ||
				(check_components(game, 'C') < 1))
		return (ft_error("Map must have at least 1 coin and exactly 1 player and 1 exit"), 1);
	// else
	// 	check_valid_path(t_game *game);
	return (0);
}
