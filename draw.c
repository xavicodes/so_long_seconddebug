/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xaviermonteiro <xaviermonteiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:29:01 by hguerrei          #+#    #+#             */
/*   Updated: 2025/01/17 13:04:08 by xaviermonte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_img(t_data *vars, void *img, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, img, x * SIZE_PIXEL, y
		* SIZE_PIXEL);
}

void	draw_sprite(t_data *vars, int x, int y)
{
	if (vars->game.map[y][x] == '1')
		draw_img(vars, vars->sprites.walls, x, y);
	else if (vars->game.map[y][x] == '0')
		draw_img(vars, vars->sprites.floor, x, y);
	else if (vars->game.map[y][x] == 'P')
		draw_img(vars, vars->sprites.player, x, y);
	else if (vars->game.map[y][x] == 'C')
		draw_img(vars, vars->sprites.collectables, x, y);
	else if (vars->game.map[y][x] == 'E')
		draw_exit(vars, x, y);
}

void	draw_exit(t_data *vars, int x, int y)
{
	if (vars->player.total_c == 0)
		draw_img(vars, vars->sprites.floor, x, y);
	else
		draw_img(vars, vars->sprites.escape, x, y);
}

void	draw_map(t_data *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->game.rows)
	{
		x = 0;
		while (x < vars->game.column)
		{
			draw_tile(vars, x, y);
			x++;
		}
		y++;
	}
}
