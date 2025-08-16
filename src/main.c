/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:25:48 by ifeito-m          #+#    #+#             */
/*   Updated: 2025/08/16 14:06:44 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_error("Usage: ./so_long map_file.ber"), 1);
	ft_memset(&game, 0, sizeof(t_game));
	if (load_map(&game, av[1]) != 0)
		return (clean_game(&game), 1);
	game.mlx_ptr = mlx_init();
	game.mlx_wnd = mlx_new_window(game.mlx_ptr, game.width * 32, game.height * 32, "so_long");
	if (!game.mlx_ptr || !game.mlx_wnd)
		return (clean_game(&game), ft_error("MLX initialization or window creation failed"), 1);
	if (run_game(&game) != 0)
		return (clean_game(&game), 1);
	mlx_key_hook(game.mlx_wnd, hooks, &game);
	mlx_loop(game.mlx_ptr);
	clean_game(&game);
	return (0);
}
