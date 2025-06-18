/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:25:48 by ifeito-m          #+#    #+#             */
/*   Updated: 2025/06/18 12:58:08 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int check_extension(char *map_name)
{
	int len;

	if ((len = ft_strlen(map_name)) >= 5)
	{
		if (ft_strncmp(map_name + len - 4, ".ber", 5) == 0)
		{
			printf("NOMBRE DEL MAPA: %s\n", map_name);
			return ft_putstr_fd("buena extensión del  map\n", 2), 0;
		}
	}
	ft_putstr_fd("mala extensión del map\n", 2);
	return 1;
}

char *check_map_name(char *map_name, char *path_map)
{
	if (!ft_strchr(map_name, '/'))
	{
		char	*map;
		map = ft_strjoin((const char *)path_map, (const char *)map_name);
		printf("ruta mapa: %s\n", map);
		if (!map || check_extension(map) == 1)
		{
			if (map)
				free(map);
			return (ft_putstr_fd("Error on the map", 2), NULL);
		}
		return map;
	}
	else
	{
		printf("ruta mapa: %s\n", map_name);
		if (check_extension(map_name) == 1)
			return NULL;
		return ft_strdup(map_name);
	}
}

void init_map(s_game *game, char **temp_map, int matrix_len)
{
	game->count_coins = 0;
	game->is_colected = 0;
	game->steps = 0;
	game->total_coins = 0;
	init_strc_map(&(game->map), temp_map, matrix_len);
}
int save_map(char **temp, char *map_name, int map_len)
{
	int		fd_map;
	char	*line;
	int		i;
	
	if ((fd_map = open(map_name, O_RDONLY)) == -1)
	return ft_putstr_fd("Error opening fd/doesn't exists", 2), 1;
	
	i = 0;
    while (i < map_len - 1 && (line = get_next_line(fd_map)) != NULL)
	{
		temp[i++] = line;
		if (i >= ft_count_file_lines(map_name) + 1)
			break;
	}
	temp[i] = NULL;
	close(fd_map);
	return 0;
}
// int main(int ac, char **av)
// {
// 	if (ac == 2)
// 	{		
// 		char	*map_name;
// 		char	**temp_map;
// 		int		map_x_len;
// 		s_game	strc_game;
	
// 		if (!(map_name =  check_map_name(av[1], "maps/")))
// 			return (ft_putstr_fd("Error on map name", 2) ,1);
// 		if ((map_x_len = ft_count_file_lines(map_name) + 1) == 1)
// 			return(ft_putstr_fd("Empty map or mistake conunting lines \n", 2), 1);	
// 		if (!(temp_map = malloc(sizeof(char *) * (map_x_len))))
// 			return (ft_putstr_fd("Malloc error\n", 2) ,1);
// 		if (save_map(temp_map, map_name, map_x_len) != 0)
// 			return (ft_double_freedom(temp_map), 1);
// 		//valid_map;
// 		init_map(&strc_game, temp_map, map_x_len);
// 		ft_double_freedom(temp_map);
// 	}
// 	else 
// 		return (ft_putstr_fd("Error on args", 2), 1);
// 	return 0;
// }
int main(int ac, char **av)
{
    if (ac == 2)
    {        
        char *map_name = NULL;
        char **temp_map = NULL;
        int map_len;
        s_game game;
		
        ft_memset(&game, 0, sizeof(game));// Initialize game structure
        map_name = check_map_name(av[1], "maps/");// Get and check map name
        if (!map_name)
            return (ft_putstr_fd("Error: Invalid map name\n", 2), 1);
        map_len = ft_count_file_lines(map_name) + 1;// Allocate and read map
        if (map_len == 1)
        {
            free(map_name);
            return (ft_putstr_fd("Error: Empty map\n", 2), 1);
        }
        temp_map = malloc(sizeof(char *) * map_len);
        if (!temp_map)
        {
            free(map_name);
            return (ft_putstr_fd("Error: Memory allocation failed\n", 2), 1);
        }
        if (save_map(temp_map, map_name, map_len) != 0)
        {
            free(map_name);
            if (temp_map) ft_double_freedom(temp_map);
            return 1;
        }
        init_map(&game, temp_map, map_len);// Initialize game map
        if (temp_map) 
			ft_double_freedom(temp_map);// Cleanup temporary map
        free(map_name);
        /* Game loop would go here */
        if (game.map) ft_double_freedom(game.map);// Final cleanup
    }
    else 
    {
        ft_putstr_fd("Usage: ./so_long map_file.ber\n", 2);
        return 1;
    }
    return 0;
}
