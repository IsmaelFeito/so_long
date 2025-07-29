/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:23:59 by ifeito-m          #+#    #+#             */
/*   Updated: 2025/07/30 00:27:44 by ifeito-m         ###   ########.fr       */
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

void	flood_fill( t_game *game, int x, int y, int **visited)
{
    // Si la posición está fuera del mapa, retorna
    if (x < 0 || y < 0 || x >= game->width || y >= game->height)
        return;
    
    // Si ya fue visitado o es un muro ('1'), retorna
    if (visited[y][x] == '1' || game->map[y][x] == '1')
        return;
    
    // Marca como visitado (puedes usar una matriz auxiliar `visited`)
    visited[y][x] = '1';
    
    // Si encuentra una moneda ('C'), incrementa el contador
    if (game->map[y][x] == 'C')
        game->coins_reachable++;
    
    // Si encuentra la salida ('E'), marca como accesible
    if (game->map[y][x] == 'E')
        game->exit_reachable = 1;
    
    flood_fill(game, x + 1, y, visited); // Derecha
    flood_fill(game, x - 1, y, visited); // Izquierda
    flood_fill(game, x, y + 1, visited); // Abajo
    flood_fill(game, x, y - 1, visited); // Arriba
	
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
