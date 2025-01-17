/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_letters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xaviermonteiro <xaviermonteiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:29:20 by hguerrei          #+#    #+#             */
/*   Updated: 2025/01/17 13:03:35 by xaviermonte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_map_elements(t_data *vars, int *c_count, int *p_count,
		int *exit_count)
{
	int	i;
	int	j;

	*c_count = 0;
	*p_count = 0;
	*exit_count = 0;
	i = 0;
	while (i < vars->game.rows)
	{
		j = 0;
		while (j < vars->game.column)
		{
			if (vars->game.map[i][j] == 'C')
				(*c_count)++;
			else if (vars->game.map[i][j] == 'P')
				(*p_count)++;
			else if (vars->game.map[i][j] == 'E')
				(*exit_count)++;
			else if (vars->game.map[i][j] != '0'
				&& vars->game.map[i][j] != '1')
				free_error(vars);
			j++;
		}
		i++;
	}
}

void	check_conditions(t_data *vars)
{
	int	c_count;
	int	p_count;
	int	exit_count;

	count_map_elements(vars, &c_count, &p_count, &exit_count);
	if (c_count <= 0 || p_count != 1 || exit_count != 1)
		error_message(vars);
}

void	find_player(t_data *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->game.rows)
	{
		j = 0;
		while (j < vars->game.column)
		{
			if (vars->game.map[i][j] == 'P')
			{
				vars->player.p_x = j;
				vars->player.p_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
	error_message(vars);
}

int	count_collectibles(t_data *vars)
{
	int	collectibles;
	int	i;
	int	j;

	collectibles = 0;
	i = 0;
	while (i < vars->game.rows)
	{
		j = 0;
		while (j < vars->game.column)
		{
			if (vars->game.map[i][j] == 'C')
				collectibles++;
			j++;
		}
		i++;
	}
	return (collectibles);
}

void	check_if_map_is_playable(t_data *vars)
{
	t_flood_fill	fill;
	char			**map_copy;

	map_copy = copy_map(vars);
	if (!map_copy)
		error_message(vars);
	fill.map_copy = map_copy;
	fill.rows = vars->game.rows;
	fill.columns = vars->game.column;
	fill.found_exit = 0;
	fill.collectables = count_collectibles(vars);
	if (vars->player.p_x == -1 || vars->player.p_y == -1)
	{
		free_map(map_copy, vars->game.rows);
		error_message(vars);
	}
	flood_fill(&fill, vars->player.p_x, vars->player.p_y);
	if (fill.collectables != 0 || fill.found_exit == 0)
	{
		free_map(map_copy, vars->game.rows);
		error_message(vars);
	}
	free_map(map_copy, vars->game.rows);
}
