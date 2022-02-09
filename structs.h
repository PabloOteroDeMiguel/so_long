/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:58:23 by potero-d          #+#    #+#             */
/*   Updated: 2022/02/09 16:51:33 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "so_long.h"

typedef struct s_matrix
{
	int		pos_x;
	int		pos_y;
	int		border;
	char	value;
}	t_matrix;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	void	*img_w;
	void	*img_s;
	void	*img_b;
	void	*img_h;
	void	*img_f;
}	t_mlx;

typedef struct s_sprite
{
	void	*l[8];
	void	*r[8];
	void	*u[8];
	void	*d[8];
}	t_sprite;

typedef struct s_bear
{
	int		x;
	int		y;
}	t_bear;

typedef struct s_game
{
	t_matrix	**matrix;
	t_mlx		mlx;
	t_bear		bear;
	t_sprite	sprite;
	int			collectibles;
	int			exit;
	int			player;
	int			frames;
	int			steps;
}	t_game;

#endif
