/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 01:10:18 by ifeito-m          #+#    #+#             */
/*   Updated: 2025/07/25 01:34:10 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_textures(t_game *game)
{
	if (game->object->wall)
		mlx_destroy_image(game->mlx_ptr, game->object->wall);
	if (game->object->floor)
		mlx_destroy_image(game->mlx_ptr, game->object->floor);
	if (game->object->player)
		mlx_destroy_image(game->mlx_ptr, game->object->player);
	if (game->object->exit)
		mlx_destroy_image(game->mlx_ptr, game->object->exit);
	if (game->object->coin)
		mlx_destroy_image(game->mlx_ptr, game->object->coin);

	game->object->wall = NULL;
	game->object->floor = NULL;
	game->object->player = NULL;
	game->object->exit = NULL;
	game->object->coin = NULL;
}

void clean_mlx_resources(t_game *game)
{
    if (!game->mlx_ptr)
        return;
    free_textures(game);
    if (game->mlx_wnd)
    {
        mlx_clear_window(game->mlx_ptr, game->mlx_wnd);
        mlx_destroy_window(game->mlx_ptr, game->mlx_wnd);
		game->mlx_wnd = NULL;
    }
    if (game->mlx_ptr)
    {
        mlx_destroy_display(game->mlx_ptr);
        free(game->mlx_ptr);
		game->mlx_ptr = NULL;
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
	free(game->object);
	game->mlx_ptr = NULL;
	game->mlx_wnd = NULL;
	game->e_pos_x = 0;
	game->e_pos_y = 0;
	game->p_pos_x = 0;
	game->p_pos_y = 0;
	game->wnd_height = 0;
	game->wnd_wide = 0;
	game->height = 0;
	game->wide = 0;
	game->total_coins = 0;
	game->coins = 0;
	game->is_colected = 0;
	game->steps = 0;
}
