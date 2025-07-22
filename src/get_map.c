/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 02:33:07 by ifeito-m          #+#    #+#             */
/*   Updated: 2025/07/23 00:30:48 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	*get_full_map_path(const char *map_name)
{
	char	*full_path;
	int		fd;

	if (!map_name || validate_extension(map_name))
		return (ft_error("Invalid map name or extension"), NULL);
	if (ft_strchr(map_name, '/'))
	{
		fd = open(map_name, O_RDONLY);
		if (fd == -1)
			return (ft_error("Error opening map file"), NULL);
		close(fd);
		full_path = ft_strdup(map_name);
		if (!full_path)
			return (ft_error("Memory allocation failed"), NULL);
	}
	else {
		full_path = ft_strjoin("maps/", map_name);
		if (!full_path)
			return (ft_error("Memory allocation failed"), NULL);
		fd = open(full_path, O_RDONLY);
		if (fd == -1)
			return (free(full_path), ft_error("Error opening map file"), NULL);
		close (fd);
	}
	return (full_path);
}

int count_objs(char c, t_game *game)
{
    int count;
    int i;
    int j;

    count = 0;
    i = 0;
    while (i < game->height)
    {
        j = 0;
        while (j < game->wide)
        {
            if (game->map[i][j] == c)
            {
                if (c == 'P')
                {
                    game->p_pos_x = j;
                    game->p_pos_y = i;
                }
                else if (c == 'E')
                {
                    game->e_pos_x = j;
                    game->e_pos_y = i;
                }
                count++;
            }
            j++;
        }
        i++;
    }
    return (count);
}

int	check_wide_n_count_objs(t_game *game)
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

	if ((count_objs('P', game) != 1) || (count_objs('E', game) != 1))
		return (ft_error("The ammount of exits and players has to be 1"), 1);
	return (0);
}

static int	load_map_contents(t_game *game, char *map_path)
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
		game->map[game->height++] = line;
		line = get_next_line(fd);
	}
	game->map[game->height] = NULL;
	close(fd);
	ft_print_matrix(game->map, game->height);//quitar / debug
	if (check_wide_n_count_objs(game))
		return (free(map_path), clean_game(game), ft_error("map doesn't have squared sahpe"), 1);
	game->wide = ft_strlen(game->map[0]);
	printf("\n%i\n", game->wide);//quitar / debug
	return (free(map_path), 0);
}

int	load_map(t_game *game, const char *map_name)
{
	char	*full_path;
	int		ret;

	if (!game || !map_name)
		return (ft_error("Ivalid parameters"), 1);
	full_path = get_full_map_path(map_name);
	if (!full_path)
		return (ft_error("Invalid map path or extension"), 1);
	ret = load_map_contents(game, full_path);
	if (ret != 0)
		return (ft_error("Error charging map content"), 1);
	if (!validate_map(game))
		return (clean_game(game), ft_error("Map vablidation failed"), 1);
	return (0);
}
