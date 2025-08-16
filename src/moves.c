/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 02:06:50 by ifeito-m          #+#    #+#             */
/*   Updated: 2025/08/16 14:33:19 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	finish_game(t_game *game, int move_did)
{
	if (game->map[game->p_pos_y][game->p_pos_x] == 'E' && game->is_colected)
	{
		mlx_destroy_window(game->mlx_ptr, game->mlx_wnd);
		ft_printf("Congratulatioins!!! You've won the game!!\n");
		clean_game(game);
		exit(EXIT_SUCCESS);
	}
	if (game->map[game->p_pos_y][game->p_pos_x] == 'C')
	{
		game->map[game->p_pos_y][game->p_pos_x] = '0';
		printf("%i\n",game->total_coins--);
		if (game->total_coins == 0){
			game->is_colected = 1;
			finish_game(game, move_did);
		}
	}
	if (move_did)
		printf("You've given %d steps!!\n", ++game->steps);
}

void	do_move(t_game *game, char pos, int dir)
{
	int	move_did;

	move_did = 0;
	if (game->coins == 0)
		game->is_colected = 1;
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_wnd, game->object->floor, game->p_pos_x * 32, game->p_pos_y * 32);
	if (pos == 'y' && game->map[game->p_pos_y + 1 * dir][game->p_pos_x] != '1' \
	&& (game->is_colected || game->map[game->p_pos_y + 1 * dir][game->p_pos_x] != 'E'))
	{
		game->p_pos_y = game->p_pos_y + 1 * dir;
		move_did = 1;
	}
	if (pos == 'x' && game->map[game->p_pos_y][game->p_pos_x + 1 * dir] != '1' \
	&& (game->is_colected || game->map[game->p_pos_y][game->p_pos_x + 1 * dir] != 'E'))
	{
		game->p_pos_x = game->p_pos_x + 1 * dir;
		move_did = 1;
	}
	finish_game(game, move_did);
	mlx_put_image_to_window(game->mlx_ptr , game->mlx_wnd, game->object->player, game->p_pos_x * 32, game->p_pos_y * 32);
}

int	hooks(int key, t_game *game)
{
	printf("hook\n");
	if (key == ESC)
		exit_game(game);
	if (key == UP_ARROW || key == W_KEY)
		do_move(game, 'y', -1);
	if (key == DOWN_ARROW || key == S_KEY)
		do_move(game, 'y', 1);
	if (key == LEFT_ARROW || key == A_KEY)
		do_move(game, 'x', -1);
	if (key == RIGHT_ARROW || key == D_KEY)
		do_move(game, 'x', 1);
	return (0);
}
