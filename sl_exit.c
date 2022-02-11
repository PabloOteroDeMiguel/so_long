/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:51:25 by potero-d          #+#    #+#             */
/*   Updated: 2022/02/11 10:20:03 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_esc(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->window);
	mlx_destroy_window(mlx->mlx, mlx->window);
	exit(0);
	return (0);
}
