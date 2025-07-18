/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:25:48 by ifeito-m          #+#    #+#             */
/*   Updated: 2025/07/18 02:34:37 by ifeito-m         ###   ########.fr       */
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
	{
		clean_game(&game);
		return (1);
	}
	floodfill_map(&game);
	game.mlx_ptr = mlx_init();
	game.mlx_wnd = mlx_new_window(game.mlx_ptr, game.wide * 32, game.height * 32, "so_long");
	run_game(&game);
	clean_game(&game);
	return (0);
}
