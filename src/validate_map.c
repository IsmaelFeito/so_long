/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 01:22:36 by ifeito-m          #+#    #+#             */
/*   Updated: 2025/07/25 03:06:07 by ifeito-m         ###   ########.fr       */
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
	int	**visited;
	int	i;
	int	j;
	int	found;

	i = 0;
	found = 0;
	visited = malloc(game->height * sizeof(int *));
	while (i < game->height)
	{
		visited[i] = malloc(game->wide * sizeof(int));
		j = 0;
		while (j < game->wide)
		{
			visited[i][j] = 0;
			j++;
		}
		i++;
	}
	flood_fill(game->p_pos_x, game->p_pos_y, game, visited);
	locate_target(game, &found, visited, c);
	return (found > 0);
}

int	validate_map(t_game *game)
{
	if (game->e_count != 1)
		return (ft_error("exit count"), 1);
	if (game->p_count != 1)
		return (ft_error("p count"), 1);
	if (game->coins == 0)
		return (ft_error("no coins"), 1);
	if (check_shape(game) != 0)
		return (ft_error("Game's shape isn't rectangular"), 1);
	if (check_walls(game) != 0)
		return (ft_error("Map must be surrounded by walls"), 1);
	if (!check_components(game, 'P') || !check_components(game, 'E'))
		return (ft_error("Exit is not accesible"), 1);
	if (!check_components(game, 'C'))
		return (ft_error("EVERY Coin should be accessible!"), 1);
	return (0);
}

void	count_objects(char **map, int width, int height, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->coins = 0;
	game->p_count = 0;
	game->e_count = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] == 'P')
				game->p_count++;
			if (map[i][j] == 'E')
				game->e_count++;
			if (map[i][j] == 'C')
				game->coins++;
			j++;
		}
		i++;
	}
}