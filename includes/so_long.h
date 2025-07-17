/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 23:50:21 by ifeito-m          #+#    #+#             */
/*   Updated: 2025/07/17 03:37:00 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../includes/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

typedef struct s_game
{
	char	**map;
	void	*mlx_ptr;
	void	*mlx_wnd;
	int		e_pos_x;
	int		e_pos_y;
	int		p_pos_x;
	int		p_pos_y;
	int		total_coins;
	int		height;
	int		wide;
	int		count_coins;
	int		steps;
	int		is_colected;
}				t_game;

void		clean_game(t_game *game);
int			validate_extension(const char *map_name);
int			validate_map(t_game *game);
int			floodfill_map(t_game *game);
#endif
