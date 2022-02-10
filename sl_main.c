/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:33:40 by potero-d          #+#    #+#             */
/*   Updated: 2022/02/10 13:55:31 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	leaks(void)
{
	system("leaks so_long");
}

int	main(int argc, char **argv)
{
	int		x;
	int		y;
	t_game	game;

//	atexit(leaks);
	if (argc != 2)
	{
		printf("Error\nWrong number of arguments\n");
		exit(0);
	}
	file_name(argv[1]);
	x = 0;
	matrix_size(argv[1], &x, &y);
	game.matrix = malloc(sizeof(t_matrix *) * x + 1);
	game.matrix[x] = 0;
	if (!game.matrix)
		return (0);
	init(&game, x, y, argv[1]);
	image(&game, x, y);
}

void	init(t_game *game, int x, int y, char *argv)
{
	create_matrix(argv, x, y, game->matrix);
	create_border(x, y, game->matrix);
	border(game->matrix, x, y);
	read_map(game, x, y);
	read_matrix(game, x, y);
//	print_matrix(game->matrix, x, y);
//	print_border(game->matrix, x, y);
}
