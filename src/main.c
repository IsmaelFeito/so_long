/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:25:48 by ifeito-m          #+#    #+#             */
/*   Updated: 2025/07/11 22:26:53 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int validate_map(t_game *game)
{
	if (!game)
		return (1);
	return (0);
}

static char	*get_full_map_path(const char *map_name)
{
	char	*full_path;

	if (!map_name)
		return (NULL);
	if (ft_strchr(map_name, '/'))
	{
		if (validate_extension(map_name) == 1)
			return (NULL);
		return (ft_strdup(map_name));
	}

	full_path = ft_strjoin("maps/", map_name);
	if (!full_path)
		return (NULL);
	if (validate_extension(full_path))
	{
		free(full_path);
		return (NULL);
	}
	return (full_path);
}
static int load_map_contents(t_game *game, const char *map_path)
{
	int		fd;
	char	*line;
	int		line_count;

	line_count = ft_count_file_lines(map_path);
	if (line_count < 3)
		return (ft_error("Map too small"), 1);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (ft_error("Couldn't open map file"), 1);
	game->map = (char **)malloc(sizeof(char *) * (line_count + 1));
	if (!game->map)
		return (ft_error("Map's malloc failed"), 1);
	line = get_next_line(fd);
	while (line && game->height < line_count)
	{
		game->map[game->height++] = line;
		line = get_next_line(fd);
	}
	game->map[game->height] = NULL;
	close(fd);
	ft_print_matrix(game->map, game->height);//
	return (0);
}

int	load_map(t_game *game, const char *map_name)
{
	char	*full_path;

	if(!game || !map_name)
		return (ft_error("Ivalid parameters"), 1);

	full_path = get_full_map_path(map_name);
	if (!full_path)
		return (ft_error("Invalid map path or extension"), 1);
	if (load_map_contents(game, full_path) != 0)
		{
			free(full_path);
			return (ft_error("Error charging map content"), 1);
		}
	free(full_path);
	return (validate_map(game));
}

int	main (int ac, char **av)
{
	t_game game;

	if (ac != 2)
		return(ft_error("Usage: ./so_long map_file.ber"), EXIT_FAILURE);

	init_game_data(&game);

	if (load_map(&game, av[1]) != 0 )
	{
		clean_game(&game);
		return (1);
	}
	//game loop function
	clean_game(&game);
	return (0);
}