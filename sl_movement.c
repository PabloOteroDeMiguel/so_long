/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:17:50 by potero-d          #+#    #+#             */
/*   Updated: 2022/02/11 11:44:09 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	movement(t_game *game, int x, int y)
{
	int	new_x;
	int	new_y;

	new_x = game->bear.x + x;
	new_y = game->bear.y + y;
	if (game->matrix[new_x][new_y].value == '1' ||
			(game->matrix[new_x][new_y].value == 'E'
				&& game->collectibles != 0))
	{
		printf("Impossible movement\n");
		return (1);
	}
	else
	{
		game->bear.x = new_x;
		game->bear.y = new_y;
		return (0);
	}
}

void	key_a(t_game *game)
{
	int	i;

	i = game->frames;
	if (game->matrix[game->bear.x][game->bear.y].value == 'C')
	{
		game->collectibles--;
		game->matrix[game->bear.x][game->bear.y].value = '0';
	}
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.window, game->mlx.img_s,
		(game->bear.y * 120), (game->bear.x * 120));
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.window, game->mlx.img_s,
		((game->bear.y + 1) * 120), ((game->bear.x) * 120));
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.window, game->sprite.l[i],
		(game->bear.y * 120), (game->bear.x * 120 + 25));
	game->frames += 1;
	game->steps += 1;
	print_steps(game);
	if (game->matrix[game->bear.x][game->bear.y].value == 'E')
		close_esc(&game->mlx);
}

void	key_d(t_game *game)
{
	int	i;

	i = game->frames;
	if (game->matrix[game->bear.x][game->bear.y].value == 'C')
	{
		game->collectibles--;
		game->matrix[game->bear.x][game->bear.y].value = '0';
	}
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.window, game->mlx.img_s,
		(game->bear.y * 120), (game->bear.x * 120));
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.window, game->mlx.img_s,
		((game->bear.y - 1) * 120), ((game->bear.x) * 120));
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.window, game->sprite.r[i],
		(game->bear.y * 120), (game->bear.x * 120 + 25));
	game->frames += 1;
	game->steps += 1;
	print_steps(game);
	if (game->matrix[game->bear.x][game->bear.y].value == 'E')
		close_esc(&game->mlx);
}

void	key_w(t_game *game)
{	
	int	i;

	i = game->frames;
	if (game->matrix[game->bear.x][game->bear.y].value == 'C')
	{
		game->collectibles--;
		game->matrix[game->bear.x][game->bear.y].value = '0';
	}
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.window, game->mlx.img_s,
		(game->bear.y * 120), (game->bear.x * 120));
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.window, game->mlx.img_s,
		(game->bear.y * 120), ((game->bear.x + 1) * 120));
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.window, game->sprite.u[i],
		(game->bear.y) * 120, (game->bear.x * 120 + 25));
	game->frames += 1;
	game->steps += 1;
	print_steps(game);
	if (game->matrix[game->bear.x][game->bear.y].value == 'E')
		close_esc(&game->mlx);
}

void	key_s(t_game *game)
{
	int	i;

	i = game->frames;
	if (game->matrix[game->bear.x][game->bear.y].value == 'C')
	{
		game->collectibles--;
		game->matrix[game->bear.x][game->bear.y].value = '0';
	}
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.window, game->mlx.img_s,
		(game->bear.y * 120), (game->bear.x * 120));
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.window, game->mlx.img_s,
		(game->bear.y * 120), ((game->bear.x - 1) * 120));
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.window, game->sprite.d[i],
		(game->bear.y * 120), (game->bear.x * 120 + 25));
	game->frames += 1;
	game->steps += 1;
	print_steps(game);
	if (game->matrix[game->bear.x][game->bear.y].value == 'E')
		close_esc(&game->mlx);
}
