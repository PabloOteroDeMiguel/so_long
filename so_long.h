/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:50:14 by potero-d          #+#    #+#             */
/*   Updated: 2022/02/09 16:10:20 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include<fcntl.h>
# include "gnl/get_next_line.h"
# include "structs.h"
# include "libft.h"
# include <mlx.h>

int		main(int argc, char **argv);
void	print_matrix(t_matrix **matrix, int x, int y);
void	print_border(t_matrix **matrix, int x, int y);
void	print_steps(t_game *game);
void	matrix_size(char *file, int *x, int *y);
void	matrix_size_y(char *file, int x, int *y);
void	create_matrix(char *file, int x, int y, t_matrix **matrix);
void	create_border(int x, int y, t_matrix **matrix);
void	read_matrix(t_game *game, int x, int y);
void 	border(t_matrix **matrix, int x, int y);
void	error_map(int e);

void	assets(t_mlx *mlx);
void	sprites_right(t_game *game);
void	sprites_left(t_game *game);
void	sprites_up(t_game *game);
void	sprites_down(t_game *game);

void	close_esc(t_mlx *mlx);
int		key_event(int key_code, t_game *game);
int		image(t_game *game, int x, int y);

int		movement(t_game *game, int x, int y);
void	key_a(t_game *game);
void	key_d(t_game *game);
void	key_s(t_game *game);
void	key_w(t_game *game);

#endif
