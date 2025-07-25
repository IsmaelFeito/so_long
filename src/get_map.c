/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 02:33:07 by ifeito-m          #+#    #+#             */
/*   Updated: 2025/07/25 03:00:19 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	*get_full_map_path(const char *map_name)//map exist's and opens
{
	char	*full_path;
	int		fd;

	if (!map_name || validate_extension(map_name))
		return (ft_error("1 Invalid map name or extension"), NULL);
	if (ft_strchr(map_name, '/'))
	{
		fd = open(map_name, O_RDONLY);
		if (fd == -1)
			return (ft_error("Error opening map file"), NULL);
		close(fd);
		full_path = ft_strdup(map_name);
		printf("dup: %s\n", full_path);
		if (!full_path)
			return (ft_error("Memory allocation failed"), NULL);
	}
	else {
		full_path = ft_strjoin("maps/", map_name);
		printf("join: %s", full_path);
		if (!full_path)
			return (ft_error("Memory allocation failed"), NULL);
		fd = open(full_path, O_RDONLY);
		if (fd == -1)
			return (free(full_path), ft_error("Error opening map file"), NULL);
		close (fd);
	}
	return (full_path);
}

int	check_map(t_game *game)
{
	size_t	temp;
	int		i;

	if (!game->map[0] || !game->map[0][0])
        return (ft_error("Empty map"), 1);
	i = 0;
	temp = ft_strlen(game->map[i]);
	while (game->map[i])
	{
		if (ft_strlen(game->map[i++]) != temp)
			return (ft_error("Map must be rectangular"), 1);
	}
	game->wide = ft_strlen(game->map[0]);
	
	return (0);
}

static int	save_map(t_game *game, char *map_path)
{
	int		fd;
	char	*line;
	int		line_count;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (free(map_path) ,ft_error("Couldn't open map file"), 1);
	line_count = ft_count_file_lines(map_path);
	if (line_count < 3)
		return (free(map_path), close(fd), ft_error("Map too small"), 1);
	game->map = (char **)malloc(sizeof(char *) * (line_count + 1));
	if (!game->map)
		return (free(map_path), close(fd), ft_error("Map's malloc failed"), 1);
	line = get_next_line(fd);
	while (line && game->height < line_count)
	{
		if (line[ft_strlen(line) - 1] == '\n')
            line[ft_strlen(line) - 1] = '\0';
		game->map[game->height++] = line;
		line = get_next_line(fd);
	}
	game->map[game->height] = NULL;
	close(fd);
	game->wide = ft_strlen(game->map[0]);
	ft_print_matrix(game->map, game->height);//quitar / debug
	return (free(map_path), 0);
}

int	load_map(t_game *game, const char *map_name)
{
	char	*full_path;

	full_path = NULL;
	if (!game || !map_name)
		return (ft_error("No map name"), 1);
	full_path = get_full_map_path(map_name);//check the map exist's and opens
	if (!full_path)
		return (ft_error("2 Invalid map path or extension"), 1);
	if (save_map(game, full_path) != 0)
		return (ft_error("Error charging map content"), 1);
	count_objects(game->map, game->wide, game->height, game);
	if (validate_map(game) != 0)
		return (clean_game(game), ft_error("Map vablidation failed"), 1);
	return (0);
}
