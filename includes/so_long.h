#ifndef SO_LONG_H
# define SO_LONG_H

# include "../includes/libft.h"

typedef struct s_map
{
    char    **map;
    int     total_coins;
    int     count_coins;
    int     steps;
    int    is_colected;
} s_map;

#endif