/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xaviermonteiro <xaviermonteiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:38:32 by hguerrei          #+#    #+#             */
/*   Updated: 2025/01/17 13:05:37 by xaviermonte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_moves(t_data *vars)
{
	char	*move_str;

	if (vars->player.move_count < 0)
		error_message(vars);
	move_str = ft_itoa(vars->player.move_count);
	if (!move_str)
		return ;
	draw_map(vars);
	mlx_string_put(vars->mlx, vars->mlx_win, 10, 20, 0xFFFFFF, "Moves:");
	ft_printf("Moves: %d\n", vars->player.move_count);
	mlx_string_put(vars->mlx, vars->mlx_win, 100, 20, 0xFFFFFF, move_str);
	free(move_str);
}

void	move_player(t_data *vars, int x_offset, int y_offset)
{
	int	current_x;
	int	current_y;

	current_x = vars->player.p_x + x_offset;
	current_y = vars->player.p_y + y_offset;
	if (vars->game.map[current_y][current_x] != '1')
	{
		if (vars->game.map[current_y][current_x] == 'C')
			vars->player.total_c--;
		else if (vars->game.map[current_y][current_x] == 'E')
		{
			if (vars->player.total_c == 0)
				close_window(vars);
			return ;
		}
		vars->game.map[vars->player.p_y][vars->player.p_x] = '0';
		vars->game.map[current_y][current_x] = 'P';
		vars->player.p_x = current_x;
		vars->player.p_y = current_y;
		vars->player.move_count++;
		display_moves(vars);
	}
}

int	key_hook(int keycode, t_data *vars)
{
	if (keycode == KEY_ESC)
		close_window(vars);
	else if (keycode == LEFT_KEY)
		move_player(vars, -1, 0);
	else if (keycode == RIGHT_KEY)
		move_player(vars, 1, 0);
	else if (keycode == UP_KEY)
		move_player(vars, 0, -1);
	else if (keycode == DOWN_KEY)
		move_player(vars, 0, 1);
	return (0);
}

void	create_window(t_data *vars)
{
	mlx_get_screen_size(vars->mlx, &vars->window_height, &vars->window_width);
	if (vars->window_height < vars->game.map_height
		|| vars->window_width < vars->game.map_width)
		error_message(vars);
	vars->mlx_win = mlx_new_window(vars->mlx, vars->game.map_width,
			vars->game.map_height, "So_long");
	vars->img = mlx_new_image(vars->mlx, vars->game.map_width,
			vars->game.map_height);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
}

void	store_sprites(t_data *vars)
{
	vars->sprites.player = mlx_xpm_file_to_image(vars->mlx,
			"sprites/player.xpm", &vars->sprites.img_width,
			&vars->sprites.img_height);
	vars->sprites.collectables = mlx_xpm_file_to_image(vars->mlx,
			"sprites/collectable.xpm", &vars->sprites.img_width,
			&vars->sprites.img_height);
	vars->sprites.floor = mlx_xpm_file_to_image(vars->mlx,
			"sprites/floor.xpm", &vars->sprites.img_width,
			&vars->sprites.img_height);
	vars->sprites.escape = mlx_xpm_file_to_image(vars->mlx, "sprites/exit.xpm",
			&vars->sprites.img_width, &vars->sprites.img_height);
	vars->sprites.walls = mlx_xpm_file_to_image(vars->mlx, "sprites/wall.xpm",
			&vars->sprites.img_width, &vars->sprites.img_height);
}
