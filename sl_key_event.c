/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_key_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:45:25 by potero-d          #+#    #+#             */
/*   Updated: 2022/02/11 10:19:04 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_event(int key_code, t_game *game)
{
	if (game->frames == 8)
		game->frames = 0;
	if (key_code == 0)
		if (movement(game, 0, -1) == 0)
			key_a(game);
	if (key_code == 1)
		if (movement(game, 1, 0) == 0)
			key_s(game);
	if (key_code == 2)
		if (movement(game, 0, 1) == 0)
			key_d(game);
	if (key_code == 13)
		if (movement(game, -1, 0) == 0)
			key_w(game);
	if (key_code == 53)
		close_esc(&game->mlx);
	return (0);
}
