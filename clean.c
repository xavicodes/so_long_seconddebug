/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xaviermonteiro <xaviermonteiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:28:47 by hguerrei          #+#    #+#             */
/*   Updated: 2025/01/17 13:04:08 by xaviermonte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_error(t_data *vars)
{
	error_message(vars);
}

void	free_game(t_data *vars)
{
	if (vars->game.map)
	{
		free_map(vars->game.map, vars->game.rows);
		vars->game.map = NULL;
	}
}

void	destroy_sprites(t_data *vars)
{
	mlx_destroy_image(vars->mlx, vars->sprites.collectables);
	mlx_destroy_image(vars->mlx, vars->sprites.floor);
	mlx_destroy_image(vars->mlx, vars->sprites.walls);
	mlx_destroy_image(vars->mlx, vars->sprites.player);
	mlx_destroy_image(vars->mlx, vars->sprites.escape);
	mlx_destroy_image(vars->mlx, vars->sprites.escape_open);
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	mlx_destroy_display(vars->mlx);
	mlx_loop_end(vars->mlx);
	free_game(vars);
}

int	close_window(t_data *vars)
{
	mlx_loop_end(vars->mlx);
	return (0);
}
