/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 02:02:18 by ifeito-m          #+#    #+#             */
/*   Updated: 2025/07/18 02:21:08 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	run_game(t_game *game)
{
	// Asignar memoria para los objetos del juego
	game->object = malloc(sizeof(t_object));
	if (!game->object)
	{
		clean_game(game);
		ft_error("Game allocation failed");
	}
	// Cargar texturas de 32x32 píxeles
	load_texture(game, &game->object->wall, "./textures/wall.xpm", '1');
	load_texture(game, &game->object->player, "./textures/dolphin.xpm", 'P');
	load_texture(game, &game->object->floor, "./textures/water.xpm", '0');
	load_texture(game, &game->object->coin, "./textures/fish.xpm", 'C');
	load_texture(game, &game->object->exit, "./textures/exit.xpm", 'E');
	mlx_hook(game->mlx_wnd, 17, 1L << 2, exit_game, game);
	mlx_key_hook(game->mlx_wnd, hooks, game);
}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->mlx_wnd);
	ft_printf("You left the game :( %d\n", game->total_coins);
	free_game(game);
	exit(EXIT_SUCCESS);
}
