/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 23:50:21 by ifeito-m          #+#    #+#             */
/*   Updated: 2025/07/16 02:30:56 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../includes/libft.h"

typedef struct s_game
{
	char	**map;
	int		height;
	int		wide;
	int		count_coins;
	int		steps;
	int		is_colected;
	int		total_coins;
}				t_game;

void		clean_game(t_game *game);
void		init_game_data(t_game *game);
int			validate_extension(const char *map_name);
int			validate_map(t_game *game);
#endif