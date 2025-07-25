/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 23:50:21 by ifeito-m          #+#    #+#             */
/*   Updated: 2025/07/25 01:34:10 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../includes/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

# define ESC 65307
# define UP_ARROW 65362
# define DOWN_ARROW 65364
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

typedef struct s_object
{
	void	*player;
	void	*coin;
	void	*wall;
	void	*exit;
	void	*floor;
}	t_object;

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
	int		wnd_height;
	int		wnd_wide;
	int		steps;
	int		is_colected;
	int		coins;
	t_object	*object;
}				t_game;


//loading map
int			load_map(t_game *game, const char *map_name);
int 		count_objs(char c, t_game *game);
void		save_location(t_game *game, char c, int y, int x);

//clean game and exiting game
void		clean_mlx_resources(t_game *game);
void		clean_game(t_game *game);
int			exit_game(t_game *game);

//validating stuff
int			validate_extension(const char *map_name);
int			validate_map(t_game *game);
int			floodfill_map(t_game *game);
int			check_map(t_game *game);

//render images
int			run_game(t_game *game);
int			hooks(int key, t_game *game);

#endif