
#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_error("Usage: ./so_long map_file.ber"), exit(EXIT_FAILURE), 1);
	ft_memset(&game, 0, sizeof(t_game));
	if (load_map(&game, av[1]) != 0)
		return (clean_game(&game), 1);
	game.mlx_ptr = mlx_init();
	game.mlx_wnd = mlx_new_window(game.mlx_ptr, game.wide * 32, game.height * 32, "so_long");
	if (!game.mlx_ptr || !game.mlx_wnd)
		return (clean_game(&game), ft_error("MLX initialization or window creation failed"), 1);
	if (run_game(&game) != 0)
		return (clean_game(&game), 1);
	mlx_loop(game.mlx_ptr);
	clean_game(&game);
	return (0);
}
