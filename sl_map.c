/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:49:47 by potero-d          #+#    #+#             */
/*   Updated: 2022/02/10 16:49:26 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_aux(t_game *game, int pos_x, int pos_y)
{
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.window,
		game->mlx.img_s, (pos_y * 120), (pos_x * 120));
	if (game->matrix[pos_x][pos_y].value == 'P')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.window,
			game->mlx.img_b, (pos_y * 120), (pos_x * 120 + 25));
		game->bear.x = pos_x;
		game->bear.y = pos_y;
	}
	else if (game->matrix[pos_x][pos_y].value == 'E')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.window,
			game->mlx.img_h, (pos_y * 120), (pos_x * 120) + 25);
	else if (game->matrix[pos_x][pos_y].value == 'C')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.window,
			game->mlx.img_f, (pos_y * 120), (pos_x * 120) + 50);
}

void	image(t_game *game, int x, int y)
{
	int	pos_x;
	int	pos_y;

	pos_x = 0;
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
				image_aux(game, pos_x, pos_y);
			}
			pos_y++;
		}
		pos_x++;
	}
}
