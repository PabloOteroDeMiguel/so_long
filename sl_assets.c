/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_assets.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:04:58 by potero-d          #+#    #+#             */
/*   Updated: 2022/02/10 11:33:24 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	assets(t_mlx *mlx)
{
	int	px;

	px = 120;
	mlx->img_w = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/tex_water.xpm", &px, &px);
	mlx->img_s = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/tex_snow.xpm", &px, &px);
	mlx->img_b = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/bear/b1.xpm", &px, &px);
	mlx->img_h = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/higlu.xpm", &px, &px);
	mlx->img_f = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/fish.xpm", &px, &px);
}

void	sprites_right(t_game *game)
{
	int	px;

	px = 120;
	game->sprite.r[0] = mlx_xpm_file_to_image(game->mlx.mlx,
			"./assets/bear/right/r1.xpm", &px, &px);
	game->sprite.r[1] = mlx_xpm_file_to_image(game->mlx.mlx,
			"./assets/bear/right/r2.xpm", &px, &px);
	game->sprite.r[2] = mlx_xpm_file_to_image(game->mlx.mlx,
			"./assets/bear/right/r3.xpm", &px, &px);
	game->sprite.r[3] = mlx_xpm_file_to_image(game->mlx.mlx,
			"./assets/bear/right/r4.xpm", &px, &px);
	game->sprite.r[4] = mlx_xpm_file_to_image(game->mlx.mlx,
			"./assets/bear/right/r5.xpm", &px, &px);
	game->sprite.r[5] = mlx_xpm_file_to_image(game->mlx.mlx,
			"./assets/bear/right/r6.xpm", &px, &px);
	game->sprite.r[6] = mlx_xpm_file_to_image(game->mlx.mlx,
			"./assets/bear/right/r7.xpm", &px, &px);
	game->sprite.r[7] = mlx_xpm_file_to_image(game->mlx.mlx,
			"./assets/bear/right/r8.xpm", &px, &px);
}

void	sprites_left(t_game *game)
{
	int	px;

	px = 120;
	game->sprite.l[0] = mlx_xpm_file_to_image(game->mlx.mlx,
			"./assets/bear/left/l1.xpm", &px, &px);
	game->sprite.l[1] = mlx_xpm_file_to_image(game->mlx.mlx,
			"./assets/bear/left/l2.xpm", &px, &px);
	game->sprite.l[2] = mlx_xpm_file_to_image(game->mlx.mlx,
			"./assets/bear/left/l3.xpm", &px, &px);
	game->sprite.l[3] = mlx_xpm_file_to_image(game->mlx.mlx,
			"./assets/bear/left/l4.xpm", &px, &px);
	game->sprite.l[4] = mlx_xpm_file_to_image(game->mlx.mlx,
			"./assets/bear/left/l5.xpm", &px, &px);
	game->sprite.l[5] = mlx_xpm_file_to_image(game->mlx.mlx,
			"./assets/bear/left/l6.xpm", &px, &px);
	game->sprite.l[6] = mlx_xpm_file_to_image(game->mlx.mlx,
			"./assets/bear/left/l7.xpm", &px, &px);
	game->sprite.l[7] = mlx_xpm_file_to_image(game->mlx.mlx,
			"./assets/bear/left/l8.xpm", &px, &px);
}

void	sprites_up(t_game *game)
{
	int	px;

	px = 120;
	game->sprite.u[0] = mlx_xpm_file_to_image(game->mlx.mlx,
			"./assets/bear/up/u1.xpm", &px, &px);
	game->sprite.u[1] = mlx_xpm_file_to_image(game->mlx.mlx,
			"./assets/bear/up/u2.xpm", &px, &px);
	game->sprite.u[2] = mlx_xpm_file_to_image(game->mlx.mlx,
			"./assets/bear/up/u3.xpm", &px, &px);
	game->sprite.u[3] = mlx_xpm_file_to_image(game->mlx.mlx,
			"./assets/bear/up/u4.xpm", &px, &px);
	game->sprite.u[4] = mlx_xpm_file_to_image(game->mlx.mlx,
			"./assets/bear/up/u5.xpm", &px, &px);
	game->sprite.u[5] = mlx_xpm_file_to_image(game->mlx.mlx,
			"./assets/bear/up/u6.xpm", &px, &px);
	game->sprite.u[6] = mlx_xpm_file_to_image(game->mlx.mlx,
			"./assets/bear/up/u7.xpm", &px, &px);
	game->sprite.u[7] = mlx_xpm_file_to_image(game->mlx.mlx,
			"./assets/bear/up/u8.xpm", &px, &px);
}

void	sprites_down(t_game *game)
{
	int	px;

	px = 120;
	game->sprite.d[0] = mlx_xpm_file_to_image(game->mlx.mlx,
			"./assets/bear/down/d1.xpm", &px, &px);
	game->sprite.d[1] = mlx_xpm_file_to_image(game->mlx.mlx,
			"./assets/bear/down/d2.xpm", &px, &px);
	game->sprite.d[2] = mlx_xpm_file_to_image(game->mlx.mlx,
			"./assets/bear/down/d3.xpm", &px, &px);
	game->sprite.d[3] = mlx_xpm_file_to_image(game->mlx.mlx,
			"./assets/bear/down/d4.xpm", &px, &px);
	game->sprite.d[4] = mlx_xpm_file_to_image(game->mlx.mlx,
			"./assets/bear/down/d5.xpm", &px, &px);
	game->sprite.d[5] = mlx_xpm_file_to_image(game->mlx.mlx,
			"./assets/bear/down/d6.xpm", &px, &px);
	game->sprite.d[6] = mlx_xpm_file_to_image(game->mlx.mlx,
			"./assets/bear/down/d7.xpm", &px, &px);
	game->sprite.d[7] = mlx_xpm_file_to_image(game->mlx.mlx,
			"./assets/bear/down/d8.xpm", &px, &px);
}
