/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:00:14 by nboucher          #+#    #+#             */
/*   Updated: 2025/05/26 17:08:29 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "libft.h"
#include "mlx.h"
#include "struct.h"

void	free_all(t_data *data)
{
	if (data->i_game.img)
		mlx_destroy_image(data->mlx, data->i_game.img);
	if (data->textures[0].img)
		mlx_destroy_image(data->mlx, data->textures[0].img);
	if (data->textures[1].img)
		mlx_destroy_image(data->mlx, data->textures[1].img);
	if (data->textures[2].img)
		mlx_destroy_image(data->mlx, data->textures[2].img);
	if (data->textures[3].img)
		mlx_destroy_image(data->mlx, data->textures[3].img);
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->game.map)
		ft_free_tab(data->game.map);
}

int	exit_prog(t_data *data)
{
	ft_putstr_fd("Game exited with succed\n", 2);
	free_all(data);
	exit(EXIT_SUCCESS);
}

void	exit_failure(t_data *data)
{
	ft_putstr_fd("Error\nFatal Error\n", 2);
	free_all(data);
	exit(EXIT_FAILURE);
}
