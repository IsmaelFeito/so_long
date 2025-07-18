/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 02:06:50 by ifeito-m          #+#    #+#             */
/*   Updated: 2025/07/18 02:08:33 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void	do_move(t_game *game, char pos, int dir)
{
	
}

int	hooks(int key, t_game *game)
{
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
