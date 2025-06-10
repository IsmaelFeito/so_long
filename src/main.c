/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:25:48 by ifeito-m          #+#    #+#             */
/*   Updated: 2025/06/10 20:29:48 by ifeito-m         ###   ########.fr       */
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
	// printf("NOMBRE DEL MAPA: %s\n", map_name);
	return 1;
}
char *check_map(char *map_name, char *path_map)
{
	if (!ft_strchr(map_name, '/'))
	{
		char	*map;
		map = ft_strjoin((const char *)path_map, (const char *)map_name);
		printf("ruta mapa: %s\n", map);
		if (!map || check_extension(map) == 1)
		{
			free(map);
			return (ft_putstr_fd("Error on the map", 2), NULL);
		}
		return map;
	}
	else
	{
		printf("ruta mapa: %s\n", map_name);
		return map_name;
	}
}
int main(int ac, char **av)
{
	if (ac == 2)
	{
		int fd_map;
		char *map_name;
		if ((map_name =  check_map(av[1], "maps/")) != NULL)
		{
			if ((fd_map = open(map_name, O_RDONLY)) == -1)
			{
				return ft_putstr_fd("Error opening fd", 2), close(fd_map), 2;
			}
			else
				printf("fd opened");
			close(fd_map);
			return 0;
		}
	}
	return (ft_putstr_fd("Error on args", 2), 1);
}
