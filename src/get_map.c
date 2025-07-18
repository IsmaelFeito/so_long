/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 02:33:07 by ifeito-m          #+#    #+#             */
/*   Updated: 2025/07/18 02:35:18 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	*get_full_map_path(const char *map_name)
{
	char	*full_path;
	int		fd;

	if (!map_name || validate_extension(map_name))
		return (NULL);
	if (ft_strchr(map_name, '/'))
	{
		fd = open(map_name, O_RDONLY);
		if (fd == -1)
			return (ft_error("Error opening map file"), NULL);
		close(fd);
		return (ft_strdup(map_name));
	}
	full_path = ft_strjoin("maps/", map_name);
	if (!full_path)
		return (NULL);
	fd = open(full_path, O_RDONLY);
	if (fd == -1)
	{
		free(full_path);
		return (ft_error("Error opening map file"), NULL);
	}
	close(fd);
	return (full_path);
}

static int	load_map_contents(t_game *game, char *map_path)
{
	int		fd;
	char	*line;
	int		line_count;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (ft_error("Couldn't open map file"), 1);
	line_count = ft_count_file_lines(map_path);
	if (line_count < 3)
		return (free(map_path), close(fd), ft_error("Map too small"), 1);
	game->map = (char **)malloc(sizeof(char *) * (line_count + 1));
	if (!game->map)
		return (close(fd), ft_error("Map's malloc failed"), 1);
	line = get_next_line(fd);
	while (line && game->height < line_count)
	{
		game->map[game->height++] = line;
		line = get_next_line(fd);
	}
	game->map[game->height] = NULL;
	close(fd);
	if (check_wide_n_asignation(game->map))
		return (clean_game(game), free(map_path), ft_error("map doesn't have squared sahpe"), 1);
	game->wide = ft_strlen(game->map[0]) - 1;
	return (0);
}

int	load_map(t_game *game, const char *map_name)
{
	char	*full_path;
	int		ret;

	if (!game || !map_name)
		return (ft_error("Ivalid parameters"), 1);
	full_path = get_full_map_path(map_name);
	if (!full_path)
		return (clean_game(game), ft_error("Invalid map path or extension"), 1);
	ret = load_map_contents(game, full_path);
	if (ret != 0)
	{
		free(full_path);
		clean_game(game);
		return (ft_error("Error charging map content"), 1);
	}
	free(full_path);
	if (validate_map(game))
		return (clean_game(game), ft_error("Map vablidation failed"), 1);
	return (0);
}
