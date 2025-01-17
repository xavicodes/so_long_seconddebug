/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xaviermonteiro <xaviermonteiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:37:16 by hguerrei          #+#    #+#             */
/*   Updated: 2025/01/17 13:03:35 by xaviermonte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	build_map(char *file, t_data *vars)
{
	int		fd;
	int		i;
	char	*line;

	vars->game.map = malloc((vars->game.rows) * sizeof(char *));
	if (!vars->game.map)
		error_message(vars);
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		vars->game.map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	check_walls(vars);
	check_rectangular(vars);
	check_letters(vars);
	vars->game.map_width = vars->game.column * SIZE_PIXEL;
	vars->game.map_height = vars->game.rows * SIZE_PIXEL;
	return (1);
}

int	read_map(char *file, t_data *vars)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		error_message(vars);
	vars->game.column = 0;
	while (line[vars->game.column] != '\0' && line[vars->game.column] != '\n')
		vars->game.column++;
	vars->game.rows = 0;
	while (line)
	{
		vars->game.rows++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	build_map(file, vars);
	return (0);
}

char	**copy_map(t_data *vars)
{
	int		i;
	char	**copy;

	copy = malloc(sizeof(char *) * (vars->game.rows + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < vars->game.rows)
	{
		copy[i] = ft_strdup(vars->game.map[i]);
		if (!copy[i])
		{
			while (i-- > 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	free_map(char **map, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
