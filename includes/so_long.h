#ifndef SO_LONG_H
# define SO_LONG_H

# include "../includes/libft.h"

typedef struct t_game
{
    char    **map;
    int     total_coins;
    int     count_coins;
    int     steps;
    int    is_colected;
} s_game;

void	init_strc_map(char ***map, char **temp_map, int matrix_len);


#endif