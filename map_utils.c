/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xaviermonteiro <xaviermonteiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:29:29 by hguerrei          #+#    #+#             */
/*   Updated: 2025/01/17 13:03:35 by xaviermonte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_n(char *string)
{
	int	i;

	i = 0;
	if (!string)
		return (0);
	while (string[i] && string[i] != '\n')
		i++;
	return (i);
}

void	check_walls(t_data *vars)
{
	int	i;

	i = 0;
	while (i < vars->game.column)
	{
		if (vars->game.map[0][i] != '1' || vars->game.map[vars->game.rows
			- 1][i] != '1')
		{
			error_message(vars);
		}
		i++;
	}
	i = 0;
	while (i < vars->game.rows)
	{
		if (vars->game.map[i][0] != '1'
			|| vars->game.map[i][vars->game.column - 1] != '1')
		{
			error_message(vars);
		}
		i++;
	}
}

void	error_message(t_data *vars)
{
	free_game(vars);
	ft_putstr_fd("Error\n", 1);
	exit(EXIT_FAILURE);
}

void	check_rectangular(t_data *vars)
{
	int	i;

	i = 0;
	while (i < vars->game.rows)
	{
		if ((ft_strlen_no_newline(vars->game.map[i]) != vars->game.column))
		{
			error_message(vars);
		}
		i++;
	}
}

int	check_map_name(char *name, t_data *vars)
{
	int	i;

	i = 0;
	while (name[i] && name[i] != '.')
		i++;
	if (name[i] == '\0' || ft_strncmp(name + i, ".ber", 5) != 0)
	{
		error_message(vars);
	}
	return (1);
}
