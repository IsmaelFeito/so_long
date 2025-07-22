/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 02:02:18 by ifeito-m          #+#    #+#             */
/*   Updated: 2025/07/22 01:31:08 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_textures(t_game *game, void **object, char *path, char c)
{
	int	img_width;
	int	img_height;
	int	i;
	int	j;

	i = 0;
	*object = mlx_xpm_file_to_image(game->mlx_ptr, path, &img_width, &img_height);
	while (i < game->height / 32)
	{
		j = 0;
		while (j < game->wide / 32)
		{
			if (game->map[i][j] == c)
			{
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_wnd, object, (j * 32), (i * 32));
			}
			j++;
		}
		i++;
	}
}

int	run_game(t_game *game)
{
	// Asignar memoria para los objetos del juego
	game->object = malloc(sizeof(t_object));
	if (!game->object)
		return (ft_error("Game allocation failed"), 1);
	ft_memset(game->object, 0, sizeof(t_object));
	// Cargar texturas de 32x32 píxeles
	load_textures(game, &game->object->wall, "./textures/wall.xpm", '1');
	load_textures(game, &game->object->player, "./textures/player.xpm", 'P');
	load_textures(game, &game->object->floor, "./textures/floor.xpm", '0');
	load_textures(game, &game->object->coin, "./textures/coin.xpm", 'C');
	load_textures(game, &game->object->exit, "./textures/exit.xpm", 'E');
	mlx_hook(game->mlx_wnd, 17, 1L << 2, exit_game, game);
	mlx_key_hook(game->mlx_wnd, hooks, game);
	return (0);
}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->mlx_wnd);
	printf("You left the game :( %d\n", game->total_coins);
	// free_game(game);
	exit(EXIT_SUCCESS);
}
