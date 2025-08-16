/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:23:59 by ifeito-m          #+#    #+#             */
/*   Updated: 2025/08/16 14:25:12 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_matrix(t_game *game, int **visited)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

void flood_fill(t_game *game, int x, int y, int **visited)
{
    if (x < 0 || y < 0 || x >= game->width || y >= game->height)
        return;
    
    if (visited[y][x] || game->map[y][x] == '1')
        return;
    
    visited[y][x] = 1;

    if (game->map[y][x] == 'C')
    {
        game->coins++;
        ft_printf("Moneda encontrada en [%d][%d]. Total: %d\n", x, y, game->coins);
    }
    else if (game->map[y][x] == 'E')
    {
        game->exit_reachable++;
        ft_printf("Salida encontrada en [%d][%d].\n", x, y);
    }

    flood_fill(game, x + 1, y, visited);
    flood_fill(game, x - 1, y, visited);
    flood_fill(game, x, y + 1, visited);
    flood_fill(game, x, y - 1, visited);
}

void	locate_target(t_game *game, int *found_tar, int **visited, char target)
{
	int	i;
	int	j;
	int	is_accessible;

	i = 0;
	is_accessible = 1;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == target)
			{
				if (!visited[i][j])
					is_accessible = 0;
				else
					(*found_tar)++;
			}
			j++;
		}
		i++;
	}
	if (!is_accessible)
		*found_tar = 0;
	free_matrix(game, visited);
}

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
