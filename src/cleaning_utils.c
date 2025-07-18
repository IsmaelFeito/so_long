/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 01:10:18 by ifeito-m          #+#    #+#             */
/*   Updated: 2025/07/18 01:34:39 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	clean_mlx_resources(t_game *game)
{
	if (game->mlx_wnd)
	{
		mlx_clear_window(game->mlx_ptr, game->mlx_wnd);
		mlx_destroy_window(game->mlx_ptr, game->mlx_wnd);
		game->mlx_wnd = NULL;
	}
	// Aquí deberías liberar también cualquier imagen/textura que hayas cargado
	// Ejemplo:
	// if (game->player_img)
	//     mlx_destroy_image(game->mlx_ptr, game->player_img);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		freedom(game->mlx_ptr);
	}
}

void	clean_game(t_game *game)
{
	if (!game)
		return ;
	clean_mlx_resources(game);
	if (game->map)
	{
		ft_double_freedom(&game->map, game->height);
		game->map = NULL;
	}
	game->mlx_ptr = NULL;
	game->mlx_wnd = NULL;
	game->e_pos_x = 0;
	game->e_pos_y = 0;
	game->p_pos_x = 0;
	game->p_pos_y = 0;
	game->total_coins = 0;
	game->height = 0;
	game->wide = 0;
	game->steps = 0;
	game->is_colected = 0;
}
