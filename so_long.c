/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xaviermonteiro <xaviermonteiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:37:25 by hguerrei          #+#    #+#             */
/*   Updated: 2025/01/17 13:03:35 by xaviermonte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_hooks(t_data *vars)
{
	mlx_hook(vars->mlx_win, 17, 0, close_window, vars);
	mlx_key_hook(vars->mlx_win, key_hook, vars);
}

int	main(int argc, char *argv[])
{
	t_data	vars;

	vars.game.map = NULL;
	if (argc == 2)
	{
		if (check_map_name(argv[1], &vars))
			read_map(argv[1], &vars);
	}
	else
		error_message(&vars);
	vars.mlx = mlx_init();
	create_window(&vars);
	store_sprites(&vars);
	draw_map(&vars);
	game_hooks(&vars);
	mlx_loop(vars.mlx);
	destroy_sprites(&vars);
	free(vars.mlx);
	return (0);
}
