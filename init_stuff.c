/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xaviermonteiro <xaviermonteiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:29:11 by hguerrei          #+#    #+#             */
/*   Updated: 2025/01/17 13:03:35 by xaviermonte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_variables(t_data *vars)
{
	vars->player.p_x = -1;
	vars->player.p_y = -1;
	vars->player.total_c = -1;
	vars->player.move_count = 0;
	vars->player.total_c = count_collectables(vars);
}

void	check_letters(t_data *vars)
{
	init_variables(vars);
	find_player(vars);
	check_conditions(vars);
	check_if_map_is_playable(vars);
}

void	flood_fill(t_flood_fill *fill, int x, int y)
{
	if (x < 0 || x >= fill->columns || y < 0 || y >= fill->rows
		|| fill->map_copy[y][x] == '1')
		return ;
	if (fill->map_copy[y][x] == 'F')
		return ;
	if (fill->map_copy[y][x] == 'E')
	{
		fill->found_exit = 1;
		return ;
	}
	if (fill->map_copy[y][x] == 'C')
		fill->collectables--;
	fill->map_copy[y][x] = 'F';
	flood_fill(fill, x - 1, y);
	flood_fill(fill, x + 1, y);
	flood_fill(fill, x, y - 1);
	flood_fill(fill, x, y + 1);
}
