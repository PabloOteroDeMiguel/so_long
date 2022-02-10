/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:49:47 by potero-d          #+#    #+#             */
/*   Updated: 2022/02/10 11:35:01 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
void	leaks(void)
{
	system("leaks so_long");
}

int	main(int argc, char **argv)
{
	int			x;
	int			y;
	t_game		game;

	atexit(leaks);
	if (argc > 2)
	{
		printf("Error.\nDemasiados argumentos\n");
		exit(0);
	}
	x = 0;
	matrix_size(argv[1], &x, &y);
	game.matrix = malloc(sizeof(t_matrix *) * x);
	if (!game.matrix)
		return (0);
	create_matrix(argv[1], x, y, game.matrix);
	create_border(x, y, game.matrix);
	border(game.matrix, x, y);
	read_matrix(&game, x, y);
	print_matrix(game.matrix, x, y);
	print_border(game.matrix, x, y);
	image(&game, x, y);
}*/

int	byebye(void)
{
	exit(0);
	return (1);
}

int	image(t_game *game, int x, int y)
{
	int	pos_x;
	int	pos_y;

	game->mlx.mlx = mlx_init();
	game->mlx.window = mlx_new_window(game->mlx.mlx, (y * 120), (x * 120), "So Long");
	assets(&game->mlx);
	sprites_right(game);
	sprites_left(game);
	sprites_up(game);
	sprites_down(game);
	game->steps = 0;
	pos_x = 0;
	game->frames = 0;
	while (pos_x < x)
	{
		pos_y = 0;
		while (pos_y < y)
		{
			if (game->matrix[pos_x][pos_y].value == '1')
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.window,
						game->mlx.img_w, (pos_y * 120), (pos_x * 120));
			else if (game->matrix[pos_x][pos_y].value != '1')
			{
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.window,
						game->mlx.img_s, (pos_y * 120), (pos_x * 120));
				if (game->matrix[pos_x][pos_y].value == 'P')
				{
					mlx_put_image_to_window(game->mlx.mlx, game->mlx.window,
							game->mlx.img_b, (pos_y * 120), (pos_x * 120 + 25));
					game->bear.x = pos_x;
					game->bear.y = pos_y;
					printf("The player it's in the position (%d, %d)\n", game->bear.x, game->bear.y);
				}
				else if (game->matrix[pos_x][pos_y].value == 'E')
					mlx_put_image_to_window(game->mlx.mlx, game->mlx.window,
							game->mlx.img_h, (pos_y * 120) , (pos_x * 120) + 25);
				else if (game->matrix[pos_x][pos_y].value == 'C')
					mlx_put_image_to_window(game->mlx.mlx, game->mlx.window,
							game->mlx.img_f, (pos_y * 120) , (pos_x * 120) + 50);
			}
			pos_y++;
		}
		pos_x++;
	}
	print_steps(game);
	mlx_key_hook(game->mlx.window, key_event, game);
	mlx_hook(game->mlx.window, 17, (1L << 17), byebye, &game->mlx);
	mlx_loop(game->mlx.mlx);
	return (0);
}
