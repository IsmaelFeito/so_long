/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:23:59 by ifeito-m          #+#    #+#             */
/*   Updated: 2025/07/25 04:02:53 by ifeito-m         ###   ########.fr       */
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

void	flood_fill(int x, int y, t_game *game, int **visited)
{
	printf("floodfill\nx: %i y: %i \ng_wide:%i n h_heith: %i, visited:%i, map: %c\n", x, y, game->wide, game->height, visited[x][y], game->map[x][y]);
	if (x < 0 || x >= game->height || y < 0 || y >= game->wide || \
		visited[x][y] || game->map[x][y] == '1')
		return ;
	visited[x][y] = 1;
	// printf("pr_mat\n");
	// ft_print_matrix((char **)visited, game->height);
	printf("visited:  %i\n", visited[x][y]);
	flood_fill(x + 1, y, game, visited);
	printf("visited:  %i\n", visited[x][y]);
	flood_fill(x - 1, y, game, visited);

	printf("visited:  %i\n", visited[x][y]);
	flood_fill(x, y - 1, game, visited);
	printf("visited:  %i\n", visited[x][y]);
	flood_fill(x, y + 1, game, visited);
	
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
		while (j < game->wide)
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
