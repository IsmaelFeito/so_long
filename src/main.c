/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:25:48 by ifeito-m          #+#    #+#             */
/*   Updated: 2025/07/09 01:11:55 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_extension(char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (len >= 5)
	{
		if (ft_strncmp(map_name + len - 4, ".ber", 5) == 0)
		{
			printf("NOMBRE DEL MAPA: %s\n", map_name);
			return (ft_putstr_fd("buena extensión del map\n", 2), 0);
		}
	}
	ft_putstr_fd("mala extensión del map\n", 1);
	return (1);
}

char	*check_map_name(char *map_name, char *path_map)
{
	char	*map;

	if (!ft_strchr(map_name, '/'))
	{
		map = ft_strjoin((const char *)path_map, (const char *)map_name);
		printf("ruta mapa: %s\n", map);
		if (!map || check_extension(map) == 1)
		{
			if (map)
				free(map);
			return (ft_putstr_fd("Error on the map", 2), NULL);
		}
		return (map);
	}
	else
	{
		printf("ruta mapa: %s\n", map_name);
		if (check_extension(map_name) == 1 || ft_strncmp("maps/", map_name, 5) != 0)
			return (NULL);
		return (ft_strdup(map_name));
	}
}

void	init_map(t_game *game, char **temp_map, int matrix_len)
{
	game->count_coins = 0;
	game->is_colected = 0;
	game->steps = 0;
	game->total_coins = 0;
	init_strc_map(&(game->map), temp_map, matrix_len);
	if (temp_map)
		ft_double_freedom((void ***)&temp_map);// Cleanup temporary map
}

int	save_map(char **temp, char *map_name, int map_len)
{
	int		fd_map;
	char	*line;
	int		i;

	fd_map = open(map_name, O_RDONLY);
	if (fd_map == -1)
		return (perror("Error opening fd/doesn't exists"), EXIT_FAILURE);
	i = 0;
	line = get_next_line(fd_map);
	while (i < map_len && line != NULL)
	{
		temp[i++] = line;
		line = get_next_line(fd_map);
	}
	temp[i] = NULL;
	ft_putstr_fd("temp\n", 1);
	ft_print_matrix(temp);
	close(fd_map);
	return (0);
}

int	main(int ac, char **av)
{
	char	*map_name;
	char	**temp_map;
	// int		map_len;
	t_game	game;
	
	if (!(ac == 2))      
		return (ft_putstr_fd("Usage: ./so_long map_file.ber\n", 2), EXIT_FAILURE);
	map_name = check_map_name(av[1], "maps/");// Get and check map name
	if (!map_name)
		return (ft_putstr_fd("Error: Invalid map name\n", 2), EXIT_FAILURE);
	ft_memset(&game, 0, sizeof(game));// Initialize game structure
	temp_map = malloc(sizeof(char *) * ft_count_file_lines(map_name) + 1);
	if (!temp_map)
		return (free(map_name), ft_putstr_fd("Error: Memory allocation failed\n", 2), EXIT_FAILURE);
	if (ft_count_file_lines(map_name) >= 2 && save_map(temp_map, map_name, ft_count_file_lines(map_name) + 2) != 0)
	{
		free(map_name);
		if (temp_map) 
			return (ft_double_freedom((void ***)&temp_map), EXIT_FAILURE);
	}
	init_map(&game, temp_map, ft_count_file_lines(map_name));// Initialize game map
	free(map_name);
	/* Game loop would go here */
	printf("game.map:\n");ft_print_matrix(game.map);//coment
	if (game.map) 
		ft_double_freedom((void ***)&game.map);// Final cleanup 
    return (0);
}
