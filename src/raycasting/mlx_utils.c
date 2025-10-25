/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:42:38 by nboucher          #+#    #+#             */
/*   Updated: 2025/05/25 18:42:38 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "struct.h"

void	put_pixel(t_img *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel
					/ 8));
		*(unsigned int *)dst = color;
	}
}

int	get_pixel(t_img *img, int x, int y)
{
	int		pixel;
	char	*dst;

	pixel = 0;
	if (x >= 0 && x < img->size.x && y >= 0 && y < img->size.y)
	{
		dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel
					/ 8));
		pixel = *(int *)dst;
	}
	return (pixel);
}
